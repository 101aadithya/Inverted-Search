Author : AADITHYA SATHEESH KUMAR  
Upload Time : April 2024  
GitHub Link : https://github.com/101aadithya  
Project Tilte : Inverted Search  
Description : An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents.   
Language : C  
Compiler used : GCC (Compile as : gcc *.c )  

Usage (To be given via command line)  
To execute : ./a.out file1.txt file2.txt file3.txt  

NOTE: * Once the files are passed through the command line and program is executed it provides a menu for the user to choose from.  
1. Create database
2. Display database
3. Search database
4. Save database
5. Update database
6. Exit

                                                     FILE DESCRIPTION
   
main.c : Contains the main functions and a menu for the user to select from.  
validation.c : This validates the command line arguments passed.  
create_database.c : Contains the code to create a hashtable and store the words, wordcount, filecount.  
display_database.c : This file is used to display the cretaed database.  
save_database.c : Contains the code to save the created database into a separate text file.  
search_database.c : To search for a word in the database.  
update_database.c : Contains code to update an already saved database.  
