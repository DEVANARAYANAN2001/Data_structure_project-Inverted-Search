#include"inverted_search.h"
int search_data(mnode *hashtable[],char *data)
{	    
    int index = tolower(data[0]) % 97 ;
    if( (index >=33 && index<=47) || (index>=58 && index <= 63))
    {
	index = 26;
    }
    if (hashtable[index] == NULL )
    {
	return DATA_NOT_FOUND;              //the hashtable index is null then return data not found
    }
    mnode *temp = hashtable[index];
    while(temp != NULL)
    {
	if(strcmp(temp->word,data) == 0)
	{
	    printf("\n");
	    printf("----------------------------------- DISPLAY SEARCHIG DATA -------------------------------------\n");
	    printf("\n");
	    printf("Index\tWord\tFilecount\tFilename\tWordcount\n");
	    printf("%d\t%s\t%d\t",index,temp->word,temp->filecount); //to print the index and then word and then filecount
	    snode *sub_temp = temp->main_sub_link;
	    while(sub_temp != NULL)
	    {
		printf("\t%s\t%d\t",sub_temp->fname,sub_temp->wordcount); //to print the filename and then wordcount
		sub_temp = sub_temp->sub_link;
	    }
	    printf("\n");
	    return DATA_FOUND;
	}
	temp = temp->main_link;
    }
    return DATA_NOT_FOUND;
}
