#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
struct cub
{
	int d[4][4];
}a,mid,q[N];
int mark,target,used[N],ans[N],pre[N]={-1};
int f[10]={0,1,2,6,24,120,720,5040,40320,362880};
int turn(cub x)
{
	int to[10],sum=0;
	for(int i=1;i<=3;i++)
	{
		to[i+0]=x.d[1][i];
		to[i+3]=x.d[2][i];
		to[i+6]=x.d[3][i];
	}
	for(int i=1;i<=9;i++)
	{
		int s=0;
		for(int j=i+1;j<=9;j++)
			if(to[i]>to[j])
				s++;
		sum+=s*f[9-i];
	}
	return sum;
}
int A(int head)
{
	mid=q[head];
	mid.d[1][1]=q[head].d[2][1],mid.d[1][2]=q[head].d[1][1];
	mid.d[1][3]=q[head].d[1][2],mid.d[2][3]=q[head].d[1][3];
	mid.d[3][3]=q[head].d[2][3],mid.d[3][2]=q[head].d[3][3];
	mid.d[3][1]=q[head].d[3][2],mid.d[2][1]=q[head].d[3][1];
	return turn(mid);
}
int B(int head)
{
	mid=q[head];
	mid.d[2][1]=q[head].d[2][3];
	mid.d[2][2]=q[head].d[2][1];
	mid.d[2][3]=q[head].d[2][2];
	return turn(mid);
}
void print(int x)
{
	int cnt=0;
	for(int i=x;i!=-1;i=pre[i])
		ans[++cnt]=i;
	printf("%d\n",cnt-2);
	for(int i=--cnt;i>=1;i--)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
				printf("%d ", q[ans[i]].d[j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
void bfs()
{
	int head=0,tail=1;
	int (*p[3])(int)={NULL,A,B};
	q[1]=a,used[turn(a)]=1,pre[1]=0;
	while(head<tail)
	{
		head++;
		for(int i=1;i<=2;i++)
		{
			mark=p[i](head);
			if(!used[mark])
			{
				tail++;
				q[tail]=mid;
				used[mark]=1;
				pre[tail]=head;
			}
			if(mark==target)
			{
				print(tail);
				exit(0);
			}
		}
	}
}
int main()
{
	int cnt=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a.d[i][j]);
			mid.d[i][j]=cnt++;		
		}
	target=turn(mid);
	bfs();
	printf("UBSOLVABLE\n");
}
