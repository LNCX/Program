#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a!=d) puts("0");
    else
    {
        if(c!=0&&a==0) puts("0");
        else puts("1");
    }
    return 0;
}
