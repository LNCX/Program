#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
char s[N];
int n,m,sa[N],tp[N],rk[N],tax[N],h[N],sum[N],ans1,ans2,q,k;
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
void solve()
{
    int l1=1,r1=n,l2;
    for(int i=1;i<=n;i++)
    {
        l2=l1;
        for(int j='a';j<='z';j++)
        {
            int l=l2,r=r1;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if(s[sa[mid]+i-1]>j) r=mid-1;
                else l=mid+1;
            }
            int t=sum[r]-sum[l2-1]-(r-l2+1)*(i-1);
            if(t>=k)
            {
                if(k<=r-l2+1)
                {
                    ans1=sa[l2];
                    ans2=sa[l2]+i-1;
                    return;
                }
                l1=l2,r1=r;
                k-=r-l2+1;
                break;
            }
            l2=r+1,k-=t;
        }
        if(n-sa[l1]+1==i) l1++;
    }
}
signed main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    SA();
    scanf("%d%d",&q,&k);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+n-sa[i]+1-(q?0:h[i]);   
    if(sum[n]<k) return !puts("-1");
    if(q==0)
    {
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
    }
    if(q==1) 
    {
        solve();
        for(int i=ans1;i<=ans2;i++)
            putchar(s[i]);
        puts("");
    }
    return 0;
}