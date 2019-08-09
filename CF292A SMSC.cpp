#include<bits/stdc++.h>
using namespace std;
int N,n,t,x;
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
        N=max(N,x);
        t=a;
    }
    printf("%d %d",t+x,N);
    return 0;
}