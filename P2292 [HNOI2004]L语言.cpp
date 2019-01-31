#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+5;
char s[maxm];
bool bo[205];
int n,m,Len,ch[205][26],tot,f[maxm];
void insert(char *s)
{
    int u=0;
    int len=strlen(s);
    Len=max(len,Len);
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c]);
        ch[u][c]=++tot;
        u=ch[u][c];
    }
    bo[u]=true;
}
bool find(int l,int r)
{
    int u=1;
    for(int i=l;i<=r;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c]) return false;
        u=ch[u][c];
    }
    return bo[u];
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    while(n--)
    {
        scanf("%s",s);
        insert(s);
    }
    while(m--)
    {
        scanf("%s",s);
        memset(f,0,sizeof(f));
        int len=strlen(s),ans=0;
        for(int i=0;i<len;i++)
            for(int j=max(i-Len,-1);j<=i;j++)
                if((j==-1||f[j])&&find(j+1,i))
                    {f[i]=1;ans=i+1;break;}
        printf("%d\n",ans);
    }
    return 0;
}