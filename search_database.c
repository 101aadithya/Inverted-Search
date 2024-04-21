#include "invert.h"
/*
Name          : AADITHYA SATHEESH KUMAR
Date          :	11-04-2024
Description   :	inverted search
sample input  :
sample output :
 */

/* Function to search for the word */
void search_database(mlist *head[])
{

	char wordl[100];
	printf("Enter the word to search:\n");
	scanf("%s",wordl);
	printf("%s",wordl);
	printf("\n");
	if(head == NULL)
	{
		printf("Search word is not available in the list as list is empty\n");
		return;
	}
	for(int i=0;i<27;i++)
	{
	mlist *temp=head[i];
	while(temp != NULL)
	{
		//Compare the search word with available words	
		if(strcmp(temp->word, wordl)==0)
		{
			printf("Word %s is present in %d file\n " , temp->word , temp->file_count);

			slist *Thead = temp->sublink;
			// accesing the sub link
			while(Thead)
			{
				printf("In File : %s\t%d times\n", Thead->file_name , Thead->wordcount);
				Thead = Thead->slink;
			}
			return;
		}
		temp = temp->mainlink;
	}
	}
	printf("Error: Search word is not found in list\n");
}

