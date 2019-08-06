#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e6+5;
char s[M];
class AC
{
    private:
        int ch[N][26],tot=1,num=0,nxt[N],cnt[N],bo[N],ans[N],vis[N],a[N],in[N];
        void build()
        {
            queue<int>q;
            for(int i=0;i<26;i++)
                ch[0][i]=1;
            q.push(1);
            while(!q.empty())
            {
                int u=q.front();q.pop();
                for(int c=0;c<26;c++)
                {
                    if(!ch[u][c]) ch[u][c]=ch[nxt[u]][c];
                    else
                    {
                        nxt[ch[u][c]]=ch[nxt[u]][c];
                        in[ch[nxt[u]][c]]++;
                        q.push(ch[u][c]);    
                    }
                }
            }        
        }
    public:
        void insert(char *s)
        {
            num++;
            int u=1,n=strlen(s);
            for(int i=0;i<n;i++)
            {
                int c=s[i]-'a';
                if(!ch[u][c]) ch[u][c]=++tot;
                u=ch[u][c];
            }
            if(!bo[u]) bo[u]=num;
            a[num]=bo[u];
        }
        void find(char *s)
        {
            build();
            int u=1,n=strlen(s);
            for(int i=0;i<n;i++)
            {
                u=ch[u][s[i]-'a'];
                ans[u]++;
            }
        }
        void print()
        {
            queue<int>q;
            for(int i=1;i<=tot;i++)
                if(in[i]==0) q.push(i);
            while(!q.empty())
            {
                int u=q.front();q.pop();
                vis[bo[u]]=ans[u];
                int v=nxt[u];in[v]--;
                ans[v]+=ans[u];
                if(in[v]==0) q.push(v);
            }
            for(int i=1;i<=num;i++)
                printf("%d\n",vis[a[i]]);
        }
}t;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        t.insert(s);
    }
    scanf("%s",s);
    t.find(s);
    t.print();
    return 0;
}