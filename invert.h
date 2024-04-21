#ifndef INVERT_H
#define INVERT_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4
#define ind 100

/* Node structure for the  file linked list */
typedef struct file_node
{
	char *file_name;
	struct file_node *link;
}flist;


/* Node structure for the subnode which links to the main node */
typedef struct sub_table
{
	int wordcount;
	char file_name[ind];
	struct sub_table *slink;
}slist;


/* Node structure for the main node */
typedef struct main_table
{
	char word[ind];
	int file_count;
	struct main_table *mainlink;
	slist *sublink;
}mlist;


/* Function to check if the file is empty or not */
int isFileEmpty(char* filename);

/* Function to print the list */
void print(flist *);

/* Function to do all the validations */
void file_validation(flist **head,char *argv[]);

/* Function to create the list of files */
int to_create_list_of_files(flist **head,char* filename);

/* Function to create database */
void create_database(flist *f_head,mlist *head[]);

/* Function to read the data */
mlist * read_data(flist *fhead,mlist *head[],char *);

/* Function to update the sublist */
void update_database(mlist *hashtable[],char*);

/* Function to display the database */
void display_database(mlist *head[]);

/* Function to search word from the database */
void search_database(mlist *head[]);

/* Function to save the database */
void save_database(mlist *head[]);

/* Function to update database */
void update_database(mlist *head[],char*);

#endif 
	

