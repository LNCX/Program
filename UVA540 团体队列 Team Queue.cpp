#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int maxm=1005;
int a[N];
queue<int>que[maxm],q,e;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
int main()
{
    int t,o=0;
    while((t=read())!=0)
    {
        for(int i=1;i<=t;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=1;j<=x;j++)
                a[read()]=i;
        }
        printf("Scenario #%d\n",++o);
        while(1)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='E')
            {
                int x;
                scanf("%d",&x);
                if(!que[a[x]].size())
                    q.push(a[x]);
                que[a[x]].push(x);
            }
            else if(s[0]=='D')
            {
                int x=q.front();
                printf("%d\n",que[x].front());
                que[x].pop();
                if(que[x].empty())q.pop();
            }
            else
            {
                q=e;
                for(int i=0;i<maxm;i++)
                    que[i]=e;
                break;
            }
        }
        puts("");
    }
    return 0;
}