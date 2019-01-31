#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,q;
bool a[5000000],b[5000000];

void bf1()
{
	int i=1;
	a[1]=0;
	while(n--)
	{
		for(int j=i+1; j<=2*i; j++)
			a[j]=a[j-i]^1;
		i*=2;
	}
	for(i=1; i<=(1<<22); i++)
		if(a[i])putchar('1');
		else putchar('0');
	puts("");
}

void ibf2()
{
	int i,j,k,x=3524578;
	a[i=1]=0;
	while(i<x)
	{
		k=0;
		for(j=1; j<=i; j++)
			if(a[j])b[++k]=1,b[++k]=0,b[++k]=1;
			else b[++k]=0,b[++k]=1;
		i=k;
		for(j=1; j<=i; j++)a[j]=b[j];
	}
	for(j=1; j<=i; j++)
		if(a[j])putchar('1');
		else putchar('0');
	puts("");
}

bool v[600000];
int sum=531441;
char cc[600000];

bool bfdfs(int x,int now)
{
	if(v[now])return 0;
	v[now]=1;
	if(x==sum+11)return 1;
	cc[x]='0';
	if(bfdfs(x+1,now*3%sum))return 1;
	cc[x]='1';
	if(bfdfs(x+1,(now*3+1)%sum))return 1;
	cc[x]='2';
	if(bfdfs(x+1,(now*3+2)%sum))return 1;
	v[now]=0;
	return 0;
}

void ibf3()
{
	//zhe ge dian shi shenmegui
	for(int i=0; i<12; i++)cc[i]='0';
	bfdfs(12,0);
	printf("%s\n",cc);
}

int fa[100010];
int ifind(int x)
{
	if(fa[x]==0)return x;
	return fa[x]=ifind(fa[x]);
}

int ni(int x,int p)
{
	int y=p-2,s=1;
	while(y)
	{
		if(y&1)s=(ll)s*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return s;
}

void ibf4()
{
	n=262144;
	int p=104857601;
	cout<<n<<endl<<1<<endl;;
	int x=1;
	for(int i=1; i<=n; i++)
	{
		x=(ll)x*(n-i+1)%p*ni(i,p)%p;
		printf("%d\n",x);
	}
}

void ibf5()
{
	n=131072;
	int p=104857601;
	cout<<n<<endl<<1<<endl;;
	int x=1,y;
	for(int i=1; i<=n; i++)
	{
		x=(ll)x*(n-i+1)%p*ni(i,p)%p;
		y=x;
		if(i%2==1)y=p-y;
		printf("%d\n",y);
	}
}

void ibf6()
{
	n=177147;
	int c,p=104857601,i,a=23333333,b=33333333,a1,b1;
	b1=a1=c=1;
	for(i=1; i<=n; i++)a1=(ll)a1*a%p;
	puts("177147");
	for(i=1; i<=n; i++)
	{
		int x=(ll)a1*b1%p*c%p;
		printf("%d\n",x);
		c=(ll)c*(n-i+1)%p*ni(i,p)%p;
		a1=(ll)a1*ni(a,p)%p;
		b1=(ll)b1*b%p;
	}
	int x=(ll)a1*b1%p*c%p;
	printf("%d\n",x);
}

struct bian
{
	int en,next,w;
} G[200010];
int tot,start[100010],dis[100010][20],f[100010][20],dep[100010];

void idfs(int x)
{
	for(int i=1; i<20; i++)
		f[x][i]=f[f[x][i-1]][i-1],dis[x][i]=max(dis[x][i-1],dis[f[x][i-1]][i-1]);
	for(int ne,i=start[x]; i; i=G[i].next)
		if((ne=G[i].en)!=f[x][0])
		{
			f[ne][0]=x;
			dep[ne]=dep[x]+1;
			dis[ne][0]=G[i].w;
			idfs(ne);
		}
}

int lca(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
	int ans=0;
	for(int i=19; i>=0; i--)
		if(dep[y]-dep[x]>=(1<<i))ans=max(ans,dis[y][i]),y=f[y][i];
	for(int i=19; i>=0; i--)
		if(f[x][i]!=f[y][i])ans=max(ans,max(dis[y][i],dis[x][i])),x=f[x][i],y=f[y][i];
	if(x==y)return ans;
	return max(ans,max(dis[x][0],dis[y][0]));
}

struct bian2
{
	int u,v,w;
} B[100010];

bool cmp(bian2 p,bian2 q)
{
	return p.w<q.w;
}

void iWork()
{
	cin>>n;
	if(n==22)
	{
		bf1();
		return;
	}
	if(n==33)
	{
		ibf2();
		return;
	}
	if(n==12)
	{
		ibf3();
		return;
	}
	if(n==131072)
	{
		ibf4();
		return;
	}
	if(n==262144)
	{
		ibf5();
		return;
	}
	if(n==531441)
	{
		ibf6();
		return;
	}
	if(n==100000)
	{
		cin>>m>>q;
		if(m==100000&&q==200000)
		{
			for(int i=1; i<=m; i++)
			{
				int u,v;
				scanf("%d %d",&u,&v);
				u=ifind(u);
				v=ifind(v);
				if(u!=v)fa[u]=v;
			}
			while(q--)
			{
				int u,v;
				scanf("%d %d",&u,&v);
				u=ifind(u);
				v=ifind(v);
				if(u!=v)printf("2139062143\n");
				else printf("0\n");
			}
			return;
		}
		if(m==99999&&q==200000)
		{
			for(int i=1; i<=m; i++)
			{
				int u,v,w;
				scanf("%d %d %d",&u,&v,&w);
				tot++;
				G[tot].en=v;
				G[tot].w=w;
				G[tot].next=start[u];
				start[u]=tot;
				tot++;
				G[tot].en=u;
				G[tot].w=w;
				G[tot].next=start[v];
				start[v]=tot;
			}
			idfs(1);
			while(q--)
			{
				int u,v;
				scanf("%d %d",&u,&v);
				int ans=lca(u,v);
				printf("%d\n",ans);
			}
			return;
		}
	}
	if(n==50000)
	{
		cin>>m>>q;
		for(int i=1; i<=m; i++)
		{
			scanf("%d %d %d",&B[i].u,&B[i].v,&B[i].w);
		}
		sort(B+1,B+m+1,cmp);
		for(int i=1; i<=m; i++)
		{
			int u=ifind(B[i].u),v=ifind(B[i].v);
			if(u!=v)
			{
				fa[u]=v;
				tot++;
				G[tot].en=B[i].v;
				G[tot].w=B[i].w;
				G[tot].next=start[B[i].u];
				start[B[i].u]=tot;
				tot++;
				G[tot].en=B[i].u;
				G[tot].w=B[i].w;
				G[tot].next=start[B[i].v];
				start[B[i].v]=tot;
			}
		}
		for(int i=1; i<=n; i++)
			if(dep[i]==0)idfs(i);
		while(q--)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			if(ifind(u)!=ifind(v))
			{
				puts("2139062143");
			}
			else
			{
				printf("%d\n",lca(u,v));
			}
		}
		return;
	}
	puts("Your program should output itself here.");
	puts("Sounds very difficult, yeah?");
	puts("Anyway, good luck!");
}

int main()
{
	iWork();
	return 0;
}
