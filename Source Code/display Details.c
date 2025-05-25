#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void page1();
void salary_details();

void Loading_time()
{
	int j,i;
	for(j=0;j<3;j++)
	{
	    system("cls");
		printf("\n\nSYSTEM LOADING PLEASE WAIT");
	    for(i=0; i<3; i++)
	    {
	        printf(".");
	        Sleep(200);
	    }
	}
}
void Display_Software_Architect_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tSoftware Architect Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    ------------------------------------------\n\n\n");
	fa=fopen("Software Architect salary.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
		}while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
}
void Display_Developer_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tDeveloper Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    --------------------------------\n\n\n");
	fa=fopen("Developer salary.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
} 
void Display_Designer_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tDesigner Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    -------------------------------\n\n\n");
	fa=fopen("Desinger salary.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
}
void Display_Quality_Assurance_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tQuality Assurance Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    ------------------------------------------\n\n\n");
	fa=fopen("Quality Assurance salary.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
}
void Display_Business_Analyst_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tBusiness Analyst Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    -----------------------------------------\n\n\n");
	fa=fopen("Business Analyst salary.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
}
void Display_All_Salary_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tAll Salary Details\n");
	printf("\t\t\t\t\t\t\t\t    --------------------------\n\n\n");
	fa=fopen("All salary details.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress Any Key to Continue...");
	getch();
	Loading_time();
	salary_details();
}
void Display_Employee_Details()
{
	FILE *fa;
	char c;
	system("cls");
	printf("\t\t\t\t\t\t\t\t\tEmployee Details\n");
	printf("\t\t\t\t\t\t\t\t    ------------------------\n\n\n");
	fa=fopen("Employee Details.txt","r");
	if(fa==NULL)
	{
		printf("File doesn/'t Existed\n\n");
		fclose(fa);
	}
	do{
		c=fgetc(fa);
		printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
	printf("\n\nPress ANY Key to Continue...");
	getch();
	Loading_time();
	page1();
}
void display()
 {
	FILE *fa;
	char c;
	printf("\t\t\t\t\t\t\t\tEmployee Details\n");
	printf("\t\t\t\t\t\t\t    ------------------------\n\n\n");
	fa=fopen("Employee Details.txt","r");
	if(fa==NULL)
	{
 		printf("File doesn/'t Existed\n\n");
 		fclose(fa);
	}
	do{
	  	c=fgetc(fa);
	  	printf("%c",c);
	  }while(c!=EOF);
	fclose(fa);
}
void salary_details()
{
	 int choice;
	 system("cls");
	 reselect:printf("\t\t\t\t\t\t\t\t\tSALARY DETAILS\n");
	 printf("\t\t\t\t\t\t\t\t    ----------------------\n\n\n\n");
	 printf("\t\t\t\t\t\t1. All Salary Details\n");
	 printf("\t\t\t\t\t\t2. Software Architect Salary Details\n");
	 printf("\t\t\t\t\t\t3. Developer Salry Details\n");
	 printf("\t\t\t\t\t\t4. Designer Details\n");
	 printf("\t\t\t\t\t\t5. Quality Assurance\n");
	 printf("\t\t\t\t\t\t6. Business Analyst\n");
	 printf("\t\t\t\t\t\t7. Back\n");
	 printf("\t\t\t\t\t\tEnter Your Choice : ");
		scanf("%d",&choice);
	 switch(choice)
	 {
	  case 1:
			Loading_time();
			Display_All_Salary_Details();
			break;
	  case 2:
		  	Loading_time();
			Display_Software_Architect_Salary_Details();
			break;
	  case 3:
		  	Loading_time();
			Display_Developer_Salary_Details();
			break;
	  case 4:
		  	Loading_time();
			Display_Designer_Salary_Details();
			break;
	  case 5:
		  	Loading_time();
			Display_Quality_Assurance_Salary_Details();
			break;
	  case 6:
		  	Loading_time();
			Display_Business_Analyst_Salary_Details();
			break;
	  case 7:
		  	Loading_time();
			page1();
			break;
	  default:
			printf("\n\t\t\t\t\t\t\t\t***INVALID CHOICE...Please Reselect***\n\n");
			Sleep(2000);
			system("cls");
			goto reselect;
	}
} 
