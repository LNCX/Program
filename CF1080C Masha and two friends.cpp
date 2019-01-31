#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f1(int x1,int y1,int x2,int y2)
{
    bool opt=(x1+y1)&1;
    int n=x2-x1+1,m=y2-y1+1;
    if(opt) return 1LL*n*(m/2)+((m&1)?(n/2)+(n&1):0);
    else return 1LL*n*(m/2)+((m&1)?(n/2):0);
}
LL f2(int x1,int y1,int x2,int y2)
{
    return 1LL*(x2-x1+1)*(y2-y1+1)-f1(x1,y1,x2,y2);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d",&n,&m),n^=m^=n^=m;
        LL s1=f2(1,1,n,m);
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        int u=max(x1,x3),d=min(x2,x4);
        int l=max(y1,y3),r=min(y2,y4);
        if(u<=d&&l<=r) 
            s1+=f1(x1,y1,x2,y2)-f1(u,l,d,r)-f2(x3,y3,x4,y4);
        else 
            s1+=f1(x1,y1,x2,y2)-f2(x3,y3,x4,y4);
        printf("%lld %lld\n",s1,1LL*n*m-s1);
    }
    return 0;
}
