#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node
{
    int a,b;
    friend bool operator<(const node &x,const node &y)
    {
        if(x.b>=0&&y.b>=0) return x.a<y.a;
        if(x.b<0&&y.b<0) return max(x.a,-x.b)+x.b>max(y.a,-y.b)+y.b;
        return x.b>=0;
    }
}p[N];
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].a,&p[i].b);
    sort(p+1,p+1+n);
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(r<p[i].a) flag=false;
        r+=p[i].b;
        if(r<0) flag=false;
    }
    flag?puts("YES"):puts("NO");
    return 0;
}
