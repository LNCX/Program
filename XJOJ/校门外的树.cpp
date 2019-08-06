#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,num,a[N],blg[N],L[N],R[N],tag[N],ans;
void build()
{
    int t=sqrt(n);
    num=n/t;
    if(n%t) num++;
    for(int i=1;i<=n;i++)
        blg[i]=(i-1)/t+1;
    for(int i=1;i<=num;i++)
        L[i]=t*(i-1)+1,R[i]=i*t;
    R[num]=n;
}
void update(int l,int r)
{
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++) 
            a[i]=0;
        return;
    }
    
    for(int i=l;i<=R[blg[i]];i++) a[i]=0;
    for(int i=L[blg[r]];i<=r;i++) a[i]=0;
    for(int i=blg[l]+1;i<blg[r];i++) tag[i]=0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) tag[i]=a[i]=1;
    build();
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        update(l,r);
    }
    for(int i=1;i<=n;i++)
        if(tag[blg[i]]&&a[i])
            ans++;
    printf("%d\n",ans);
    return 0;
}