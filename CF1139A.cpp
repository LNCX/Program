#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        int x=s[i]-'0';
        if(x%2==0) ans+=i+1;
    }
    cout<<ans<<endl;
    return 0;
}