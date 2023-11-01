#include"inverted_search.h"
int file_validation(int argc,Search **head,char *argv[])
{
    if(argc > 1 )
    {
	for(int i = 1;i<argc;i++)
	{
	    if(argv[i] != NULL && strstr(argv[i],".txt") != NULL)
	    {
		FILE* fptr = fopen(argv[i],"r");
		if(fptr != NULL)
		{
		    fseek(fptr,0,SEEK_END);
		    if(ftell(fptr) > 0)
		    {
			if(insert_at_last(head,argv[i]) == SUCCESS)
			{
			    printf(" -------------------- SUCCESS : %s INSERT FILE NAME SUCCESS --------------------\n",argv[i]);
			}
			else
			{
			    printf("ERROR : DUPLICATE FILE\n");
			}
		    }
		    else
		    {
			printf("ERROR : FILE EMPTY\n");
		    }
		}
		else
		{
		    printf("ERROR : FILE NOT PRECENT YOUR DIRECTORY\n");
		}
	    }
	    else
	    {
		printf("ERROR : FILE IS NOT .txt\n");
	    }
	}
    }
    else
    {
	printf("ERROR : PLEASE ENTER THE CLA\n");
    }

}

