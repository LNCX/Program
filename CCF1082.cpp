#include<cstring>
#include<iostream>
using namespace std;
char a[1000],b[1000];
int len1,len2;
int f(int l1,int l2)
{
	int len=0;
	while(a[l1]==b[l2])
	{
		len++;
		l1++;
		l2++;
		if(l1>=len1) l1=0;
		if(l2>=len2) l2=0;
		if(len>=len1||len>=len2) return len;
	}
	return len;
}
int main()
{
	int i,j,Max;
	while(cin>>a>>b)
	{
		Max=0;
		len1=strlen(a);
		len2=strlen(b);
		if(len2==1||len1==1) break;
		for(i=0;i<len1;i++)
		{
			for(j=0;j<len2;j++)
			{
				Max=max(Max,f(i,j));
			}
		}
		cout<<Max<<endl;
	}
}
