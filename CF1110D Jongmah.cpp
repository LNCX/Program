#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,a[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    puts("0");
    sort(a+1,a+1+n);
    #ifdef DEBUG 
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
    #endif
    
    return 0;
}