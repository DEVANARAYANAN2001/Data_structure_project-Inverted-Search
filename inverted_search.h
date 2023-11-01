#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define DUPLICATE -2
#define DATA_FOUND -3
#define DATA_NOT_FOUND -4

typedef struct sub_node
{
    int wordcount;
    char fname[30];
    struct sub_node *sub_link;
}snode;

typedef struct main_node
{
    char word[30];
    int filecount;
    struct main_node *main_link;
    snode *main_sub_link;

}mnode;

typedef struct inverted
{
    struct inverted *link;
    char *filename;
}Search;

int insert_at_last(Search **head,char *filename);
int file_validation(int argc,Search **head,char *argv[]);
int create_table(Search **head,mnode *hashtable[]);
int insert_data(mnode **head,char *buff,char *filename);
int display_data_base(mnode *hashtable[]);
int search_data(mnode *hashtable[],char *data);
int save_data_base(mnode *hashtable[]);
int update_validation(Search **head,char *file,mnode *hashtable[]);
int update_data_base(FILE *fptr,mnode *hashtable[]);
void print_list(Search *head);

#endif
