#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"Mail & Number Checking.C"
#include"Salary Headings.c"
#include"display Details.c"
#include"remove.c"
#include"modify.c"
void page1();
int gen_emp_id() 
{
    int random_number;
    FILE *file;
    char line[1000];
    char *token,str[1000];
    file = fopen("Employee Details.txt", "r");
    if (file == NULL) 
	{
		fclose(file);
        srand(time(NULL));
    	random_number = rand() ;
    	return random_number;
    }
	else
	{
    	while (fgets(line, sizeof(line), file)) 
		{
        	if (feof(file)) 
			{
            	token = strtok(line, " \t\n");
            	if (token != NULL) 
				{
					strcpy(str,token);
         		} 
            	break;
        	}
    	}
    	fclose(file);
    	random_number = atoi(str)+1;
    	return random_number;
	}
}
void intro()
{
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t    =============================""===============""===========================");
    printf("\n\t\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""~~~~~~~~~~~~~~~""~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t\t    =============================""==========================================");
    printf("\n\t\t\t\t\t    [[[[[[[[[[|:::>:::>:::>::>  ""EMPLOYEE RECORD""  <::<:::<:::<:::|]]]]]]]]]]");
    printf("\n\t\t\t\t\t    =============================""==========================================");
    printf("\n\t\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""~~~~~~~~~~~~~~~""~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t\t    =============================""===============""===========================\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t   ""Developer : @YUVARAJ""\n\n\n\n\n");
    printf("Press ANY Key to Continue...");
    getch();
}
void login()
{
	int a=0,i=0,j=0;
	system("cls");
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
	{
	    printf("\n\n\n\n\t\t\t\t\t\t:::::::::::::::::::::::::::::  LOGIN FORM  :::::::::::::::::::::::::::::  ");
	    printf(" \n\n\n\n\n\t\t\tENTER USERNAME :  ");
			scanf("%s", &uname);
		printf(" \n\t\t\tENTER PASSWORD :  ");
		while(i<10)
		{
		    pword[i]=getch();
		    c=pword[i];
		    if(c==13) break;
		    else printf("*");
		    i++;
		}
		pword[i]='\0';
		i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
		{
			printf("  \n\n\t\t\t\t\t\t\t\t\t>>>LOGIN IS SUCCESSFUL<<<");
			Sleep(3000);
			for(j=0;j<5;j++)
			{
			    system("cls");
				printf("\n\nSYSTEM LOADING PLEASE WAIT");
			    for(i=0; i<10; i++)
			    {
			        printf(".");
			        Sleep(250);
			    }
			}
			break;
		}
		else
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;
			Sleep(2000);
			system("cls");
		}
	}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for Three times!!!");
		getch();
		exit(0);
	}
	system("cls");
}
void add_record()
{
 	FILE *file;
 	int designation_choice,i,n=1;
 	int age,id;
 	long int basic_salary,netpay,gross_salary,detection,pf,it,da,hra;
 	char name[20],email_id[25],qualification[20],mobile_no[13];
 	char c, *designations[6]={"","Software Architect","Developer","Designer","Quality Assurance","Business Analyst"};
 	system("cls");
 	for(i=0;i<n;i++)
 	{
 		printf("\n\t\t\t\t\t\t\t\t\t    ADD RECORD\n");
 		printf("\t\t\t\t\t\t\t\t\t------------------\n\n");
  		printf("\t\t\t\t\tType -1 to back");
  		printf("\n\n\t\t\t\t\t\t\tEnter Name : ");
  			scanf("%s",name);
  			if(!(strcmp(name,"-1")))
  			{
  				Loading_time();
  				 page1();
  			}
  		printf("\t\t\t\t\t\t\tEnter age: ");
  			scanf("%d",&age);
  			if(age==-1)
  			{
  				Loading_time();
  				 page1();
  			}		
re_mail: printf("\t\t\t\t\t\t\tEnter Email.ID : ");
  			scanf("%s",email_id);
  			if(!(strcmp(email_id,"-1")))
  			{
  				Loading_time();
  				page1();
  			}
  			if(!(check_mail(email_id)))
  			{
  				printf("\n\t\t\t\t\t\t\t\tINVALID Email-ID...\n\n");
  				goto re_mail;
  			}			
re_mob_no: printf("\t\t\t\t\t\t\tEnter the Mobile.NO: ");
  				scanf("%s",&mobile_no);
  				if(!(strcmp(mobile_no,"-1")))
  				{
  					Loading_time();
  					page1();
  				}
  				if(!(check_number(mobile_no)==10))
 				{
   					printf("\n\t\t\t\t\t\t\t\tINVALID Mobile.NO...\n\n");
   					goto re_mob_no;
  				}
		printf("\t\t\t\t\t\t\tEnter the Qualification : ");
			scanf("%s",qualification);
			if(!(strcmp(qualification,"-1")))
			{
				Loading_time();
				page1();
			}	
		printf("\t\t\t\t\t\t\tEnter the basic salary: ");
  			scanf("%lu",&basic_salary);
  			if(basic_salary==-1)
  			{
  				Loading_time();
   				page1();
  			}
		id=gen_emp_id();
		printf("\t\t\t\t\t\t\tYour Employee ID : %lu",id);
repeat_designation_choice: printf("\n\n\t\t\t\t\t\t\t1. Software Architect\n");
		printf("\t\t\t\t\t\t\t2. Developer\n");
		printf("\t\t\t\t\t\t\t3. Desinger\n");
		printf("\t\t\t\t\t\t\t4. Quality Assurance\n");
		printf("\t\t\t\t\t\t\t5. Business Analyst\n");
		printf("\t\t\t\t\t\t\tEnter Your Choice : ");
			scanf("%d",&designation_choice);
		  	if(designation_choice==-1)
		  	{
		  		Loading_time();
		   		page1();
		  	}
  		switch(designation_choice)
  		{
		   case 1:
		   		file=fopen("Software Architect salary.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Software_Architect_salary_heading();
				}
				fclose(file);
		   	  	da=(basic_salary*4)/100;
 				hra=(basic_salary*3)/100;
 				pf=(basic_salary/100)*2;
 				it=(basic_salary/100)*1;
 				gross_salary=basic_salary+da+hra;
  				detection=pf+it;
  				netpay=gross_salary-detection;
				file=fopen("Software Architect salary.txt","a");
				fprintf(file,"%-12d %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
				fclose(file);
				break;
		   case 2:
		   		file=fopen("Developer salary.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Developer_salary_heading();
				}
				fclose(file);
		   		da=(basic_salary*4.5)/100;
 				hra=(basic_salary*3.5)/100;
 				pf=(basic_salary/100)*2.5;
 				it=(basic_salary/100)*1.5;
 				gross_salary=basic_salary+da+hra;
  				detection=pf+it;
  				netpay=gross_salary-detection;
			 	file=fopen("Developer salary.txt","a");
			 	fprintf(file,"%-12d %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
			 	fclose(file);
			break;
		   case 3:
		   		file=fopen("Desinger salary.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Desinger_salary_heading();
				}
				fclose(file);
		   		da=(basic_salary*5)/100;
 				hra=(basic_salary*4)/100;
 				pf=(basic_salary/100)*3;
 				it=(basic_salary/100)*2;
 				gross_salary=basic_salary+da+hra;
  				detection=pf+it;
  				netpay=gross_salary-detection;
				file=fopen("Desinger salary.txt","a");
				fprintf(file,"%-12d %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
				fclose(file);
				break;
		   case 4:
		   		file=fopen("Quality Assurance salary.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Quality_Assurance_salary_heading();
				}
				fclose(file);
		   		da=(basic_salary*5.5)/100;
 				hra=(basic_salary*4.5)/100;
 				pf=(basic_salary/100)*3.5;
 				it=(basic_salary/100)*2.5;
 				gross_salary=basic_salary+da+hra;
  				detection=pf+it;
  				netpay=gross_salary-detection;
				file=fopen("Quality Assurance salary.txt","a");
				fprintf(file,"%-12d %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
				fclose(file);
				break;
		   case 5:
		   		file=fopen("Business Analyst salary.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Business_Analyst_salary_heading();
				}
				fclose(file);
		   		da=(basic_salary*6)/100;
 				hra=(basic_salary*5)/100;
 				pf=(basic_salary/100)*4;
 				it=(basic_salary/100)*3;
 				gross_salary=basic_salary+da+hra;
  				detection=pf+it;
  				netpay=gross_salary-detection;	
				file=fopen("Business Analyst salary.txt","a");
				fprintf(file,"%-12d %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
				fclose(file);
				break;
		   default:
				printf("\n\n\t\t\t\t\t\t\t\t***INVALID CHOICE...***\n");
				goto repeat_designation_choice;
		}
		  
		file=fopen("Employee Details.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			Employee_Details_heading();
				}
		fclose(file);
  		file=fopen("Employee Details.txt","a");
  		fprintf(file,"\n%-12d %-20s %-10d %-25s %-20s %-30s %-20s %-15lu",id,name,age,qualification,mobile_no,email_id,designations[designation_choice],basic_salary);
  		fclose(file);
  		file=fopen("All salary details.txt","r");
		   		if(file==NULL)
		   		{
		   			fclose(file);
		   			All_salary_details_heading();
				}
		fclose(file);
  		file=fopen("All salary details.txt","a");
  		fprintf(file,"%-12d %-15s %-10d %-20s %-15lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,designations[designation_choice],basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
		fclose(file);
  		printf("\n\n\t\t\t\t\t\t\t>>>>>New Record is Added Successfully<<<<<\n\n\n");
  		display();
   		printf("\n\nYou want to Add another record (Y/N) : ");
  		c=getch();
  		printf("%c",c);
  		if(c=='y'||c=='Y')
  		{
  			Loading_time();
   			system("cls");
   			n++;
  		}
  		else
  		{
  			Loading_time();
   			page1();
  		}
 	}
}
void page1()
{	
	int choice;
	system("cls");
	reselect:system("cls");
	printf("\t\t\t\t\t\t\t         WELCOME TO EMPLOYEE RECORD MANAGEMENT SYSTEM !!!!\n");
	printf("\t\t\t\t\t\t\t-----------------------------------------------------------------\n\n");
	printf("\n\n\t\t\t\t\t\t\t\t1. Add New Record\n");
	printf("\t\t\t\t\t\t\t\t2. Display Salary Details\n");
	printf("\t\t\t\t\t\t\t\t3. Display Employee Details\n");
	printf("\t\t\t\t\t\t\t\t4. Modify Employee Records\n");
	printf("\t\t\t\t\t\t\t\t5. Delete Employee Record\n");
	printf("\t\t\t\t\t\t\t\t6. EXIT\n");
	printf("\t\t\t\t\t\t\t\tEnter Your Choice : ");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			Loading_time();
			add_record();
			break;
  		case 2:
  			Loading_time();
			salary_details();
			break;
  		case 3:
  			Loading_time();
			Display_Employee_Details();
			break;
  		case 4:
  			Loading_time();
			Modify_Employee_Records();
			break;
		case 5:
  			Loading_time();
			Delete_Employee_Record();
			break;
  		case 6:
			exit(0);
			break;
  		default:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t****INVALID CHOICE...Please Reselect****\n\n");
			Sleep(2000);
			goto reselect;
	}	
}
void main()
{
	intro();
	login();
	page1();	
}
