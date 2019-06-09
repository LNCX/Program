#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if(x<y)
    {
        if(x+z>=y) puts("?");
        else puts("-");
    }
    else if(x>y)
    {
        if(y+z>=x) puts("?");
        else puts("+");
    }
    else
    {
        if(z!=0) puts("?");
        else puts("0");
    }
    return 0;
}