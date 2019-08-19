#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    int n ;
    scanf("%d",&n);
    if(n%2==0) return puts("NO"),0;
    for(int i=1;i<=n;i++)
    {
        a[i]=2*i-1,a[i+n]=2*i;
        if(i%2==0) swap(a[i],a[i+n]);
    }
    puts("YES");
    for(int i=1;i<=2*n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}