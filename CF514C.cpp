#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
char s[N];
bool bo[205];
int n,m,tot,ch[205][3];
void insert(char *s)
{
    int u=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c])ch[u][c]=++tot;
        u=ch[u][c];
    }
    bo[u]=true;
}
void dfs()
{
    
}
int main()
{
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%s",s);
        insert(s);
    }
    while(m--)
    {
        scanf("%s",s);
        
        printf("%d\n",ans);
    }
    return 0;
}