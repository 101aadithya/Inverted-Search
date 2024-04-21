#include "invert.h"
/*
Name          :	AADITHYA SATHEESH KUMAR
Date          :	11-04-2024
Description   :	Inverted search
sample input  :
sample output :
 */


void update_database(mlist *hashtable[],char *file1)
{
	printf("INFO: Updating Database ... \n");
	FILE *file=fopen(file1,"r");
	int index, filecount, wordcount;
	char *word;
	char *filename;
	char *delims="#;";
	char oneline[50];

	while(fscanf(file, "%s", oneline) != EOF)
	{
		index=atoi(strtok(oneline,delims));
		word=strtok (NULL,delims);
		filecount=atoi(strtok(NULL, delims));
		mlist *memp=malloc(sizeof(mlist));
		strcpy(memp->word,word);
		memp->file_count=filecount;
		memp->mainlink=NULL;
		memp->sublink=NULL;
		for(int i=1;i<=filecount;i++)
		{
		    filename=strtok(NULL,delims);
			wordcount=atoi(strtok(NULL,delims));
			slist* semp=malloc(sizeof(slist)); 
			strcpy(semp->file_name,filename);
			semp->wordcount=wordcount;
			semp->slink=NULL;
			
			if(memp->sublink == NULL)
			{
				memp->sublink=semp;
			}
			else
			{
				slist* st=memp->sublink;
				while(st->slink!=NULL)
				{
					st=st->slink;
				}
				st->slink=semp;
			}
		}
		if(hashtable[index]==NULL)
		{
			hashtable[index]=memp;
		}
		else
		{
			mlist *tm=hashtable[index];
				while(tm->mainlink != NULL)
				{
					tm=tm->mainlink;
				}
			tm->mainlink=memp;
		}
	}
	printf("Successful creation of database for file:%s\n",file1);
	return;
}
