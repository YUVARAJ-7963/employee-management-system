#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int check_mail(char[]);
int check_number(char[]);
int is_valid(char[]);
int ischar(char);
int check_number(char num[])
{
	int ans,i,ch=0;
	for(i=0;i<10;i++)
	{
		if(num[i]>='0' && num[i]<='9')
	   	{
	    	ch++;
	   	}
	}
	return ch;
}

int check_mail(char email[])
{
	int ans;
	ans=is_valid(email);
	return ans;
}
int is_valid(char mail[])
{
	int at=-1,dot=-1,i,j;
	if(!ischar(mail[0]))
	{
		return 0;
	}
	for(i=0;i<strlen(mail);i++)
	{
		if(mail[i]=='@')
		{
	   		at=i;
		}
		else if(mail[i] == '.')
		{
	   		dot=i;
		}
	}
	if(at==-1||dot==-1)
	{
		return 0;
	}
	if(at>dot)
	{
		return 0;
	}
	j=!(dot >= (strlen(mail))-1);
	return j;
}

int ischar(char c)
{
 	return ((c>='a'&&c<='z') || (c>='A' && c<='Z'));
}



