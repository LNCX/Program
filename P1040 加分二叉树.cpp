#include<bits/stdc++.h>
using namespace std;
const int N=35;
int num[N],f[N][N];
void print(int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        printf("%d ",l);
        return ;
    }
    for(int k=l;k<=r;k++)
        if(f[l][k-1]*f[k+1][r]+num[k]==f[l][r])
        {
            printf("%d ",k);
            print(l,k-1);
            print(k+1,r);
            return;
        }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        f[i+1][i]=1;
        f[i][i]=num[i];
    }
    f[1][0]=1;
    for(int len=1;len<=n;len++)
        for(int l=1;l+len<=n;l++)
            for(int k=l;k<=l+len;k++)
                f[l][l+len]=max(f[l][l+len],f[l][k-1]*f[k+1][l+len]+num[k]);
    cout<<f[1][n]<<endl;
    print(1,n);
    return 0;
}