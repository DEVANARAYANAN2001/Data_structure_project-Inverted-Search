#include"inverted_search.h"

int save_data_base(mnode *hashtable[])
{
    FILE *fptr =  fopen("backup.txt","w");           //to craet the backup file for store the data base
    if(fptr == NULL)                                   //the file is not open then print error message
    {
	printf("------------------------- Error fopen -------------------------\n");
	return FAILURE;
    }
    else
    {
	int i;
	mnode *temp;
	snode *sub_temp;
	for(i=0;i<27;i++)
	{
	    for(temp = hashtable[i];temp != NULL;temp = temp ->main_link)
	    {
		fprintf(fptr, "#%d;%s;%d;",i,temp->word,temp->filecount);                              //to store the index and word and then filecount
		for(sub_temp = temp->main_sub_link;sub_temp != NULL;sub_temp = sub_temp->sub_link)
		{
		    fprintf(fptr, "%s;%d;",sub_temp->fname,sub_temp->wordcount);      //to store the fielname and then wordcount
		}
		fprintf(fptr,"#");
		fprintf(fptr,"\n");
	    }
	}
	fprintf(fptr,"\n");
    }
    return SUCCESS;
}
