#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        scanf("%d%d",&n,&m);
        for(int i=n;i<=m;i++)
        {
            bool flag=true;
            for(int j=2;j*j<=i;j++)
                if(!(i%j))
                {
                    flag=false;
                    break;
                }
            if(flag&&i!=1) printf("%d\n",i);
        }
        puts(" ");
    }
    return 0;
}