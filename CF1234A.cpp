#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
         int n,sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        cout<<(int)ceil((double)sum/n)<<endl;
    }
    return 0;
}