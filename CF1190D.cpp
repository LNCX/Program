#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct point
{
    int x,y;
    bool operator<(const point k) const
    {
        if(k.x==x) return y<k.y;
        else return x<k.x;
    }
}a[N];
int n,m,ans;
vector<int>b[N];
void divide(int l,int r)
{
    map<int>ma;
    s.insert(0);
    if(l==r) {ans++;return;}
    if(l> r) return;
    int mid=(l+r)>>1;
    for(auto i:b[mid])
        s.insert(i);
    for(int i=l;i<mid;i++)
        for(int i=1;i<=n;i++)
}
int main()
{
    cin>>n;
    for(int i=1;i=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    b[++m].push_back(a[1].y);
    for(int i=2;i<=n;i++)
    {
        if(a[i].x!=a[i-1].x) m++;
        b[m].push_back(a[i].y);
    }
    divide(1,m);
    return 0;
}