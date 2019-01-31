#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int sum=n;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        {
            sum-=sum/i;
            while(n%i==0) n/=i;
        }
    if(n>1) sum-=sum/n;
    return sum;
}
int main()
{
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<phi(i)<<" ";
    return 0;
}