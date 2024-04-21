#include "invert.h"
/*
Name          : AADITHYA SATHEESH KUMAR
Date          :	10-04-2024
Description   :	Inverted search
sample input  :
sample output :
 */
int main(int argc ,char *argv[])
{
	// Check if the user has entered sufficient number of cla
	flist *f_head =NULL;
	if(argc>1)
	{

		file_validation(&f_head,argv);
		print(f_head);

	}
	else
	{
		printf("Error: Please pass the files through command line arguments\n");
		return 0;
	}
	if(f_head==NULL)
	{
		printf("No files are available in linked list \n");
		return 1;
	}

	/* create an array of pointers of 27 and fill them with NULL*/
	mlist *head[27];
	for(int i=0;i<28;i++)
	{
		head[i]=NULL;
	}
	char ch;

	/* provide menu for the user to chose from */
	do
	{
		printf("Select your choice among the following options\n");
		printf("1.Create database\n2.Display database\n3.Search database\n4.Save database\n5.Update database\n6.Exit\n");
		int opt=0;
		char file[ind];
		printf("Enter the Choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				create_database(f_head,head);
				break;
			case 2:
				display_database(head);
				break;
			case 3:
				search_database(head);
				break;
			case 4:
				save_database(head);
				break;
			case 5:
				printf("Enter the file name to update\n");
				scanf("%s",file);
				update_database(head,file);
				break;
			case 6:
				printf("Program terminated successfully\n");
				exit(0);
			default:
				printf("Invalid option\n");

		}
		printf("Do you want to continue?\n");
		printf("Enter y/Y to continue and n/N to discontinue\n");
		getchar();
		scanf("%s",&ch);
	}while(ch =='y' || ch=='Y');
}
void print(flist *head){
	flist *t=head;
	while(t != NULL)
	{
//		printf("%s -> ", t->file_name);
		t=t->link;
	}
//	printf("NULL\n");
}

