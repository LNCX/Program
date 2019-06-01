#include<bits/stdc++.h>
const int maxn=5e5+5;
using namespace std;
queue<int>q;
char s[maxn<<1];
int c[maxn][26],val[maxn],fail[maxn],cnt;
void ins(char *s)
{
	int len=strlen(s);int now=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		if(!c[now][v])c[now][v]=++cnt;
		now=c[now][v];
	}
	val[now]++;
}
void build()
{
	for(int i=0;i<26;i++)if(c[0][i])fail[c[0][i]]=0,q.push(c[0][i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<26;i++)
		if(c[u][i])fail[c[u][i]]=c[fail[u]][i],q.push(c[u][i]);
		else c[u][i]=c[fail[u]][i];
	}
}
int query(char *s)
{
	int len=strlen(s);int now=0,ans=0;
	for(int i=0;i<len;i++)
	{
		now=c[now][s[i]-'a'];
		for(int t=now;t&&~val[t];t=fail[t])ans+=val[t],val[t]=-1;
	}
	return ans;
}
int main()
{
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%s",s),ins(s);
    build();
    scanf("%s",s);
    printf("%d\n",query(s));
    return 0;
}