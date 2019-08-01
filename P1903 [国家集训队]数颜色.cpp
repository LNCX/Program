#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=1e6+5;
int n,m,Q,T,a[N];
int num,block,ans,out[N],cnt[M];
struct que
{
    int t,l,r,id;
    friend bool operator<(const que a,const que b)
    {
        if(a.l/block!=b.l/block) return a.l<b.l;
        if(a.r/block!=b.r/block) return a.r<b.r;
        return a.t<b.t;
    }
}q[N];
struct node
{
    int pos,val;
}t[N];
void add(int now){if(++cnt[a[now]]==1) ans++;}
void del(int now){if(--cnt[a[now]]==0) ans--;}
void tim(int now,int i) 
{
    if(q[i].l<=t[now].pos&&t[now].pos<=q[i].r)
    {
        if(--cnt[a[t[now].pos]]==0) ans--;
        if(++cnt[t[now].val]==1) ans++;
    }
    swap(t[now].val,a[t[now].pos]);
}
void moqueue()
{
    sort(q+1,q+1+Q);
    int l=1,r=0,now=0;
    for(int i=1;i<=Q;i++)
    {
        int ql=q[i].l,qr=q[i].r,t=q[i].t;
        while(l<ql) del(l++);
        while(l>ql) add(--l);
        while(r<qr) add(++r);
        while(r>qr) del(r--);
        while(now<t) tim(++now,i);
        while(now>t) tim(now--,i);
        out[q[i].id]=ans;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    block=pow(n,0.6666667);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        char s[10];
        int x,y;
        scanf("%s%d%d",s,&x,&y);
        if(*s=='Q') ++Q,q[Q]=(que){T,x,y,Q};
        else t[++T]=(node){x,y};
    }
    moqueue();
    for(int i=1;i<=Q;i++)
        printf("%d\n",out[i]);
    return 0;
}