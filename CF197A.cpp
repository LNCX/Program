#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r;
    scanf("%d%d%d",&a,&b,&r);
    int x=a/(2*r),y=b/(2*r);
    if(x==0||y==0) puts("Second");
    else puts("First");
    return 0;
}