#include<bits/stdc++.h>
using namespace std;
int cnt[30];
long long ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        cnt[s[0]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        long long x=cnt[i]/2,y=cnt[i]/2+cnt[i]%2;
        ans+=x*(x-1)/2+y*(y-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}