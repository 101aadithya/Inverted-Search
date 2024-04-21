#include "invert.h"
/*
Name          : AADITHYA SATHEESH KUMAR
Date          :	10-04-2024
Description   : iNVERTED SEARCH
sample input  :
sample output :
 */

/* Function to do all the validations */
void file_validation(flist **f_head,char* argv[])
{
	int i = 1, ret_val, empty;
    while (argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)
        {
            printf("File: %s is not available\n", argv[i]);
	        printf("Hence we are not adding this into File Linked List\n");
            i++;
	        continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf("File: %s is Empty\n", argv[i]);
	        printf("Hence we are not adding %s into File Linked List\n", argv[i]);
            i++;	    
            continue;
        }
        else
        {
            //File valid then  add it to the linked list
            ret_val = to_create_list_of_files(f_head, argv[i]);
            if (ret_val == SUCCESS)
            {
                printf("Successful: Inserting file %s into the File Linked List\n",argv[i]);
            }
            else if (ret_val == REPEATATION)
            {             		
                printf("This file name : %s is repeated, so  we do not add more than once :\n", argv[i]);           
            }
            else
            {
                printf("Failed: to add the file into the File Linked List");
            }
            i++;
        }
    }
}
/* Function is called to check for file availability and for its contents */
int isFileEmpty(char* filename)
{
    //Opening the file read only mode
    FILE* fptr = fopen(filename, "r");

    //Validating fptr. If fprt NULL then file not available
    if (fptr == NULL)
    {
        return FILE_NOTAVAILABLE;
    }

    //Check if file empty or not
    fseek(fptr, 0L, SEEK_END);
    if (ftell(fptr) <= 1)
    {
        return FILE_EMPTY;
    }
    //If ftell(fptr) not 0 that means file has some data so return SUCCESS
    return SUCCESS;
}

/* Inserting the file in Flist */
int to_create_list_of_files (flist** head, char* filename)
{
    flist* temp = *head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }

    //Creating new node
    flist* new_file = malloc(sizeof(flist));
    
    //Validating new
    if (new_file == NULL)
    {
        return FAILURE;
    }

    //Updating filename and link part
    new_file->file_name= filename;
    new_file->link = NULL;
    if (*head == NULL)
    {
        *head = new_file;
         return SUCCESS;
    }

    temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new_file;
    return  SUCCESS;
}




