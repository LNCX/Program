#include<cstdio>
#include<iostream>
using namespace std;
int count,ans[3],a[10],b[10];
float A,B,C;
void print()
{
	for(int i=1;i<10;i++)
	{
		ans[(i-1)%3]*=10;
		ans[(i-1)%3]+=b[i];	
	}
	if(ans[0]/A==ans[1]/B&&ans[1]/B==ans[2]/C)
	{
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		count++;
	}
	else {ans[0]=0,ans[1]=0,ans[2]=0;}
}
void search(int x)
{
	if(x==10){print();return;}
	for(int i=1;i<=9;i++)
	if(!a[i])
	{
		a[i]=1,b[x]=i;
		search(x+1);
		a[i]=0,b[x]=0;
	}
}
int main()
{
	cin>>A>>B>>C;
	search(1);
	if(!count) cout<<"No!!!"<<endl;
}
