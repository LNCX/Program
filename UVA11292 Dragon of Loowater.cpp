#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int a[N],b[N];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        sort(a,a+n),sort(b,b+m);
        int cur=0,cost=0;
        for(int i=0;i<m;i++)
            if(b[i]>=a[cur])
            {
                cost+=b[i];
                if(++cur==n) break;
            }
        if(cur<n) printf("Loowater is doomed!\n");
        else printf("%d\n",cost);
    }
    return 0;
}