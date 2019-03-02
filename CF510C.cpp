#include<bits/stdc++.h>
using namespace std;
string a,b;
queue<int>que;
vector<int>g[26];
int in[26],ans[26],n,tot;
void tuopu()
{
    for(int i=0;i<26;i++)
        if(!in[i])
            que.push(i);
    while(!que.empty())
    {
        int x=que.front();
        ans[tot++]=x;
        que.pop();
        for(int i=0;i<g[x].size();i++)
        {
            if(in[g[x][i]] == 1)
                que.push(g[x][i]);
            if(in[g[x][i]] != 0)
                in[g[x][i]]--;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int len=min(a.length(),b.length());
        bool flag=false;
        for(int j=0;j<len;j++)
            if(a[j]!=b[j])
            {
                flag=true;
                g[b[j]-'a'].push_back(a[j]-'a');
                in[a[j]-'a']++;
                break;
            }
        if(!flag&&a.length()<b.length())
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        b=a;
    }
    tuopu();
    if(tot!=26)
    {
        puts("Impossible");
        return 0;
    }
    for(int i=0;i<26;i++)
        cout<<char('a'+ ans[i]);
    puts("");
    return 0;
}