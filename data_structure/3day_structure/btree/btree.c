#include "btree.h"
#include "linkstack.h"
#include "linkqueue.h"

int main(void)
{
      btree_pnode t;

      t = create_btree();

      travel("先序遍历",pro_order,t);
      travel("先序遍历非递归",pro_order_2,t);
      travel("中序遍历",mid_order,t);
      travel("后序遍历",post_order,t);
      travel("按层遍历",level_order,t);
      
      return 0;
}

btree_pnode create_btree(void)
{
      datatype_bt ch;
      btree_pnode new;
      scanf("%c",&ch);
      if(ch == '#')
	    new = NULL;
      else{
	    //创建根结点
	    new = (btree_pnode)malloc(sizeof(btree_node));
	    if(new == NULL){
		  perror("malloc");
		  exit(1);
	    }
	    new->data = ch;
	    //先序创建左子树
	    new->lchild = create_btree();
	    //先序创建右子树
	    new->rchild = create_btree();
      }
      return new;
}

void pro_order(btree_pnode t)
{
      if(t != NULL){
	    printf("%c",t->data);//访问根结点
	    //先序遍历左子树
	    pro_order(t->lchild);
	    //先序遍历右子树
	    pro_order(t->rchild);

      }
}

void pro_order_2(btree_pnode t)
{
      link_pstack top;
      top = init_linkstack(); //初始化栈

      while(t != NULL || !empty_linkstack(top)){
	    if(t != NULL){
		  printf("%c",t->data);
		  if(t->rchild != NULL)
			push_linkstack(t->rchild,&top);
		  t = t->lchild;
	    }else{
		  if(empty_linkstack(top))
			break;
		  else{
			pop_linkstack(&t,&top);
		  }
	    }
      }    
}
void mid_order(btree_pnode t)
{
      if(t != NULL){
	    //先序遍历左子树
	    mid_order(t->lchild);
	    printf("%c",t->data);//访问根结点
	    //先序遍历右子树
	    mid_order(t->rchild);

      }
}
void post_order(btree_pnode t)
{
      if(t != NULL){
	    //先序遍历左子树
	    post_order(t->lchild);
	    //先序遍历右子树
	    post_order(t->rchild);
	    printf("%c",t->data);//访问根结点

      }
}
void level_order(btree_pnode t)
{
      link_pqueue q;
      init_linkqueue(&q); //初始化队列

      while(t != NULL){
	    printf("%c",t->data);
	    if(t->lchild != NULL)
		  in_linkqueue(t->lchild,q);
	    if(t->rchild != NULL)
		  in_linkqueue(t->rchild,q);
	    if(empty_linkqueue(q))
		  break;
	    else
		  out_linkqueue(&t,q);
      }
}

void travel(const char *str,void (*fun)(btree_pnode),btree_pnode t)
{
      printf("%s: ",str);
      fun(t);
      printf("\n");
}
