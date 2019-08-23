#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int b,p,f,h,c,ans=0;
        scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
        if(h<c) swap(p,f),swap(h,c);
        ans+=h*min(b/2,p),b-=min(2*p,b);
        ans+=c*min(b/2,f),b-=min(2*f,b);
        cout<<ans<<endl;
    }
    return 0;
}
