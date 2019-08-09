#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[N];
int main()
{
    int n,cnt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;b[y]++;
    }
    for(int i=1;i<N;i++)
    {
        if(!cnt&&a[i]) 
            printf("%d ",i);
        cnt+=a[i]-b[i];
        if(!cnt&&b[i]) 
            printf("%d\n",i);
    }
}