#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],b[N],ans,id[N];
int get(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(x>=a[id[i]]&&x+b[id[i]]>=0)
            x+=b[id[i]],cnt++;
        else break;
    }
    return -cnt;
}
void SA()
{
    double T=2000,delta=0.998;
    int now=ans;
    while(T>1e-14)
    {
		int x=rand()%n+1,y=rand()%n+1;
		swap(a[id[x]],a[id[y]]),swap(b[id[x]],b[id[y]]);
        int sum=get(m),d=sum-now;
        if(d<0) now=sum;
        else
		{
			if(exp(-d/T)*RAND_MAX>rand()) now=sum;
			else swap(a[id[x]],a[id[y]]),swap(b[id[x]],b[id[y]]);
		}
        if(ans>now) ans=now; 
        T*=delta;
    }
}
void solve()
{
    ans=get(m);
    while((double)clock()/CLOCKS_PER_SEC<1.95)
		srand(rand()),SA();
}
int main()
{
    srand((unsigned)time(NULL)),srand(rand());
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]),id[i]=i;
    for(int i=1;i<=50;i++)
        random_shuffle(id+1,id+1+n);
    solve();
    printf("%d\n",-ans);
    return 0;
}