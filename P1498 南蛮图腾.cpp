#include<bits/stdc++.h>
using namespace std;
int len[10]={2,4,8};//4*2^(n-1)
char c[1030][1030];
char one[2][4]=
{
    ' ','/','\\',' ',
    '/','_','_','\\'
};
void make(int n,int x,int y)
{
    if(n==1)
    {
		for(int i=0;i<4;i++)
		{
			c[x][y+i]=one[1][i];
			c[x+1][y+i]=one[0][i];
		}
        return ;
    }
    make(n-1,0,0);
    make(n-1,len[n-1]+1,0);
    make(n-1,len[n-2]+1,len[n-2]/2+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        len[i]=2*len[i-1];
    make(n,0,0);
    for(int i=len[n]/2-1;i>=0;i--)
    {
        for(int j=0;j<len[n];j++)
            printf("%c",c[i][j]);
        printf("\n");
    }
}
