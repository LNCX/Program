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
		int loc[51]={0},move=0,count=0;
		double num[50]={0};
		scanf("%s",n);
		loc[51]=strlen(n);
		for(int i=0;i<100;i++)
		{
			if(n[i]!='0'&&n[i]!='1'&&n[i]!='2'&&n[i]!='3'&&n[i]!='4'&&n[i]!='5'&&n[i]!='6'&&n[i]!='7'&&n[i]!='8'&&n[i]!='9')  
			{
				loc[move]=i;
				move++;
			}
		}
		for(int i=0;i<=move;i++)
		{
			int middle=0;
			int move1=0;
			for(int j=middle;i<loc[move];i++)
			{
				num[move]+=(n[i]-48)*pow(10,loc[1]-i-1);
				move1++;
			}
		
		}
			switch(n[loc[i]])
			{
				case '+':
					sum+=
					break;
				case '-':
					sum-=
					break;
				case '*':
					sum*=
					break;
				case '/':
					if(b==0)
						falg=0;
					else
						sum/=
					break;
				default:
					falg=0;
	}	
}

