#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if('A'<=c&&c<='Z') c=c-'A'+'a';
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y') continue;
        else printf(".%c",c);
    }
    return 0;
}