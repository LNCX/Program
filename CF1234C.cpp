#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[2][N],n;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=0;i<=1;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%1d",&a[i][j]);
                if(a[i][j]>2) a[i][j]=1;
                else a[i][j]=0;
            }
        bool flag=true;
        int i=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]&&a[i^1][j]) i^=1;
            else if(a[i][j]){flag=false;break;}
        }
        if(i==0) flag=false;
        flag?puts("YES"):puts("NO");
    }
    return 0;
}