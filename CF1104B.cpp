#include<bits/stdc++.h>
using namespace std;
string s;
stack<char>q;
int ans;
int main()
{
    cin>>s;
    q.push(' ');
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==q.top())
        {
            q.pop();ans++;
            continue;
        }
        else q.push(s[i]);
    }
    ans%2==0?puts("No"):puts("Yes");
}