#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N],mid[N];
int n,d[N][N];
bool match(char a,char b) {return(a == '(' && b == ')') || (a == '[' && b == ']');}
void dp()
{
	for(int i = 0; i < n; i++)
	{
		d[i+1][i]=0;
		d[i][i]=1;
	}
	for(int i=n-2;i>=0;i--)
		for(int j=i+1;j<n;j++)
		{
			d[i][j]=n;
			if(match(s[i],s[j])) d[i][j]=min(d[i][j],d[i+1][j-1]);
			for(int k=i;k<j;k++)
				d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
		}
}

void print(int i,int j)
{
	if(i>j) return ;
	if(i==j)
	{
		if(s[i]=='('||s[i]==')') printf("()");
		else printf("[]");
		return;
	}
	int ans=d[i][j];
	if(match(s[i],s[j])&&ans==d[i+1][j-1])
	{
		printf("%c",s[i]);
		print(i+1,j-1);
		printf("%c",s[j]);
		return;
	}
	for(int k=i;k<j;k++)
		if(ans==d[i][k]+d[k+1][j])
		{
			print(i,k);
			print(k+1,j);
			return;
		}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		gets(mid);
		gets(s); 
		n=strlen(s)-1;
		memset(d,-1,sizeof(d));
		dp();
		print(0,n-1);
	}
	return 0;
}
