#include <stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
void page1();
void remove_old_designation_salary(char Delete_id[],char filename[])
{
    FILE *inputFile, *tempFile;
    char line[300],c;
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) 
	{
        printf("File doesn/'t Existed\n\n");
        fclose(inputFile);
    }
    tempFile = fopen("temp2.txt", "w");
    if (tempFile == NULL) 
	{
        printf("File Can\'t be open'\n\n");
        fclose(tempFile);
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
    remove(filename);
    rename("temp2.txt", filename);
}
void run(char replace_string[],char filename[],char search_id[]) 
{
    FILE *file, *temp;
    char line[300];
    file = fopen(filename, "r"); 
    temp = fopen("temp1.txt", "w");
    if (file == NULL || temp == NULL) 
	{
        printf("Error opening file.");
    }
    while (fgets(line, sizeof(line), file)) 
	{
        if (strncmp(line, search_id, strlen(search_id)) == 0)
		 {
            fputs(replace_string, temp);
         } 
		else 
		 {
            fputs(line, temp); 
         }
    }
    fclose(file);
    fclose(temp);
	remove(filename);
	rename("temp1.txt", filename);
}

void Modify_Employee_Records()
{
	FILE *file;
	char strbuff[300];
 	int new_designation_choice,i,n=1;
 	int age,old_designation_choice;
 	long int basic_salary,netpay,gross_salary,detection,pf,it,da,hra;
 	char name[20],email_id[25],qualification[20],mobile_no[13],id[9];
 	char c, *designations[6]={"","Software Architect","Developer","Designer","Quality Assurance","Business Analyst"};
 	char *filename[9]={"","Software Architect salary.txt","Developer salary.txt","Desinger salary.txt","Quality Assurance salary.txt","Business Analyst salary.txt","Employee Details.txt","All salary details.txt"};
 	system("cls");
modify_again:printf("\n\t\t\t\t\t\t\t\t\t    Modify RECORD\n");
 		printf("\t\t\t\t\t\t\t\t\t------------------\n\n");
  		printf("\t\t\t\t\tType -1 to back\n");
  		printf("\n\n\t\t\t\t\tEnter Employee id : ");
  			scanf("%s",id);
			if(!(strcmp(id,"-1")))
			{
				Loading_time();
		   		page1();
		  	}
  		printf("\n\n\n\t\t\t\t\tEnter New details\n");
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
repeat_designation_choice: printf("\n\n\t\t\t\t\t\t\t1. Software Architect\n");
		printf("\t\t\t\t\t\t\t2. Developer\n");
		printf("\t\t\t\t\t\t\t3. Desinger\n");
		printf("\t\t\t\t\t\t\t4. Quality Assurance\n");
		printf("\t\t\t\t\t\t\t5. Business Analyst\n");
again_old_designation_choice:printf("\t\t\t\t\t\t\tEnter Your Old Designation Choice : ");
			scanf("%d",&old_designation_choice);
		  	if(old_designation_choice==-1)
		  	{
		  		Loading_time();
		   		page1();
		  	}
		  	if(old_designation_choice>6 || old_designation_choice<1 )
		  	{
		  		printf("\n\n\t\t\t\t\t\t\t\t***INVALID CHOICE...***\n");
				goto again_old_designation_choice;
			}	  	
again_new_designation_choice:printf("\n\t\t\t\t\t\t\tEnter Your New Designation Choice : ");
			scanf("%d",&new_designation_choice);
		  	if(new_designation_choice==-1)
		  	{
		  		Loading_time();
		   		page1();
		  	}
		  	if(new_designation_choice>6 || new_designation_choice<1 )
		  	{
		  		printf("\n\n\t\t\t\t\t\t\t\t***INVALID CHOICE...***\n");
				goto again_new_designation_choice;
			}
			if(old_designation_choice!=new_designation_choice)
			{
				remove_old_designation_salary(id,filename[old_designation_choice]);
  				printf("\n\t\t\t\t\t\t\tEnter the basic salary: ");
  					scanf("%lu",&basic_salary);
  					if(basic_salary==-1)
  					{
  						Loading_time();
   						page1();
  					}
				switch(new_designation_choice)
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
						fprintf(file,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
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
					 	fprintf(file,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
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
						fprintf(file,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
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
						fprintf(file,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
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
						fprintf(file,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
						fclose(file);
						break;
				}
			}
			else
			{
		  		printf("\n\t\t\t\t\t\t\tEnter the basic salary: ");
		  			scanf("%lu",&basic_salary);
		  			if(basic_salary==-1)
		  			{
		  				Loading_time();
		   				page1();
		  			}	
			  		switch(new_designation_choice)
			  		{
					   case 1:
					   	  	da=(basic_salary*4)/100;
 							hra=(basic_salary*3)/100;
 							pf=(basic_salary/100)*2;
 							it=(basic_salary/100)*1;
			 				gross_salary=basic_salary+da+hra;
			  				detection=pf+it;
			  				netpay=gross_salary-detection;
							sprintf(strbuff,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
							run(strbuff,filename[1],id);
							break;
					   case 2:
					   		da=(basic_salary*4.5)/100;
	 						hra=(basic_salary*3.5)/100;
	 						pf=(basic_salary/100)*2.5;
	 						it=(basic_salary/100)*1.5;
			 				gross_salary=basic_salary+da+hra;
			  				detection=pf+it;
			  				netpay=gross_salary-detection;
						 	sprintf(strbuff,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
						 	run(strbuff,filename[2],id);
							break;
					   case 3:
					   		da=(basic_salary*5)/100;
	 						hra=(basic_salary*4)/100;
	 						pf=(basic_salary/100)*3;
	 						it=(basic_salary/100)*2;
			 				gross_salary=basic_salary+da+hra;
			  				detection=pf+it;
			  				netpay=gross_salary-detection;
							sprintf(strbuff,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
							run(strbuff,filename[3],id);
							break;
					   case 4:
					   		da=(basic_salary*5.5)/100;
	 						hra=(basic_salary*4.5)/100;
	 						pf=(basic_salary/100)*3.5;
	 						it=(basic_salary/100)*2.5;
			 				gross_salary=basic_salary+da+hra;
			  				detection=pf+it;
			  				netpay=gross_salary-detection;
							sprintf(strbuff,"%-12s %-15s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
							run(strbuff,filename[4],id);
							break;
					   case 5:
					   		da=(basic_salary*6)/100;
 							hra=(basic_salary*5)/100;
 							pf=(basic_salary/100)*4;
 							it=(basic_salary/100)*3;
			 				gross_salary=basic_salary+da+hra;
			  				detection=pf+it;
			  				netpay=gross_salary-detection;
							sprintf(strbuff,"%-12s %-155s %-10d %-20lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
							run(strbuff,filename[5],id);
							break;
					}
			}
  		sprintf(strbuff,"\n%-12s %-20s %-10d %-25s %-20s %-30s %-20s %-15lu",id,name,age,qualification,mobile_no,email_id,designations[new_designation_choice],basic_salary);
		run(strbuff,filename[6],id);
  		sprintf(strbuff,"%-12s %-15s %-10d %-20s %-15lu %-10lu %-10lu %-10lu %-10lu %-15lu %-15lu %-15lu\n",id,name,age,designations[new_designation_choice],basic_salary,da,hra,pf,it,gross_salary,detection,netpay);
  		run(strbuff,filename[7],id);
  		printf("\n\n\t\t\t\t\t\t\t>>>>>Record is Modifyed Successfully<<<<<\n\n\n");
  		display();
   		printf("\n\nYou want to Modify another record (Y/N) : ");
  		c=getch();
  		printf("%c",c);
  		if(c=='y'||c=='Y')
  		{
  			Loading_time();
   			system("cls");
   			goto modify_again;
  		}
  		else
  		{
  			Loading_time();
   			page1();
  		}
}
