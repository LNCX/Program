#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
class AC_automaton
{
    private:
        int ch[N][26],bo[N],tot=1,nxt[N];
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
                        q.push(ch[u][c]);
                        nxt[ch[u][c]]=ch[nxt[u]][c];
                    }
                }
            }
        }
    public:
        void insert(char *s)
        {
            int n=strlen(s),u=1;
            for(int i=0;i<n;i++)
            {
                int c=s[i]-'a';
                if(!ch[u][c]) ch[u][c]=++tot;
                u=ch[u][c];
            }
            bo[u]++;
        }
        int find(char *s)
        {
            build();
            int res=0,u=1,n=strlen(s);
            for(int i=0;i<n;i++)
            {
                u=ch[u][s[i]-'a'];
                for(int t=u;t&&~bo[t];t=nxt[t])
					res+=bo[t],bo[t]=-1;
            }
            return res;
        }
}t;
char s[N];
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
    printf("%d\n",t.find(s));
    return 0;
}