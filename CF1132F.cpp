#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
char s[maxn];
int n,f[maxn][maxn];
int main()
{
    scanf("%d %s",&n,s);
    for(int len=1;len<n;len++)
        for(int l=0;l+len<n;l++)
        {
            int r=l+len;
            f[l][r]=f[l+1][r]+1;
            for(int k=l;k<=r;k++)
                if(s[k]==s[l])
                    f[l][r]=min(f[l][r],f[l][k-1]+f[k][r]);
        }
    printf("%d\n",f[0][n-1]+1);
    return 0;
}