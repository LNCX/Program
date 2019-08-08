#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
struct point
{
    int x,y,z,id;
}a[N];
int cmp(const point& p,const point& q)
{
    if(p.x==q.x&&p.z==q.z)return p.y<q.y;
    if(p.x==q.x)return p.z<q.z;
    return p.x<q.x;
}
int cmp1(const point& p,const point& q){return p.z<q.z;}
int ans[N],c[N];
void add(int x,int y){while(x<=100000){c[x]+=y;x+=x&(-x);}}
int ask(int x){int tot=0;while(x){tot+=c[x];x-=x&(-x);}return tot;}
void CDQ(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    CDQ(l,mid);CDQ(mid+1,r);
    sort(a+l,a+mid+1,cmp1);
    sort(a+mid+1,a+r+1,cmp1);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        while(j<=mid&&a[j].z<=a[i].z)add(a[j++].y,1);
        ans[a[i].id]+=ask(a[i].y);
    }
    for(int i=l;i<j;i++)
        add(a[i].y,-1);
}
int main()
{
    memset(c,0,sizeof c);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        for(int i=1;i<=n;i++)
            a[i].id=i,ans[i]=0;
        sort(a+1,a+n+1,cmp);
        int cnt=0;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y&&a[i].z==a[i+1].z)cnt++;
            else cnt=0;
            ans[a[i].id]+=cnt;
        }
        CDQ(1,n);
        for(int i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}