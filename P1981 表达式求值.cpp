#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,ans=0,cj,sg;
    char ch=0,xg;
    bool tf=true;
    while(tf)
    {
        scanf("%lld",&a);
        tf=scanf("%c",&xg)==1?true:false;
        if(ch==0)cj=a;
        if(ch=='+')ans=(ans+cj)%10000,cj=a;
        if(ch=='*')cj=(cj*a)%10000;
        if(!tf)ans=(ans+cj)%10000;
        ch=xg;
    }
    printf("%lld",ans);
    return 0;
}