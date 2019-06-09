#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,x,b,y;
    scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
    while(1)
    {
        a++,b--;
        if(a>n) a%=n;
        if(b==0) b=n;
        if(a==b)
        {
            puts("YES");
            break;
        }
        if(a==x||b==y)
        {
            puts("NO");
            break;
        }
    }
    return 0;
}