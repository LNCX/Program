#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+2*n);
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
        sum1+=a[i],sum2+=a[i+n];
    if(sum1==sum2)
        puts("-1");
    else 
        for(int i=1;i<=2*n;i++) 
            printf("%d ",a[i]);
    return 0;
}