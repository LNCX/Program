#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,ans,used[20];
char a[20][100005],word; 
int search(char *x,char *y)
{
	int count=0,lenx=strlen(x),leny=strlen(y);
	for(int i=1;i<=(lenx<leny?lenx:leny);i++)
	{
		for(int j=0;j<i;j++)
			if(x[lenx-i+j]!=y[j]){count=0;break;}
			else count=i;
		if(count!=0) break;
	}
	if(count>=lenx||count>=leny) count=0;
	return count;
}
void dfs(char *s,int len)
{
	if(len>ans)	ans=len;
	for(int i=0;i<n;i++)
	{
		int mid=search(s,a[i]);
		if(used[i]<=1&&mid)
		{
			len+=strlen(a[i])-mid;
			used[i]++;
			dfs(a[i],len);
			used[i]--;
			len-=(strlen(a[i])-mid);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)	
		scanf("%s",a[i]);
	cin>>word;
	for(int i=0;i<n;i++)
		if(a[i][0]==word)
		{
			used[i]++;
			dfs(a[i],strlen(a[i]));
			used[i]--;
		}
	cout<<ans<<endl;
}
