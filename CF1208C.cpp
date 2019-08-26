#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N][N],cnt;
int main()
{
    int n;
    scanf("%d",&n);
    for(int k=1;k<=n;k+=4)
        for(int l=1;l<=n;l+=4)
            for(int i=k;i<=k+3;i++)
            {
                for(int j=l;j<=l+3&&i%2;j++)
                    a[i][j]=cnt++;
                for(int j=l+3;j>=l&&!(i%2);j--)
                    a[i][j]=cnt++;
            }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]),ans^=a[i][j];
        puts("");
    }
    return 0;
}