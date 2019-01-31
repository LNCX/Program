#include<queue>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<ctime>
#include<cmath>
#define LL long long
using namespace std;
inline int read()
{
	int data=0;
	int w=1;
	char ch=0;
	ch=getchar();
	while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0' && ch<='9') data=(data<<3)+(data<<1)+ch-'0',ch=getchar();
	return data*w;
}
struct N
{
	LL wei;
	LL nxt;
} a[20001];
LL n;
LL m;
LL cnt=0;
LL num=0;
LL top=0;
LL xu[10001];
LL lowest[10001];
LL head[20001];
LL zhan[20001];
LL jilu[20001];
LL root;
LL p=0;
inline void add(LL tou,LL wei)
{
	a[++cnt].wei=wei;
	a[cnt].nxt=head[tou];
	head[tou]=cnt;
}
vector<LL>G[100000];
inline void tarjan(LL tou)
{
	xu[tou]=lowest[tou]=++num;
	zhan[++top]=tou;
	LL son=0;
	for(LL i=head[tou]; i; i=a[i].nxt)
	{
		LL wei=a[i].wei;
		if(!xu[wei])
		{
			son++;
			tarjan(wei);
			lowest[tou]=min(lowest[tou],lowest[wei]);
			if((tou==root&&son>1)||(tou!=root&&xu[tou]<=lowest[wei]))
				jilu[tou]=1;
			if(xu[tou]<=lowest[wei])
			{
				p++;
				G[p].clear();
				while(1)
				{
					G[p].push_back(zhan[top--]);
					if(zhan[top+1]==wei)break;
				}
				G[p].push_back(tou);
			}
		}
		else lowest[tou]=min(lowest[tou],xu[wei]);
	}
}
int main()
{
	LL shu=0;
	while(1)
	{
		m=read();
		if(m==0)break;
		n=0;
		memset(xu,0,sizeof(xu));
		memset(lowest,0,sizeof(lowest));
		memset(jilu,0,sizeof(jilu));
		memset(head,0,sizeof(head));
		cnt=0;
		top=0;
		for(LL i=1; i<=m; i++)
		{
			LL a;
			LL b;
			a=read();
			b=read();
			n=max(n,max(a,b));
			add(a,b);
			add(b,a);
		}
		p=0;
		for(LL i=1; i<=n; i++)
		{
			if(xu[i]==0)
			{
				root=i;
				tarjan(i);
			}
		}
		LL sum=1;
		LL ans=0;
		for(LL i=1; i<=p; i++)
		{
			LL sum1=0;
			for(LL j=0; j<G[i].size(); j++)
			{
				if(jilu[G[i][j]])sum1++;
			}
			if(sum1==0)ans+=2,sum=sum*(G[i].size()-1)*G[i].size()/2;
			else if(sum1==1)ans++,sum=sum*(G[i].size()-1);
		}
		printf("Case %lld: %lld %lld\n",++shu,ans,sum);
	}
	return 0;
}
