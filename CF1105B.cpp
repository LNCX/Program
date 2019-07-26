#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5 ;
int m[N];
bool vis[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(vis[i]) continue;
        bool flag=true;
        for(int j=1;j<k;j++)
            if(s[j+i]!=s[i])
            {
                flag=false;
                i=j+i-1;
                break;
            }
        if(flag==true)
        {
            for(int j=0;j<k;j++)
                vis[i+j]=1;
            m[s[i]-'a']++;
        }
    }
    int ans=0;
    for(int i=0;i<26;i++)
        ans=max(m[i],ans);
    cout<<ans<<endl;
    return 0;  
}