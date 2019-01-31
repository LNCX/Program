#include<iostream>
#include<string.h>
using namespace std;
int judge(int l,int r,int &flag,char n[100]);
int main()
{
	int flag=1;
	char n[100];
	cin>>n;
	judge(0,strlen(n)-1,flag,n);
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int judge(int l,int r,int &flag,char n[100])
{
	int a=0,b=0;
	int loc[2]={0};
	for(int i=l;i<=r;i++)
	{
		if(n[i]=='[') a++;
		else if(n[i]==']') a--;
		if(a==0) loc[0]=i;
	}
	for(int i=l;i<=r;i++)
	{
		if(n[i]=='(') b++;
		else if(n[i]==')') b--;
		if(b==0) loc[1]=i;
	}
	if((loc[0]-l)%2==1&&(loc[1]-l)%2==1)
	{
		judge(l,loc[0],flag,n);
		judge(loc[0]+1,r,flag,n);	
	}
	else flag=0; 
} 
