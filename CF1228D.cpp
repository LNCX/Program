#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
vector<int>e[N];
map<vector<int>,int>ma;
int main()
{
    int n,m,tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
    {
        int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++) 
    {
		if(!e[i].size()||tot>3)
        {
            printf("-1");
            return 0;
        }
		sort(e[i].begin(),e[i].end());
		if(!ma[e[i]]) ma[e[i]]=++tot;
	}
	if(tot!=3) printf("-1"); 
	else for(int i=1;i<=n;i++) printf("%d ",ma[e[i]]);
	return 0;
}