#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(n%i==0)
        {
            printf("%d\n",n/i);
            for(int j=1;j<=n/i;j++)
                printf("%d ",i);
            puts("");
            return 0;
        }
    return 0;
}