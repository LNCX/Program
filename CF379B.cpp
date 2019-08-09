#include<bits/stdc++.h>
using namespace std;
const int N=305;
int a[N],sum;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++)
    {
        if(!sum) break;
        if(a[i]==0)
        {
            putchar('R');
            continue;
        }
        while(a[i])
        {
            putchar('P');
            a[i]--,sum--;
            if(!sum) break;
            if(a[i]==0)
                putchar('R');
            else
            {
                if(i==1)putchar('R'),putchar('L');
                else if(i==n) putchar('L'),putchar('R');
                else putchar('L'),putchar('R');
            }
        }
    }
    return 0;
}