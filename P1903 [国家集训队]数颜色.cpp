#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2*1e6+10;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}
    return x*f;
}
int N,M;
int a[MAXN],where[MAXN];
struct Query
{
    int x,y,pre,id;
}Q[MAXN];
int Qnum=0;
struct Change
{
    int pos,val;
}C[MAXN];
int Cnum=0;
int color[MAXN],ans=0,base,out[MAXN];
int comp(const Query &a,const Query &b)
{
    if(a.x!=b.x) return where[a.x]<where[b.x];
    if(a.y!=b.y) return where[a.y]<where[b.y];
    return a.pre<b.pre;
}
void Add(int val)
{    
    if(++color[val]==1) ans++;
} 
void Delet(int val)
{
    if(--color[val]==0) ans--;
}
void Work(int now,int i)
{
    if(C[now].pos>=Q[i].x&&C[now].pos<=Q[i].y)
    {
        if( --color[a[C[now].pos]] == 0 ) ans--;
        if( ++color[C[now].val] == 1)      ans++; 
    }
    swap(C[now].val,a[C[now].pos]);
}
void MoQueue()
{
    int l=1,r=0,now=0; 
    for(int i=1;i<=Qnum;i++)
    {
        while(l<Q[i].x)    Delet(a[l++]);
        while(l>Q[i].x) Add(a[--l]);
        while(r<Q[i].y) Add(a[++r]);
        while(r>Q[i].y) Delet(a[r--]);
        while(now<Q[i].pre) Work(++now,i);
        while(now>Q[i].pre) Work(now--,i);
        out[Q[i].id]=ans;
    }
    for(int i=1;i<=Qnum;i++)
        printf("%d\n",out[i]);
}
int main()
{
    N=read();M=read();
    base=sqrt(N);
    for(int i=1;i<=N;i++) a[i]=read(),where[i]=(i-1)/base+1;
    while(M--)
    {
        char opt[5];
        scanf("%s",opt);
        if(opt[0]=='Q')
        {
            Q[++Qnum].x=read();
            Q[Qnum].y=read();
            Q[Qnum].pre=Cnum;
            Q[Qnum].id=Qnum;        
        }
        else if(opt[0]=='R')
        {
            C[++Cnum].pos=read();
            C[Cnum].val=read();
        }
    }
    sort(Q+1,Q+Qnum+1,comp);
    MoQueue();
    return 0;
}