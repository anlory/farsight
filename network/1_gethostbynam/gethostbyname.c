#include "net.h"


int main(int argc,char **argv)
{
	struct hostent * h_info;
	char *p;
	struct in_addr **px;
	if(argc != 2)
	{
		if( (h_info = gethostbyname("Ubuntu")) == NULL)
		{
			perror("gethostbyname");
			exit(1);
		}

	}else
	{
		if( (h_info = gethostbyname(argv[1])) == NULL)
		{
			perror("gethostbyname");
			exit(1);
		}
	}
	    //取主机信息
	printf("h_name = %s\n",h_info->h_name);
	p = *(h_info->h_aliases);
	printf("h_aliases:\n");
	while(p != NULL)
	{
		printf("%s\n",p);
		p++;
	}
	printf("h_addrtype = %d\n",h_info->h_addrtype);
	printf("h_length= %d\n",h_info->h_length);
	
	//主机对应的IP
	px = (struct in_addr**)(h_info->h_addr_list);
	printf("h_addr:\n");
	while(*px != NULL)
	{
		printf("%s\n",inet_ntoa(**px));
		px++;
	}

	return 0;
}
