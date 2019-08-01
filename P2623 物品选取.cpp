#include<bits/stdc++.h>
#define cal(x) (a*x*x-b*x)
using namespace std;
const int N=105,M=2e3+5;
int f[M];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int op,a,b,c;
        scanf("%d%d%d",&op,&a,&b);
        if(op==1)
        {
            for(int j=m;j>=0;j--)
                for(int x=1;x<=j;x++)
                    f[j]=max(f[j],f[j-x]+cal(x));
        }
        if(op==2)
        {
            scanf("%d",&c);
            for(int j=m;j>=0;j--)
                for(int cnt=1;j-cnt*b>=0&&cnt<=c;cnt++)
                    f[j]=max(f[j],f[j-b*cnt]+a*cnt);
        }
        if(op==3)
        {
            for(int j=b;j<=m;j++)
                f[j]=max(f[j],f[j-b]+a);  
        }
    }
    printf("%d\n",f[m]);
    return 0;
}