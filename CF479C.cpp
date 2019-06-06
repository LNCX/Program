#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
struct node
{
    int l,r;
    bool operator<(const node &x)const
    {
        if(r!=x.r)return r<x.r;
        else return l<x.l;
    }
    bool operator==(const node &x)const
    {
        return x.l==l&&x.r==r;
    }
}a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].r,&a[i].l);
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    for(int i=n;i>1;i--)
    {
        if(a[i].l>=a[i-1].r)
            break;
        else if(a[i].l<a[i-1].l)
        {
            cout<<a[n].r<<endl;
            return 0;
        }
    }
    cout<<a[n].l<<endl;
    return 0;
}