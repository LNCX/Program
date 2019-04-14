#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int cnt,n,ch[maxn][26],nxt[maxn],bo[maxn],que[n];
void trie(char *s)
{
	int len=strlen(s);
	int u=1;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(if!ch[u][c])
		{
			ch[u][c]=++cnt;
			memset(ch[cnt],0,sizeof(ch[cnt]));	
		} 
		u=ch[u][c];
	}
	bo[u]++;
	return ;
} //make trie tree
void bfs()
{
	for(int i=0;i<=25;i++)
	ch[0][i]=1;
	que[1]=1;nxt[1]=0;
	for(int qi=1,q2=1;q1<=q2;q1++)
	{
		int u=que[q1];
		for(int i=0;i<=25;i++)
		{
			if(!ch[u][i]) ch[u][i]=ch[nxt[u]][i];
			else
			{
				que[++q2]=ch[u][i];
				int v=nxt[u];
				nxt[ch[u][i]]=ch[v][i];
			}
		}
	}
}//check itself
void find(char *s)
{
	
}//find answer
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;cnt=1;
		memset(bo,0,sizeof);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			char s[maxn];
			scanf("%s",s[i]);
			trie(s);
		}
		bfs();
		scan("%s",s);
		find(s);
		cout<<ans<<endl;
	}
	return 0;
}
