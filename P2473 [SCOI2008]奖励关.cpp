#include<bits/stdc++.h>
using namespace std;
const int N=105,M=16;
int p[M],in[M];
double f[N][1<<M];
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        int x;
        while(scanf("%d",&x)&&x!=0)
            in[i]|=(1<<(x-1));
    }
    for(int i=k;i>=1;i--)
        for(int s=0;s<=(1<<n)-1;s++)
        {
            for(int j=1;j<=n;j++)
            {
                if((in[j]&s)==in[j])
                    f[i][s]+=max(f[i+1][s],f[i+1][s|(1<<(j-1))]+p[j]);
                else f[i][s]+=f[i+1][s];
            }
            f[i][s]/=n;
        }
    printf("%.6lf",f[1][0]);
	return 0;
}