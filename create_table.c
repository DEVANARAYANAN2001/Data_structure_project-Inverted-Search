#include"inverted_search.h"

int create_table(Search **head,mnode *hashtable[] )
{
    Search *temp = *head;                               //create temp pointer and then store the head 
    while (temp != NULL)                             
    {
	FILE *fptr = fopen(temp->filename,"r");          //open to the file read mode 
	if(fptr == NULL)                                //file is not open print error message
	{
	    printf("----------------------------- ERROR : FILE NOT OPENED ------------------------------\n");
	}
	char buff[100];
	while(fscanf(fptr,"%s",buff) != EOF)           //to read the words from the file help of fscanf
	{
	    int index = tolower(buff[0]) % 97 ;                                  //to find the index value
	    if( (index >=33 && index<=47) || (index>=58 && index <= 63))
	    {
		index = 26;                                                    //the word is special char then store 26th index 
	    }
	    if (hashtable[index] == NULL )                   //to check the hashtable is null or not
	    {
		mnode *main_new = malloc(sizeof(mnode));         //creating main node
		if(main_new == NULL)
		{
		    return FAILURE;
		}
		else
		{
		    hashtable[index] = main_new;           //update the main node members
		    strcpy (main_new->word,buff);
		    main_new->filecount = 1;
		    main_new->main_sub_link = NULL;
		    main_new->main_link = NULL;   
		}
		snode *sub_new = malloc(sizeof(snode));         //creating sub node
		if(sub_new == NULL)
		{
		    return FAILURE;
		}
		else
		{
		    main_new->main_sub_link = sub_new;             //to update the subnode members
		    sub_new->wordcount = 1;
		    strcpy(sub_new->fname,temp->filename);
		    sub_new->sub_link = NULL;
		}
	    }

	    else if(hashtable[index] != NULL )
	    {
		insert_data(&hashtable[index],buff,temp->filename);     //hashtable index is not null then function call for insert data
	    }
	}
	temp = temp->link;
    }
}
int insert_data(mnode **head,char *buff,char *filename)
{
    mnode *main_node_temp = *head; 
    mnode *prev_main_node_temp = NULL;
    snode *sub_node_temp = NULL;
    snode *prev_sub_node_temp = NULL;
    while(main_node_temp != NULL)
    {
	prev_main_node_temp = main_node_temp;
	if(strcmp(main_node_temp->word,buff) == 0)                   //to check the word are alread precent the node 
	{
	    sub_node_temp = main_node_temp->main_sub_link;

	    while(sub_node_temp != NULL)
	    {
		prev_sub_node_temp = sub_node_temp;

		if(strcmp(sub_node_temp->fname,filename)== 0)               //the word is already precent the node then check the file are same or not
		{
		    (sub_node_temp->wordcount)++;             //the file is same then increase the word count
		    return SUCCESS;
		}
		//	    else
		//	    {
		sub_node_temp = sub_node_temp->sub_link;
		//	    }
	    }
	    (main_node_temp->filecount)++;                         //the file is not same the increase the file count
	    snode *sub_new = malloc(sizeof(snode));                    //creating the subnode
	    if(sub_new == NULL)
	    {
		return FAILURE;
	    }
	    else
	    {
		prev_sub_node_temp->sub_link = sub_new;     //update the subnode parameters
		sub_new->wordcount = 1;
		strcpy(sub_new->fname,filename);
		sub_new->sub_link = NULL;
	    }
	    return SUCCESS;
	}
	//	    else
	//	    {
	main_node_temp = main_node_temp->main_link;
	//	    }
    }
    mnode *main_new = malloc(sizeof(mnode));      //the word is not precent the node then create new node
    if(main_new == NULL)
    {
	return FAILURE;
    }
    else
    {
	prev_main_node_temp->main_link = main_new;       //update the main node members
	strcpy (main_new->word,buff);
	main_new->filecount = 1;
	main_new->main_sub_link = NULL;
	main_new->main_link = NULL;
    }
    snode *sub_new = malloc(sizeof(snode));         //to create the subnode
    if(sub_new == NULL)
    {
	return FAILURE;
    }
    else
    {
	main_new->main_sub_link = sub_new;   //update the subnode members
	sub_new->wordcount = 1;
	strcpy(sub_new->fname,filename);
	sub_new->sub_link = NULL;
    }

    return SUCCESS;
}
