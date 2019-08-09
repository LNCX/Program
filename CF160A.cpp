#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main()
{
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    int cnt=0,sum1=0;
    for(int i=n;i>=1;i--)
    {
        sum1+=a[i];
        cnt++;
        if(sum1>sum-sum1)break;
    }
    cout<<cnt<<endl;
    return 0;
}