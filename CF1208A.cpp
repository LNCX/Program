#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[4],n;
        scanf("%d%d%d",&a[0],&a[1],&n);
        a[2]=a[0]^a[1];
        printf("%d\n",a[n%3]);
    }
    return 0;
}