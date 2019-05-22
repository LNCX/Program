#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int c='a';c<='z';c++)
    {
        int l=0,r=n-1;
        while(s[l]==c)l++;
        while(s[r]==c)r--;
        if(l==0&&r==n-1) continue;
        //cerr<<l<<" "<<r<<endl;
        (ans+=((long long)(l+1)*(n-r)-1))%=mod;
        
    }
    cout<<ans+1<<endl;
    return 0;
}