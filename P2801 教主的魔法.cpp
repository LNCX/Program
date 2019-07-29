#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,t,a[N],b[N],num;
int blg[N],tag[N],L[N],R[N];
void build()
{
    t=sqrt(n);
    num=n/t;
    if(n%t) num++;
    for(int i=1;i<=n;i++)
        blg[i]=(i-1)/t+1,b[i]=a[i];
    for(int i=1;i<=num;i++)
        L[i]=(i-1)*t+1,R[i]=i*t;
    R[num]=n;
    for(int i=1;i<=num;i++)
        sort(b+L[i],b+R[i]+1);
}
void reset(int x)
{
    for(int i=L[blg[x]];i<=R[blg[x]];i++) b[i]=a[i];
    sort(b+L[blg[x]],b+R[blg[x]]+1);
}
void add(int l,int r,int w)
{
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++)
            a[i]+=w;
        reset(l);
        return ;    
    }
    for(int i=l;i<=R[blg[l]];i++)a[i]+=w; reset(l);
    for(int i=L[blg[r]];i<=r;i++)a[i]+=w; reset(r);
    for(int i=blg[l]+1;i<blg[r];i++)tag[i]+=w;
}
int ask(int l,int r,int w)
{
    int res=0;
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++)
            if(a[i]+tag[blg[l]]>=w) 
                res++;
        return res;
    }
    for(int i=l;i<=R[blg[l]];i++) if(a[i]+tag[blg[i]]>=w) res++;
    for(int i=L[blg[r]];i<=r;i++) if(a[i]+tag[blg[i]]>=w) res++;
    for(int i=blg[l]+1;i<blg[r];i++) 
        if(b[R[i]]+tag[i]>=w)
            res+=b+R[i]+1-lower_bound(b+L[i],b+R[i]+1,w-tag[i]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build();
    while(q--)
    {
        char s[10];
        int l,r,w;
        scanf("%s%d%d%d",s,&l,&r,&w);
        if(*s=='M') add(l,r,w);
        else printf("%d\n",ask(l,r,w));
    }
}