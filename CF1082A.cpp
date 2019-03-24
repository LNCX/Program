# include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n,x,y,d;
        scanf("%d%d%d%d",&n,&x,&y,&d);
        int ans=0x7fffffff;
        if(abs(x-y)%d==0)
            ans=(abs(x-y)/d);
        if((y-1)%d==0)
            ans=min(ans,(x-1)/d+bool((x-1)%d)+(y-1)/d);
        if((n-y)%d==0)
            ans=min(ans,(n-x)/d+bool((n-x)%d)+(n-y)/d);
        if(ans==0x7fffffff) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}