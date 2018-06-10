#include "doublelink.h"


int main(void)
{
	int n;
	double_plist h;

	h = init_doublelist();
	printf("请输入双向链表长度:");
	scanf("%d",&n);

	create_doublelist(n,h);

	sort_doublelist(h);
	printf("排序之后的结果位:\n");
	show_doublelist(h);
	return 0;
}

