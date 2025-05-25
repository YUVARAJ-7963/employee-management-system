#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
void page1();
void check_it()
{
	FILE *file;
	char line[300];
	int count=0;
	file=fopen("Employee Details.txt","r");
	while (fgets(line, sizeof(line),file)) 
	{
    	count+=1;
    }
    if(count==4)
    {
    	fclose(file);
    	remove("Employee Details.txt");
	}
}
void Delete_Employee_Record() 
{
    FILE *inputFile, *tempFile;
    char line[300],c;
    char Delete_id[9],*filename[8]={"Software Architect salary.txt","Developer salary.txt","Desinger salary.txt","Quality Assurance salary.txt","Business Analyst salary.txt","Employee Details.txt","All salary details.txt"};
    int i,flag=1;
	system("cls");
	printf("\t\t\t\t\t\t\t\t         DELETE EMPLOYEE RECORD\n");
	printf("\t\t\t\t\t\t\t-----------------------------------------------------------------\n\n");
  	printf("\t\t\t\t\tType -1 to back");
  	printf("\n\n\t\t\t\t\t\t\tEnter Employee ID to Delete : ");
  			scanf("%s",Delete_id);
			if(!(strcmp(Delete_id,"-1")))
			{
				Loading_time();
		   		page1();
		  	}
    for(i=0;i<7;i++)
    {
	    inputFile = fopen(filename[i], "r");
	    tempFile = fopen("temp.txt", "w");
	    if (tempFile == NULL)
		{
	        printf("File Can\'t be open'\n\n");
	        fclose(inputFile);
	    }
	    while (fgets(line, sizeof(line), inputFile))
		{
	        if (strncmp(line, Delete_id, strlen(Delete_id)) != 0)
			{
	            fputs(line, tempFile);
	        }
	    }
	    fclose(inputFile);
	    fclose(tempFile);
	    remove(filename[i]);
	    rename("temp.txt", filename[i]);
	    flag=1;
	}
	if (flag=1)
	{
		printf("\n\n\t\t\t\t\t\t\t----->Employee Record Deleted Successfully.<-----\n\n\n\n");
		display();
		check_it();
	}
	else
	{
		Prinrf("\n\n\t\t\t\t\t***Employee Id Does\'t Existed***");
	}
	printf("\n\nYou want to Delete another record (Y/N) : ");
	c=getch();
	printf("%c",c);
	if(c=='y'||c=='Y')
	{
	   	system("cls");
	   	Delete_Employee_Record();
	}
	else
	{
	  	Loading_time();
	   	page1();
	}
}
