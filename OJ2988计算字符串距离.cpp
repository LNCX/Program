#include<cstdio>
#include<cstring>
#include<iostream>
#define N 1005
using namespace std;
int n,l1,l2;int f[N][N];
char a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<N;i++) f[0][i]=i,f[i][0]=i;
    while(n--)
	{
        memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
        scanf("%s%s",a,b);
		l1=strlen(a),l2=strlen(b);
        for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
		{
            if(a[i-1]==b[j-1]) f[i][j]=min(f[i-1][j-1],min(f[i-1][j]+1,f[i][j-1]+1));
            else f[i][j]=min(f[i-1][j-1]+1,min(f[i-1][j]+1,f[i][j-1]+1));
        }
        printf("%d\n",f[l1][l2]);
    }
    return 0;
}
