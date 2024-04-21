#include "invert.h"
/*
Name          :	AADITHYA SATHEESH KUMAR	
Date          :	10-04-2024
Description   : iNVERTED SEARCH
sample input  :
sample output :
 */


void display_database (mlist *head[])
{
    //Printing the database
    printf("[index] [word] filecount file/s : file_name word_count\n");
    printf("\n--------------------------------------------------\n");
    
    for (int i = 0 ; i < 27; i++)
    {
	mlist* temp = head[i];
       
	//Traversing through the list till last node of Wlist
        while (temp != NULL)
        {
            printf("[%d] [%s] %2d files:\t", i, temp->word, temp->file_count);
            slist* mhead = temp->sublink;

	    //Traverse through link table
            while (mhead != NULL)
            {
                printf("%s %d\t",mhead->file_name, mhead->wordcount);
                mhead = mhead->slink;
            }
            printf("\n");           
	        //Moving temp to next node
            temp = temp->mainlink;
        }
    }
    printf("\n--------------------------------------------------\n");
}
