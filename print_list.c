#include "inverted_search.h"

void print_list(Search *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	printf(" head-> ");
	    while (head)		
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}
