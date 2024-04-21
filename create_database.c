#include "invert.h"

/*
Name          :	AADITHYA SATHEESH
Date          :	10-04-2024
Description   :	Inverted search
sample input  :
sample output :
 */

/* Function used to create the whole database */
void create_database(flist *f_head,mlist *head[])
{
	// traversing through the single linked list containing the files
	while(f_head)
	{
		read_data(f_head,head,f_head->file_name);
		f_head=f_head->link;
	}
}
mlist * read_data(flist *f_head,mlist *head[],char *filename)
{
	int flag=0;
	char wordi[100];
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Error in opening file\n");
	}
	while(fscanf(fp,"%s",wordi) != -1)
	{
		int index=tolower(wordi[0])%97;
		if(head[index]==NULL)
		{
			mlist *new=malloc(sizeof(mlist));
			slist *news=malloc(sizeof(slist));

			if(new==NULL)
			{
				printf("No node created\n");
			}
			// update main node values
			new->file_count =1 ;
			strcpy(new -> word,wordi);
			new -> mainlink = NULL;
			new->sublink =NULL;

			// update subnode values
			news-> wordcount =1;
			strcpy(news->file_name,filename);
			news->slink =NULL;
			new->sublink=news;
			//printf("succeffully for only data\n");
			head[index]=new;
		}
		else
		{
			mlist *temp=head[index];
			mlist *prev1=NULL;
			int flag2=0;
			while(temp!=NULL)
			{
				if(strcmp(temp->word,wordi)==0)
				{
					slist *temp1=temp->sublink;
					slist  *prev=NULL;
					int flag1=0;					
					while(temp1!=NULL)
					{ 
						// when same word is present again in the same filr we increment the word count
						if(strcmp(temp1->file_name,filename)==0)
						{
							flag1=flag2=1;
							(temp1->wordcount++);
						}
						prev = temp1;
						temp1=temp1->slink;
					}
					// when same word is present in another file we make another subnode for it
					if (flag1==0)
					{	
						flag2=1;
						slist *new=malloc(sizeof(slist));
						strcpy(new->file_name,filename);
						new->wordcount=1;
						new->slink=NULL;
						prev->slink=new;
						(temp->file_count++);
					}
				}
				prev1=temp;
				temp=temp->mainlink;
			}
			// if no words are matching in the main nodes we create another main node with a subnode for that new word
			if(flag2==0)
			{
				mlist *new=malloc(sizeof(mlist));
				slist *news=malloc(sizeof(slist));
				if(new==NULL)
				{
					printf("no node created\n");
				}
				//update main node values
				new->file_count =1 ;
				strcpy(new -> word,wordi);
				new -> mainlink = NULL;
				new->sublink =NULL;

				//update subnode values
				news-> wordcount =1;
				strcpy(news->file_name,filename);
				news->slink =NULL;
				new->sublink=news;
				prev1->mainlink=new;
				//printf("database created succeffully for extra data\n");
			}
		}
	}
	printf("Successful:creation of database for file:%s\n",filename);
}








