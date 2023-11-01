#include"inverted_search.h"
/*
Name: R DEVANARAYANAN 
Date: 22 sep 2023
Title: INVERTED SEARCH
*/

int main (int argc,char *argv[])
{
    int var;
    char option;
    Search *head = NULL;
    mnode * hashtable[27] = {NULL};          //hashtable creating
    file_validation(argc,&head,argv);        //the file validation function calling
    print_list(head);                        //to print the list of files
    do
    {
	printf("1.create data_bash\n2.Dispaly\n3.search\n4.save\n5.update\n6.exit\n");
	printf("Enter the choise : ");
	scanf("%d",&var);                      //to read the option from user
	switch(var)
	{
	    case 1 : 
		if(create_table(&head,hashtable)==SUCCESS)            //create table function calling
		{
		    printf("\n");
		    printf("-------------------------------- CREATE DATA_BASE SUCCESS --------------------------------\n");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("-------------------------------- CREATE DATA_BASE FAILURE ---------------------------------\n");
		    printf("\n");
		}
		break;
	    case 2 :
		if(display_data_base(hashtable) == SUCCESS)                   //to dispaly function calling
		{
		    printf("\n");
		    printf("------------------------------------- DISPLAY DATA BASE SUCCESS -----------------------------------\n");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("------------------------------------- DISPLAY DATA BASE EMPTY -----------------------------------\n");
		    printf("\n");
		}
		break;
	    case 3 : 
		char data[20];
		printf("Enter the data : ");
		scanf(" %s",data);                                  //read the searching data from the user
		if(search_data(hashtable,data) == DATA_FOUND)       //to searching data function calling
		{
		    printf("\n");
		    printf("----------------------------------------- DATA FOUNDED -----------------------------------------\n");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("-------------------------------------- DATA NOT FOUNDED --------------------------------------\n");
		    printf("\n");
		}
		break;
	    case 4 :
		if(save_data_base(hashtable)== SUCCESS)     //save data base function calling
		{
		    printf("\n");
		    printf("-------------------------------- SAVE DATA BASE SUCCESS --------------------------------------\n");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("-------------------------------- SAVE DATA BASE FAILURE --------------------------------------\n");
		    printf("\n");
		}
		break;
	    case 5:
		char file[30];
		printf("Entert the file for update : ");
		scanf("%s",file);                                       //to read the backup file name from the user
		if(update_validation(&head,file,hashtable)==SUCCESS)    //update data base function calling
		{
		    printf("\n");
		    printf("------------------------------------- UPDATE DATA BASE SUCCESS --------------------------------------\n");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("------------------------------------ UPDATE DATA BASE FAILURE -------------------------------------\n");
		    printf("\n");
		}
		break;
	    default :
		printf("\n");
		printf("----------------------------------- Please enter the correct choise 1 to 5 -----------------------------------\n");
		printf("\n");
		break;
	}
	printf("------------------------------------------------------------------------  Do you want continue (y/n) : ");
	scanf(" %c",&option);
    }while('y' == option || 'Y'== option);
}
