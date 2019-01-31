#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    if(x<t)
    {
        printf("NO\n");
        return 0;
    }
    if((!((x-t)%s)||!((x-t-1)%s))&&x!=t+1)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}