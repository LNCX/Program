#include<iostream>
#include<cmath>
#include<string.h>
using namespace std; 
int main()
{
	printf("目前只支持两个整数的四则运算，Youth丨吹雪正在努力改进中……\n"); 
	while(1)
	{
		char n[101];
		int loc[50]={0};
		double a=0,b=0;
		scanf("%s",n);
		loc[0]=strlen(n);
		for(int i=0;i<100;i++)
		{
			if(n[i]=='*'||n[i]=='+'||n[i]=='-'||n[i]=='/')
			{   
				loc[1]=i;
				break;
			}
		}
		for(int i=0;i<loc[1];i++)
		{
			a+=(n[i]-48)*pow(10,loc[1]-i-1);
		}
		for(int i=loc[1]+1;i<loc[0];i++)
		{
			b+=(n[i]-48)*pow(10,loc[0]-i-1);
		}
		switch(n[loc[1]])
		{
			case '+':
				printf("=%.0f\n",a+b);
				break;
			case '-':
				printf("=%.0f\n",a-b);
				break;
			case '*':
				printf("=%.0f\n",a*b);
				break;
			case '/':
				if(b==0)
					printf("Math ERROR\n");
				else
					cout<<"="<<a/b<<endl;
				break;
			default:
				printf("Syntax ERROR\n");
		}
	}
}

