#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char c[N];
stack<int>s;
int vis[N],ans,l,r,cnt,ansl,ansr;
int main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    s.push(1);
    for(int i=2;i<=n;i++)
    {
        if(!s.empty()&&((c[s.top()]=='['&&c[i]==']')||(c[s.top()]=='('&&c[i]==')')))
        {
            vis[i]=vis[s.top()]=1;
            s.pop();
        }
        else s.push(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) cnt=0,l=i+1;
        else
        {
            cnt++;
            if(cnt>ans) ansl=l,ansr=i,ans=cnt;
        }
    for(int i=ansl;i<=ansr;i++) putchar(c[i]);
    puts("");
    return 0;
}