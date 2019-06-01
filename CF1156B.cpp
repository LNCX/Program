#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,s1,s2;
        cin>>s;
        sort(s.begin(),s.end());
        for(int i=0;i<s.length();i++)
            if(s[i]&1) s1+=s[i];
            else s2+=s[i];
        if(s1.empty()||s2.empty()) cout<<s1+s2<<endl;
        else if(abs(s1.back()-s2[0])!=1) cout<<s1+s2<<endl;
        else if(abs(s2.back()-s1[0])!=1) cout<<s2+s1<<endl;
        else puts("No answer");
    }
    return 0;
}