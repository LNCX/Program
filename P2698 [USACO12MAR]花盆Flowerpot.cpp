#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,d,ans=0x7fffffff;
struct point
{
    int x,y;
    bool operator<(const point&k) const
    {
        return x<k.x;
    }
}a[maxn];
deque<int>qmax,qmin;
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    qmax.push_back(1),qmin.push_back(1);
    for(int l=1,r=1;l<=n;l++)
    {
        while(!qmax.empty()&&qmax.front()<l) qmax.pop_front();
        while(!qmin.empty()&&qmin.front()<l) qmin.pop_front();
        while(r<n&&(a[qmax.front()].y-a[qmin.front()].y<d))
        {
            r++;
            while(!qmax.empty()&&a[qmax.back()].y<a[r].y)qmax.pop_back();qmax.push_back(r);
            while(!qmin.empty()&&a[qmin.back()].y>a[r].y)qmin.pop_back();qmin.push_back(r);
        }
        if(a[qmax.front()].y-a[qmin.front()].y>=d)
            ans=min(ans,a[r].x-a[l].x);
    }
    ans==0x7fffffff?puts("-1"):printf("%d\n",ans);
    return 0;
}