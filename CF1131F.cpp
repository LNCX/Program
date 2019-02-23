#include<bits/stdc++.h>
const int N=150001;
int n,g[N],p[N],r[N];
int find(int k){return k==p[k]?k:p[k]=find(p[k]);}
int main()
{
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)p[i]=i,r[i]=i;
	for(int i=1;i<n;i++)
	{
        scanf("%d%d",&x,&y),
	    x=find(p[x]),y=find(p[y]),
	    g[r[x]]=y,r[x]=r[y],p[y]=x;
    }
	for(int i=find(1);i;i=g[i])printf("%d ",i);
	return 0;
}