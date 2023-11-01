#include"inverted_search.h"

int insert_at_last(Search **head,char *argv)
{
    if(*head == NULL)
    {
	Search *new =  malloc(sizeof(Search));
	new->filename = argv;
	*head = new; 
	return SUCCESS;
    }
    Search *temp = *head;
    Search *prev;
    while(temp)
    {
	if(strcmp(temp->filename, argv) == 0)
	{
	    return FAILURE;
	}
	prev = temp ;
	temp=temp->link;
    }
    Search *new =  malloc(sizeof(Search));
    new->filename = argv;
    prev->link = new;
    return SUCCESS;





}

