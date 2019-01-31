#include<bits/stdc++.h>
using namespace std;
int maxn,n,t,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b); 
        x-=a-t;
        if(x<0) x=0;
        x+=b;
        maxn=max(maxn,x);
        t=a;
    }
    printf("%d %d",t+x,maxn);
    return 0;
}