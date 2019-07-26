#include<bits/stdc++.h>
using namespace std;
const int N=105;
int main()
{
    int q,n;
    scanf("%d%d",&q,&n);
    if(q==1)
    {
        double ans=0;
        for(int i=2;i<=n;i++)
            ans+=(double)2/i;
        printf("%.6f",ans);
    }
    else
    {
        ;
    }
	return 0;
}     