#include<bits/stdc++.h>
using namespace std;
struct node
{
	double x;
	double y;
}a[20];
int n;
bool used[20];
double ans=-1,f[20][20];
void dfs(int p,int i,double len)
{
	if(len>ans&&ans!=-1) return;
	if(i>n&&(len<ans||ans==-1))
	{
		ans=len;
		return ;
	}
	for(int j=0;j<=n;j++)
	if(!used[j]&&j!=p)
	{
		used[j]=true;
		len+=f[p][j];
		dfs(j,i+1,len);
		used[j]=false;
		len-=f[p][j];
	}
}
int main()
{
	cin>>n;
	a[0].x=0,a[0].y=0;
	for(int i=1;i<=n;i++)	
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		f[i][j]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
	used[0]=true;
	dfs(0,1,0);
	printf("%.2f\n",ans);
}
