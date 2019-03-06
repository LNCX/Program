#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=305;
int n,m,k,a[maxn];
queue<int>que[maxm],q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    while(k--)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
            int x;
            scanf("%d",&x);
            if(!que[a[x]].size())
                q.push(a[x]);
            que[a[x]].push(x);
        }
        else 
        {
            int x=q.front();
            printf("%d\n",que[x].front());
            que[x].pop();
            if(que[x].empty())q.pop();
        }
    }
    return 0;
}