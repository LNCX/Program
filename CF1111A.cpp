#include<bits/stdc++.h>
using namespace std;
map<char,int>M;
int main()
{
    string s,t;
    cin>>s>>t;
    M['a']=M['e']=M['i']=M['o']=M['u']=1;
    if(s.length()!=t.length())
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(M[s[i]]!=M[t[i]])
        {
            puts("No");
            return 0;
        } 
    }
    puts("Yes");
    return 0;
}