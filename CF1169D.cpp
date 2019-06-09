#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length(),r=n+1;
    long long ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;i+2*j<n;j++)
            if(s[i]==s[i+j]&&s[i+j]==s[i+2*j])
            {
                r=min(r,i+2*j);
                break;
            }
        ans+=max(n-r,0);
    }
    cout<<ans<<endl;
    return 0;
}