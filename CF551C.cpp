#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m,a[N],b[N];
bool pan(LL x)
{
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    int pos=n;
    for(int i=1;i<=m;i++)
    {
        LL t=x;
        while(!b[pos]&&pos) pos--;
        if(!pos) return true;
        t-=pos;
        if(t<0) return false;
        while(t>=0)
        {
            if(b[pos]>t)
            {
                b[pos]-=t;
                break;
            }
            t-=b[pos];
            b[pos]=0;
            while(!b[pos]&&pos) pos--;
            if(!pos) return true;
        }
    }
    while(!b[pos]&&pos) pos--;
    return !pos;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    LL l=0,r=0x3f3f3f3f3f3f3f3f;
    while(l<r)
    {
        LL mid=(l+r)>>1;
        if(pan(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}