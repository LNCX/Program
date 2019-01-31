#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,cnt;
int main()
{
    cin>>n;
    string t,b="1";
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t=="0") return puts("0");
        while(t[t.size()-1]=='0') cnt++,t=t.substr(0,t.size()-1);
        if(b=="1") b=t;
    }
    cout<<b;
    while(cnt--) cout<<"0";
    cout<<endl;
    return 0;
}