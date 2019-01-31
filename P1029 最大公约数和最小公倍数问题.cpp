#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int gcd(int l,int r)
{
    if(r==0)return l;
    return gcd(r,l%r);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=sqrt(m*n);i++)
        if((n*m)%i==0&&gcd(i,(n*m)/i)==n)  
			ans++;
    cout<<ans*2;
}
