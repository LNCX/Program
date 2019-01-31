#include<bits/stdc++.h>
const int maxn=1e5+5;
long long a[maxn],sum[maxn];
int n,m,k,s[maxn],l[maxn],r[maxn],x[maxn];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
        sum[i]=a[i]-a[i-1];
    for(int i=1;i<=m;i++) 
        scanf("%d%d%d",&l[i],&r[i],&x[i]);
    for(int i=1;i<=k;i++)
    {
        int l1,r1;
        scanf("%d%d",&l1,&r1);
        s[l1]++,s[r1+1]--;
    }
    for(int i=1;i<=m;i++) 
    s[i]+=s[i-1];
    for(int i=1;i<=m;i++)
    {
        sum[l[i]]+=(long long) x[i]*s[i];
        sum[r[i]+1]-=(long long) x[i]*s[i];
    } 
    for(int i=1;i<=n;i++) 
        sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++)
        printf("%I64d ",sum[i]); 
    return 0;
}
