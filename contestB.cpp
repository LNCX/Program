#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=1e7+5;
struct node
{
    int a,c,n;
    bool operator <(const node &x) const
    {
        return c>x.c;
    }
}a[maxn];
priority_queue<node>q;
int main( )
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].a);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].c);
        a[i].n=i;
        q.push(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int d,t,sum=0;
        scanf("%d%d",&d,&t);
        if(t<=a[d].a)
        {
            a[d].a-=t;
            if(a[d].a==0) n--;
            printf("%d\n",a[d].c*t);
        }
        else
        {
            sum+=a[d].c*a[d].a;
            t-=a[d].a,a[d].a=0;n--;
            node x;
            while(t)
            {
                if(!n) break;
                x=q.top();
                q.pop();
                if(a[x.n].a==0) continue;
                if(a[x.n].a>=t)
                {
                    sum+=t*a[x.n].c;
                    a[x.n].a-=t;t=0;
                    if(a[x.n].a==0) n--;
                    else q.push(a[x.n]);
                }
                if(a[x.n].a<t)
                {
                    sum+=a[x.n].a*a[x.n].c;
                    t-=a[x.n].a;a[x.n].a=0;n--;
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}