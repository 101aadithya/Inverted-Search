#include "invert.h"
/*
Name          : AADITHYA SATHEESH KUMAR
Date          :	11-04-2024
Description   :	Inverted search
sample input  :
sample output :
 */

/* Function to save the database */
void save_database(mlist *head[])
{
	char file_name[100];
	printf("Enter the filename you want save in database\n");
	scanf("%s",file_name);

	if(strcmp(strstr(file_name,"."),".txt")==0)
	{

		FILE *fptr = fopen(file_name , "w");

		if (fptr == NULL)
		{
			printf("Error: File not available\n");
			return;
		}
		for (int index = 0; index < 27; index++)
		{
			mlist* temp = head[index];
			while (temp != NULL)
			{
				fprintf(fptr,"#%d", index);
				fprintf(fptr,";%s", temp->word);
				fprintf(fptr,";%d", temp->file_count);

				slist* l_temp = temp->sublink;
				while (l_temp != NULL)
				{
					fprintf(fptr,";%s",l_temp->file_name);
					fprintf(fptr,";%d",l_temp->wordcount);
					l_temp = l_temp->slink;
				}
				fprintf(fptr,"#");
				fprintf(fptr,"\n");

				//Moving temp to next node
				temp = temp->mainlink;
			}
		}
		printf("Database saved successfully in %s\n", file_name);
		fclose(fptr);
	}
	else
	{
		printf("INFO:the database is not created properly\n");
	}
}

