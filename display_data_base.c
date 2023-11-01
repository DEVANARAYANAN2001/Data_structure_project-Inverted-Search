#include"inverted_search.h"

int display_data_base(mnode *hashtable[])
{
    printf("\n");
    printf("---------------------------------------- DISPLAY DATA BASE -----------------------------------------\n");
    printf("\n");
    printf("Index\tWord\tFilecount\tFilename\tWordcount\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    int flag = 1;
    for(int j=0;j<27;j++)                       
    {
	if(hashtable[j] != NULL )     
	{
	   flag = 0;
	}
    }
    if(flag ==1)
    {
	return FAILURE;   //the all index is null return failure
    }
    for(int i=0;i<27;i++)
    {
	mnode *temp=hashtable[i];
	while(temp != NULL)
	{
	    printf("%d\t%s\t%d\t",i,temp->word,temp->filecount);       //to printing the main node member of index and word and then fielcount
	    snode *sub_temp = temp->main_sub_link;
	    while(sub_temp != NULL)
	    {
		printf("\t%s\t%d\t",sub_temp->fname,sub_temp->wordcount); //to print the subnode member of filename and then wordcount
		sub_temp = sub_temp->sub_link;
	    }
	    printf("\n");
	    temp = temp->main_link;
	}
    }
    return SUCCESS;
}
