#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a+c<=b) puts("0");
        else
        {
            int x=ceil((b+c-a+1.0)/2.0);
            if(x<0) x=0;
            printf("%d\n",c-x+1);
        }
    }
    return 0;
}