#include<bits/stdc++.h>
using namespace std;
const int N=20,inf=0x7fffffff;
int n,a[N][N],b[N][N];
int check(int s)
{
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        if(s&(1<<i)) b[0][i]=1;
        else if(a[0][i]==1) return inf;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int sum=0;
            if(i>1) sum+=b[i-2][j];
            if(j>0) sum+=b[i-1][j-1];
            if(j<n-1) sum+=b[i-1][j+1];
            b[i][j]=sum%2;
            if(a[i][j]==1&&b[i][j]==0) return inf;
        }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]!=b[i][j])
                cnt++;
    return cnt;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int ans=inf;
        for(int i=0;i<(1<<n);i++)
            ans=min(check(i),ans);
        if(ans==inf) ans=-1;
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}