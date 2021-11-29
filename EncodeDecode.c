#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void menu(char *letters, char *enc);
void encodeDecode(char *letters, char *enc, int func);

void main()
{
char * letters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
char * enc     = "kKnNgGcCaAdDsSxXbBvVfFhHjJtTiIuUmMyYlLzZqQrRoOpPwWeE";
menu(letters, enc);	
}

void menu(char *letters, char *enc)
{
int number;
system("cls");
printf("	#------------------------------------------#\n");
printf("	|          Project Encode / Decode         |\n");
printf("	|                                          |\n");
printf("	|  This program will either encode or      |\n");
printf("	|  decode a text file of your choosing.    |\n");
printf("	|  Files will output to the same directory |\n");
printf("	|  as this program.                        |\n");
printf("	|                                          |\n");
printf("	|   1. Encode a File                       |\n");
printf("	|   2. Decode a File                       |\n");
printf("	|   3. Exit Program                        |\n");
printf("	|                                          |\n");
printf("	#------------------------------------------#\n");
printf("	Make Selection: ");

 scanf("%d",&number);
 switch(number)
{
case  1: encodeDecode(letters, enc, number);break;
case  2: encodeDecode(letters, enc, number);break;
case  3: printf("\n\nGoodbye!\n\n");
		 system("pause");
		 exit(0);
		 break;
default: menu(letters, enc);break;
}
}

void encodeDecode(char *letters, char *enc, int func)
{
char writer;
FILE * fp;
FILE * encfp;
char * result;
char * pos;
char filename[30];
char newFile[30];
int position;
int c;

/* get user file name information */
if(func == 1)
{
printf("What is the name of the file you wish to encode?\n\n");
}
else
{
printf("What is the name of the file you wish to decode?\n\n");	
}
fflush(stdin);
fgets(filename,30,stdin);
if ((pos=strchr(filename, '\n')) != NULL)
{
    *pos = '\0';
}

/* Attempt to open file, if file exists, continue, otherwise abort function */
fp = fopen(filename, "r");
if(fp)
{
printf("The file named \"%s\" has been found!\n\n", filename);
fclose(fp);
}
else
{
printf("The file \"%s\" doesn't exist!\n\n", filename);
system("pause");
menu(letters, enc);
}

/* Now that we know file exists, we can ask for name of new file */
if(func == 1)
{
printf("What do you want to name the encoded file?\n\n");
}
else
{
printf("What do you want to name the decoded file?\n\n");	
}
fflush(stdin);
fgets(newFile,30,stdin);
if ((pos=strchr(newFile, '\n')) != NULL)
{
    *pos = '\0';
}

printf("You entered the file name \"%s\":\n\n", newFile);


/* Start encoding and writing to new file */
fp = fopen(filename, "r");
encfp = fopen(newFile, "w");
   while(!feof(fp))
   {
c = fgetc(fp);
if(func == 1)
{
result = strchr(letters, c);
position = result - letters;
}
else
{
result = strchr(enc, c);
position = result - enc;	
}
if(position >= 0){

if(func == 1)
{
writer = enc[position];
}
else
{
writer = letters[position];	
}
fwrite(&writer , 1 , sizeof(char) , encfp );
}
else
{
writer = c;
if(writer != EOF){
fwrite(&writer , 1 , sizeof(char) , encfp );
}
}
}
fclose(fp);

/* If file successfully created, close it and alert user, otherwise, let them know it didn't work */
   if(encfp)
   {
	  printf("successfully created file!\n\n");
	  fclose(encfp);
   }
   else{
	   printf("failed to create file! :( \n\n");
   }

printf("\n\n");
system("pause");
menu(letters, enc);
}
