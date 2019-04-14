#include<bits/stdc++.h>
using namespace std;
int f[10010];
inline int find(int x)
{
    if(x==f[x]) return x;
	return f[x]=find(f[x]); 
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if(z==1) 
			f[find(x)]=find(y);
        else if(find(x)==find(y))
            printf("Y\n");
        else
            printf("N\n");
    }
}
