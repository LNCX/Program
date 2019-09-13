#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum,d=-inf,d2=-inf;
        scanf("%d%d",&n,&sum);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            d=max(d,x-y),d2=max(d2,x);
        }
        if(d<=0&&d2<sum) puts("-1");
        else if(d==0&&d2>=sum) puts("1");
        else
        {   
            sum-=d2;
            if(sum<=0)
            {
                puts("1");
                continue;
            }
            else printf("%d\n",(int)ceil((double)sum/d)+1);
        }
    }
    return 0;
}