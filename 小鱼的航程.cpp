#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,ans=0,x;
    cin>>x>>n;
    for(int i=0;i<n;i++)
    {
        if(x!=6&&x!=7)
            ans += 250; 
        if(x==7)x=1; 
        else x++; 
    }
    cout<<ans;
}
