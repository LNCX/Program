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
    if(n==1){printf("0\n");return 0;}
    for(int i=2;i<=n-1;i++) ans+=phi(i);
    cout<<ans*2+3<<endl;
    return 0;
}