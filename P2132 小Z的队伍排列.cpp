#include <cstdio>
const int S=30;
int n,a[S];
unsigned f[S][S][S][S][S];
inline int dfs(int i,int j,int k,int l,int p)
{
    if (i+j+k+l+p==0) return 1;
    unsigned &tp=f[i][j][k][l][p];
    if(tp) return tp;
    if(i>j) tp+=dfs(i-1,j,k,l,p);
    if(j>k) tp+=dfs(i,j-1,k,l,p);
    if(k>l) tp+=dfs(i,j,k-1,l,p);
    if(l>p) tp+=dfs(i,j,k,l-1,p);
    if(p) tp+=dfs(i,j,k,l,p-1);
    return tp;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    printf("%u\n",dfs(a[0],a[1],a[2],a[3],a[4]));
    return 0;
}