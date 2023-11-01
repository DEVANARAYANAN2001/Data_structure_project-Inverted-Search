#include"inverted_search.h"

int update_validation(Search **head,char *file,mnode *hashtable[])
{
    FILE *fptr = fopen(file,"r");                            //to oepn the backup file to read mode 
    if(fptr == NULL) 
    {
	printf("------------------------------- Unable to open the %s file ------------------------------",file);
	return FAILURE;
    }
    else
    {
	Search *temp = *head;
	while(temp != NULL)
	{
	    if(strcmp(temp->filename,file)==0)       //to check the file is precent the linked list if precent then print the error message
	    {
		printf("----------------------------- This file %s present in linked list -----------------------------\n",file);
		return FAILURE;
	    }
	    temp=temp->link;
	}
	fseek(fptr,0,SEEK_END);
	//	printf("%d\n",ftell(fptr));
	if(!(ftell(fptr)))                       //inside file content not precent then print the error message
	{
	    printf("------------------------------ ERROR %s file is empty so can not update database ------------------------------\n",file);
	}
	else
	{
	    if(strcmp((strstr(file,".")),".txt"))            //to check the file are .txt or not
	    {
		printf("------------------------------ ERROR %s please pass .txt file -----------------------------\n",file);
		return FAILURE;
	    }
	    else
	    {
		rewind(fptr);                                         //to set the cursur to first
		if(update_data_base(fptr,hashtable) == SUCCESS)       //function call for update data base
		{
		    return SUCCESS;
		}
		else
		{
		    return FAILURE;
		}
	    }  
	}
    }
}

int update_data_base(FILE *fptr,mnode *hashtable[])
{
    char arr[100];
    int index=0;
    char word[50];
    int filecount =0;
    char file_name[50];
    int wordcount=0;					
    while(fscanf(fptr,"%s",arr) != EOF)
    {
	if(arr[0] == '#')			
	{
	    index=atoi(strtok(arr,";#"));                    //to getting the index help of strtok function
	    strcpy(word,(strtok(NULL,";#")));            //to get the word
	    filecount=atoi(strtok(NULL,";#"));		  //to getting the file count
	    int i= filecount;
	    if(hashtable[index]== NULL )
	    {
		mnode *main_node =malloc(sizeof(mnode));	 //the hashtable index is null then create the main nide
		if(main_node == NULL)
		    return FAILURE;
		else
		{
		    main_node->filecount = filecount;	 //updat the main node members
		    strcpy(main_node->word,word);
		    main_node->main_link=NULL;
		    main_node->main_sub_link=NULL;
		    strcpy(file_name,(strtok(NULL,";#")));
		    wordcount = atoi(strtok(NULL,";#"));
		    snode *sub_node=malloc(sizeof(snode));       //to creating the subnode
		    if(sub_node == NULL)
			return FAILURE;
		    else
		    {
			strcpy( sub_node->fname, file_name);   //update the subnode members
			sub_node->wordcount = wordcount;
			sub_node->sub_link=NULL;
			main_node->main_sub_link= sub_node;
		    }
		    snode *sub_node_temp=sub_node;
		    while(--i)				
		    {
			snode *sub_node=malloc(sizeof(snode));
			if(sub_node == NULL)
			    return FAILURE;
			else
			{

			    strcpy(file_name,(strtok(NULL,";#")));
			    wordcount = atoi(strtok(NULL,";#"));
			    strcpy( sub_node->fname, file_name);
			    sub_node->wordcount = wordcount;
			    sub_node->sub_link=NULL;
			    sub_node_temp->sub_link= sub_node;
			    sub_node_temp=sub_node;

			}

		    }
		}
		hashtable[index]=main_node;				
	    }
	    else
	    {
		mnode *main_node_temp=hashtable[index];   //hashtable index is not null then creat the temp main and subnode for traversing
		mnode *prev_main_node_temp=NULL;		
		while(main_node_temp != NULL)				
		{
		    prev_main_node_temp=main_node_temp;	               //update the tempp node 
		    main_node_temp=main_node_temp->main_link;
		}
		mnode *main_node =malloc(sizeof(mnode));       //to creat the main nide
		if(main_node == NULL)
		    return FAILURE;			
		else
		{
		    main_node->filecount = filecount;         //update the main node members
		    strcpy(main_node->word,word);
		    main_node->main_link=NULL;			
		    main_node->main_sub_link=NULL;
		    strcpy(file_name,(strtok(NULL,";#")));
		    wordcount = atoi(strtok(NULL,";#"));
		    snode *sub_node=malloc(sizeof(snode));         //create the subnode 
		    if(sub_node == NULL)
			return FAILURE;
		    else
		    {
			strcpy( sub_node->fname, file_name);      //update the subnode members
			sub_node->wordcount = wordcount;
			sub_node->sub_link=NULL;
			main_node->main_sub_link= sub_node;
		    }
		    snode *sub_temp=sub_node;                        
		    while(--i)
		    {
			snode *sub_node=malloc(sizeof(snode));         //to creating the sub node 
			if(sub_node == NULL)
			    return FAILURE;
			else
			{
			    strcpy(file_name,(strtok(NULL,";#"))); //update the subnode parameters
			    wordcount = atoi(strtok(NULL,";#"));
			    strcpy( sub_node->fname, file_name);
			    sub_node->wordcount = wordcount;
			    sub_node->sub_link=NULL;
			    sub_temp->sub_link= sub_node;
			    sub_temp=sub_node;

			}

		    }
		}
		prev_main_node_temp->main_link=main_node;		
	    }
	}
	else						
	{
	    printf("----------------------------- Invalid file format ------------------------------\n");
	    return FAILURE;
	}

    }
    return SUCCESS;
}

