#include<bits/stdc++.h>
using namespace std;
const int maxn=50000;
bool used[maxn];
struct block
{
	int d[3][5];
}a,mid,m[maxn];
int target,q[maxn],pre[maxn],ans[maxn];
int f(int x)
{
	if(x==0)return 0;
    if(x==1)return 1;
    return x*f(x-1);
}
int turn(block x)
{
	int sum=0,tuo[9];
	for(int i=1;i<=4;i++)
	{
		tuo[i]=x.d[1][i];
		tuo[i+4]=x.d[2][i];
	}
	for(int i=1;i<=8;i++)
	{
		int s=0;
		for(int j=i+1;j<=8;j++)
			if(tuo[i]>tuo[j])
				s++;
		sum+=s*f(8-i);
	}
	return sum; 
}
int A(int head)
{
	mid=m[head];
	for(int i=1;i<=4;i++)
		swap(mid.d[1][i],mid.d[2][i]);	
	return turn(mid);
}
int B(int head)
{
	for(int i=1;i<=3;i++)
	{
		mid.d[1][i+1]=m[head].d[1][i];
		mid.d[2][i+1]=m[head].d[2][i];
	}
	mid.d[1][1]=m[head].d[1][4];
	mid.d[2][1]=m[head].d[2][4];
	return turn(mid);
}
int C(int head)
{
	mid=m[head];
	mid.d[1][2]=m[head].d[2][2];
	mid.d[1][3]=m[head].d[1][2];
	mid.d[2][3]=m[head].d[1][3];
	mid.d[2][2]=m[head].d[2][3];
	return turn(mid);
}
void print(int x)
{
	int cnt=0;
	for(int i=x;i!=0;i=pre[i])
		ans[++cnt]=q[i];
	printf("%d\n",cnt-1); 
	for(int i=1;i<cnt;i++)
	{
		printf("%c",ans[i]+'A'-1);
		if(i%60==0) printf("\n");
	}
	printf("\n");
}
void bfs()
{
	int head=0,tail=1,mark;
	int (*p[4])(int x)={NULL,A,B,C};
	q[1]=0,m[1]=a,used[turn(a)]=true;
	while(head<tail)
	{
		head++;
		for(int i=1;i<=3;i++)
		{
			mark=p[i](head);
			if(!used[mark])
			{
				used[mark]=true;
				tail++;
				q[tail]=i;
				m[tail]=mid;
				pre[tail]=head;
				if(mark==target)
				{
					print(tail);
					return ;
				}
			}
		}
	}
}
int main()
{
	int cnt=1;
	for(int i=1;i<=4;i++)
		scanf("%d",&mid.d[1][i]);
	for(int i=4;i>=1;i--)
		scanf("%d",&mid.d[2][i]);
	for(int i=1;i<=4;i++)
	{
		a.d[1][i]=cnt;
		a.d[2][4-i+1]=cnt+4;
		cnt++;	
	}
	target=turn(mid);
	bfs();
}
