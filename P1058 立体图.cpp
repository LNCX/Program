#include<bits/stdc++.h>
using namespace std;
char cub[8][8]=
{
	"**+---+",
 	"*/   /|",
 	"+---+ |",
 	"|   | +",
 	"|   |/*",
 	"+---+**",
};
char ans[1000][1000];
int m,n,a[55][55],lenx,leny;
void cmap(int x,int y)
{
	for(int i=0;i<=5;i++)
	for(int j=0;j<=6;j++)
		if(cub[i][j]!='*')
			ans[y+5-i][x+j]=cub[i][j];
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	memset(ans,'.',sizeof(ans));
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<a[i][j];k++)
	{
		int x=4*j+2*(m-1-i),
			y=2*(m-1-i)+3*k;
		lenx=max(lenx,x+6);
		leny=max(leny,y+5);
		cmap(x,y);
	}
	for(int i=leny;i>=0;i--)
	{
		for(int j=0;j<=lenx;j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
}
