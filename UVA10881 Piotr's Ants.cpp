#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct ant
{
    int rnk;
    int loc;
    char to;
    bool operator<(const ant &x) const {return loc<x.loc;}
}a[N];
int rev[N];
int main()
{
    int T;
    cin>>T;
    for(int o=1;o<=T;o++)
    {
        int l,t,n;
        scanf("%d%d%d",&l,&t,&n);
        for(int i=1;i<=n;i++)
        {
            a[i].rnk=i;
            scanf("%d %c",&a[i].loc,&a[i].to);
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            rev[a[i].rnk]=i;
        for(int i=1;i<=n;i++)
            if(a[i].to=='L') a[i].loc-=t;
            else a[i].loc+=t;
        sort(a+1,a+1+n);
        printf("Case #%d:\n",o);
        for(int i=1;i<=n;i++)
        {
            int to=rev[i];
            if(a[to].loc<0||a[to].loc>l)
                puts("Fell off");
            else if(a[to].loc==a[to+1].loc||a[to].loc==a[to-1].loc)
                printf("%d Turning\n",a[to].loc);
            else
                printf("%d %c\n",a[to].loc,a[to].to);
        }
        printf("\n");
    }
    return 0;
}