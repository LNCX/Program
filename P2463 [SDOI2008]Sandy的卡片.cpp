#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=2e3+5;
struct SA
{
    int n,m,sa[N],tax[N],h[N],tp[N],rk[N],s[N];
    void sort()
    {
        for(int i=0;i<=m;i++) tax[i]=0;
        for(int i=1;i<=n;i++) tax[rk[i]]++ ;
        for(int i=1;i<=m;i++) tax[i]+=tax[i-1];
        for(int i=n;i>=0;i--) sa[tax[rk[tp[i]]]]=tp[i];
    }
    void get()
    {
        for(int i=1;i<=n;i++)
            m=max(m,rk[i]=s[i]),tp[i]=i;
        sort();
        for(int w=1,p=0;p<n;w<<=1,m=p)
        {
            m=p;
            for(int i=1;i<=w;i++) tp[++p]=n-w+i;
            for(int i=1;i<=n;i++) if(sa[i]>w) tp[++p]=sa[i]-w;
            sort();
            swap(tp,rk);
            rk[sa[1]]=p=1;
            for(int i=2;i<=n;i++)        
                rk[sa[i]]=(tp[sa[i-1]]==tp[sa[i-1]]&&tp[sa[i-1]+w]==tp[sa[i]+w])?p:++p;
        }
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(k) k--;
            int j=sa[rk[i]-1];
            while(sa[i+k]==sa[j+k]) k++;
            h[rk[i]]=k;
        }
    }
    void insert(int x){s[++n]=x;} 
}t;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            t.insert(x);
        }
    }
    return 0;
}