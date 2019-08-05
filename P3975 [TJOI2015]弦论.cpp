#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char s[N];
int n,m,sa[N],tp[N],rk[N],tax[N],h[N],sum[N];
void sort()
{
    for(int i=0;i<=m;i++) tax[i]=0;
    for(int i=1;i<=n;i++) tax[rk[i]]++;
    for(int i=1;i<=m;i++) tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--) sa[tax[rk[tp[i]]]--]=tp[i];
}
void SA()
{
    for(int i=1;i<=n;i++)
        m=max(m,rk[i]=s[i]-'0'),tp[i]=i;
    sort();
    for(int w=1,p=0;p<n;w<<=1,m=p)
    {
        p=0;
        for(int i=1;i<=w;i++) tp[++p]=n-w+i;
        for(int i=1;i<=n;i++) if(sa[i]>w) tp[++p]=sa[i]-w;
        sort();
        swap(tp,rk);
        rk[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
            rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        h[rk[i]]=k;
    }
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    SA();
    int q,k;
    scanf("%d%d",&q,&k);
    for(int i=1;i<=n;i++)
        cerr<<(sum[i]=sum[i-1]+n-sa[i]+1-(q?0:h[i]))<<endl;   
    if(sum[n]<k) return !puts("-1");
    int l=1,r=n,x;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(k<=sum[mid])x=mid,r=mid-1;
        else l=mid+1;
    }
    for(int i=sa[x];i<=n-sum[x]+k;i++)
        printf("%c",s[i]);
    puts("");
    return 0;
}