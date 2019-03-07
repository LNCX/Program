#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string p;
        stack<char>s;
        cin>>p;
        bool flag=1;
        if(p.length()%2) flag=0;
        for(int i=0;i<p.length()&&flag;i++)
        {
            if(p[i]=='('||p[i]=='[')
                s.push(p[i]);
            else if(s.size() && (p[i]==')'&&s.top()=='(') || (p[i]==']'&&s.top()=='[') )
                s.pop();
            else flag=0;
        }
        (flag&&s.empty())?puts("YES"):puts("NO");
    }
    return 0;
}