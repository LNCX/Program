#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char s[N];
int n,m,rk[N],sa[N],tp[N],tax[N];
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
        swap(rk,tp);
        rk[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
            rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
    }
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    SA();
    for(int i=1;i<=n;i++)
        printf("%d ",sa[i]);
    puts("");
    return 0;
}