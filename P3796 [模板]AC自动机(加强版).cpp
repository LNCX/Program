#include<bits/stdc++.h>
using namespace std;
const int N=20000;
class AC
{
    private:
        int ch[N][26]={{0}},bo[N]={0},tot=1,nxt[N]={0},cnt[N]={0},f[N]={0},e[N]={0};
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
                if(!ch[u][c])
                {
                    ch[u][c]=++tot;
                    f[ch[u][c]]=u;
                    e[ch[u][c]]=c;
                }
                u=ch[u][c];
            }
            bo[u]=1;
        }
        void find(char *s)
        {
            build();
            int res=0,u=1,n=strlen(s);
            for(int i=0;i<n;i++)
            {
                u=ch[u][s[i]-'a'];
                for(int p=u;p;p=nxt[p])
                    if(bo[p])
                    {
                        cnt[p]++;
                        if(cnt[p]>res)
                            res=cnt[p];
                    }
            }
            printf("%d\n",res);
            for(int i=1;i<=tot;i++)
            {
                if(res==cnt[i])
                {
                    vector<char>a;
                    int u=i;
                    while(u!=1)
                    {
                        a.push_back(e[u]+'a');
                        u=f[u];
                    }
                    for(int i=a.size()-1;i>=0;i--)
                        putchar(a[i]);
                    puts("");
                }
            }
        }
};
char s[1000005];
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        AC t;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            t.insert(s);
        }
        scanf("%s",s);
        t.find(s);
    }
    return 0;
}