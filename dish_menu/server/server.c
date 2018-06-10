#include "menu.h"
/* 菜单服务器*/


sqlite3 *db;
/*json 订单插入到bill数据表中,返回桌号*/
int  get_json_sqlite(char *out,char *addr )
{
	time_t seconds;
	seconds = time(NULL);
	
	cJSON  *table = cJSON_Parse(out);
	cJSON *table_num = cJSON_GetObjectItem(table,"Table");
	int number = table_num->valueint;
	printf(LIGHT_GREEN"%d号桌发来订单!\n"NONE,number);
	
	//订单添加到数据表bill中
	sqlite3 *db;
	db = NULL; 
	sqlite3_open("menu.db",&db);
	char *errMsg;
	
	sqlite3_exec(db,"create table bill(Time text, Bil text);",0,0,&errMsg);
	sqlite3_stmt *stmt;
	char * zTail;
	
	sqlite3_prepare(db,"insert into bill values(?,?);",-1,&stmt,&zTail);
	sqlite3_bind_text (stmt,1,ctime(&seconds),strlen(ctime(&seconds)),SQLITE_STATIC);
	sqlite3_bind_text (stmt,2,out,strlen(out),SQLITE_STATIC);
	sqlite3_step(stmt);
	sqlite3_reset(stmt);

	return number;
}




/*将数据库中数据转化为json*/
void change_sqlite_json( char ** out)
{

	//创建sqlite3数据库
	db =NULL;
	char *errMsg = NULL;
	int nrow, ncolumn;
	char **azResult;

	nrow = ncolumn =0;
	//打开数据库menu
	sqlite3_open("menu.db",&db);
	if(sqlite3_get_table(db,"select * from food;",&azResult,&nrow,\
				&ncolumn,&errMsg)!=0){
		perror("sqlite3_get_table");
		exit(1);
	}

	cJSON *food;
	food = cJSON_CreateArray();
	char * a[100][4];
	int i,j;
	for(i = 0;i <nrow+1; i++){
		for(j=0 ; j< ncolumn ; j++){
			a[i][j]=azResult[i*ncolumn+j];
		}

	}
	for(i=0;i<nrow+1;i++){
		cJSON_AddItemToArray(food,cJSON_CreateStringArray(a[i],ncolumn));
	}	
	*out = cJSON_Print(food);
}


/*打印订单*/
void show_menu(void)
{
	system("clear");
	int nrow,ncolumn;
	char **azResult;char *errMsg;
	sqlite3_open("menu.db",&db);
	int rc = sqlite3_get_table(db,"select * from food;",&azResult,&nrow,\
			&ncolumn,&errMsg);
	if( rc != 0){
		printf("%s\n",errMsg);
	}
	int i;
	for ( i = 0;i < nrow+1  ; i++){
			printf("%-18s%-18s%-18s%-18s\n",
			azResult[i*ncolumn],azResult[i*ncolumn+1],azResult[i*ncolumn+2], azResult[i*ncolumn+3]);
	}
	sleep(3);
}


/*添加*/
void add_menu( void)
{
	
	printf(CYAN"请输入添加菜的信息(ID,Name,Price,)\n"NONE);
	int id;
	char name[30];
	int price;
	scanf("%d",&id);
	scanf("%s",name);
	scanf("%d",&price);
	sqlite3_open("menu.db",&db);
	sqlite3_stmt * stmt;
	sqlite3_prepare(db,"insert into food values(?,?,?,?);",-1,\
			&stmt,NULL);
	sqlite3_bind_int(stmt,1,id);
	sqlite3_bind_text(stmt,2,name,strlen(name),SQLITE_STATIC);
	sqlite3_bind_int(stmt,3,price);	
	sqlite3_bind_int(stmt,4,0);
	sqlite3_step(stmt);
	sqlite3_reset(stmt);
}

/*删除*/
void del_menu( void)
{
	printf(CYAN"请输删除的 ID:"NONE);
	int input;
	scanf("%d",&input);
	sqlite3_open("menu.db",&db);
	char sql[256];
	char * errMsg;
	sprintf(sql,"delete from food where ID = %d;",input);
	sqlite3_exec(db,sql,0,0,&errMsg);

}


/*修改*/
void update_menu( void)
{
	printf(CYAN"请输入修改后菜的信息(ID,OldPrice,NewPrice)\n"NONE);
	int id ,oldprice,newprice;
	scanf("%d %d %d",&id,&oldprice,&newprice );
	sqlite3_open("menu.db",&db);
	char sql[256];
	char * errMsg;
	
	sprintf(sql,"update food set Price= %d where ID = %d\
			and Price= %d;",newprice,id,oldprice);
	sqlite3_exec(db,sql,0,0,&errMsg);

}




/*管理菜单*/
void ctl_menu(void)
{
	while(1){
	printf(BLUE"****************************\n"NONE);
	printf("      1: 添加    2: 删除    \n");
	printf("      3: 修改    4: 退出    \n");
	printf(BLUE"****************************\n"NONE);
	int input;
	int flag = 0;
	scanf("%d",&input);
	switch(input){
		case 1 :  add_menu(); break;
		case 2 :  del_menu(); break;
		case 3 :  update_menu(); break;
		case 4 :  flag = 1; break;
		default:  printf("请正确输入\n");
	}
	if ( flag == 1) break;
	}
}

/*打印订单*/
void show_bill(void)
{
	int i,j,k;
	int m,n;
	int nrow,ncolumn;
	char** azResult,*errMsg;
	sqlite3_open("menu.db",&db);
	sqlite3_get_table(db,"select * from bill;",&azResult, &nrow,&ncolumn,\
			&errMsg);
	for(i = 1;i< nrow+1;i++)
	{
			printf(LIGHT_RED"%s"NONE,azResult[i*ncolumn]);
			cJSON *table = cJSON_Parse(azResult[i*ncolumn+1]);
			cJSON  *bill = cJSON_GetObjectItem(table,"format");
			cJSON *table_num = cJSON_GetObjectItem(table,"Table");
			printf(LIGHT_RED"%d号桌:\n"NONE,table_num->valueint);
			m = cJSON_GetArraySize(bill);
			n = cJSON_GetArraySize( cJSON_GetArrayItem (bill,0));
			for( j = 0;j<m;j++){
				cJSON * root=cJSON_GetArrayItem( bill ,j);
				for( k = 0; k < n;k++){
					cJSON *c=cJSON_GetArrayItem( root,k);
					printf("%-10s    ",c->valuestring);
				}
				printf("\n");
			}
				printf("\n");
	}

}



/*显示总营业额*/
void show_total(void)
{
	sqlite3 *db;
	db = NULL ;
	int nrow,ncolumn;
	int i;
	char **azResult;
	int sum;
	sum = 0;
	sqlite3_open("menu.db",&db);
	sqlite3_get_table(db,"select * from total",&azResult,&nrow,&ncolumn,NULL);
	for( i = 1; i < nrow+1 ;i++)
	{
		sum += atoi(azResult[i]);
	}
	printf(RED"截至现在营业额total:%d\n"NONE,sum);
}


/*总帐插入到total数据表*/
void total_into(int sum)
{
	sqlite3 *db;
	db =NULL;
	sqlite3_open("menu.db",&db);

	sqlite3_exec(db,"create table total(sum integer):",0,0,NULL);
	char sql[256] ;
	sprintf( sql," insert into total values(%d)",sum);
	sqlite3_exec( db,sql,0,0,NULL);

}

