#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n;
    scanf("%d%d%d%d",&a,&b,&c,&n);
    if(a+b-c>=n||(c>a)||(c>b)) puts("-1");
    else printf("%d\n",n-(a+b-c));
    return 0;
}