#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int a[4];
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    sort(a,a+4);
    printf("%d %d %d\n",a[3]-a[0],a[3]-a[1],a[3]-a[2]);
    return 0;
}