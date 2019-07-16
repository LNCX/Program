#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct point 
{
    int x,y;
    bool operator<(const point k)const
    {
        if(x!=k.x) return x<k.x;
        else return y<k.y;
    }
}a[N];
int ans=0;
void divide(int l,int r)
{
    if(l>r) return;
    if(l==r) ans++;
    int mid=(l+r)>>1;
    {
        
    }
    divide(mid+1,r);
    divide(l,mid-1);
}
int main()
{
    int  n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    divide(1,n);
    return 0;
}