#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
string s,t;
int mt()
{
    bool f=true; 
    int ky=0,x=0;
    for(int k=(int)s.size()-1;k>=0;k--)
    {
        for(int kx=k;kx<(int)s.size();kx++)
            if(s[kx]!=t[ky++])
            {
                f=false;
                break;
            }
        if(f==true)
            x=s.size()-k;        
        ky=0;
        f=true;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        for(int i=mt();i<(int)t.size();i++)
            s+=t[i];
    }
    cout<<s<<endl;
    return 0;
}