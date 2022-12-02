//ICSI 333. System Fundamentals, Spring 2022
//TA Sourav Dutta
//Joseph LaBianca, 001442880
//Arithmetic Expression/Number Conversion
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

char res1[1000];
char * number_conversion(int num, int radix)
{
	char res[1000];
	int rem;
	int i=0;
	res[0]='\0';
	
	int t=0;
	
	int num1=num;
	if(num<0)
		num*=-1;
	while(num)
	{
		rem=num%radix;
		
		if(rem<=9)
		{
			res[i]=rem+'0';
			i++;
		}
		else if(rem>9)
		{
			
			res[i]=rem+'0'+7;
			i++;
			
		}
		num=num/radix;
		t++;
	}
	//char res1[1000];
	int c=1;
	
	if(num1>=0)
		res1[0]=' ';
	else if(num1<0)
		res1[0]='-';
	for(int j=t-1;j>=0;j--)
	{
		res1[c]=res[j];
		c++;
	}
	return res1;

}
int expression_solver(char *exp)
{
	
	int total=exp[0]-'0';
	int c=0;
	for(int i=1;exp[i]!='\0';i+=2)
	{
		 if (exp[i] == '+')       
		 	total += exp[i+1]-'0';
		else if (exp[i] == '-')  
			total -= exp[i+1]-'0';
		else if (exp[i] == '*')  
			total *= exp[i+1]-'0';
		else if (exp[i] == '/')  
			total /= exp[i+1]-'0';
	}
	return total;
}
int main()
{
	//expression solver
	
	int count=0;
	char exp[1000];
	do{
		printf("Enter Expression: ");
		
		scanf(" %s",exp);
		
		while(exp[count]!='\0')
		{
			count++;	
		}
	
		if(count>80)
			printf("Expression should not be longer than 80\n");
			fflush(stdout);
	}while(count>80);
	
	int result1=expression_solver(exp);
	printf("value = %d\n",result1);
	fflush(stdout);
	
	//number conversion
	int radix;
	printf("Enter Radix: ");
	fflush(stdout);
	scanf("%d",&radix);
	
	
	printf("Answer = %s\n",number_conversion(result1,radix));
	fflush(stdout);

	return 1;
}
