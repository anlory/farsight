#include "net.h"
void init_link(p_node *H)
{
	if( (*H = (p_node)malloc(sizeof(node))) < 0)
	{
		err("malloc");
	}

	(*H)->next = NULL;
}

bool isempty(p_node h)
{
	if(h->next == NULL)
		return true;
	else
		return false;
}

bool insert_link(p_node h,datatype fd)
{
	p_node new;
	
	if( (new = (p_node)malloc(sizeof(node))) < 0)
		return false;		

	new->fd = fd;
	new->next = h->next;
	h->next = new;
	return true;
}

bool del_link(p_node h,datatype fd)
{
	p_node p;
	
	while(h->next != NULL)
	{
		if(h->next->fd == fd)
		{
			p = h->next;
			h->next = p->next;
			free(p);
			return true;
		}
		h = h->next;
	}
	return false;
}
