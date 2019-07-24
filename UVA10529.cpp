#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
double pl,pr,f[N];
double dp(int i,int j)
{
    return f[j]+f[i-j-1]+(1+pl*f[j]+pr*f[i-j-1])/(1-pl-pr);
}
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(!n) break;
        scanf("%lf%lf",&pl,&pr);
        for(int i=1,j=0;i<=n;i++)
        {
            while(j<i-1&&dp(i,j)>dp(i,j+1))
                j++;
            f[i]=dp(i,j);
        }
        printf("%.2f\n",f[n]);
    }
    return 0;
}