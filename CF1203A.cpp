#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N],n,q;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        bool f1=1,f2=1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n&&a[i]==1;j++)
                if(a[(i+j)%n]!=a[(i+j-1)%n]+1)
                {
                    f1=0;
                    break;
                }
            for(int j=1;j<n&&a[i]==n;j++)
                if(a[(i+j)%n]!=a[(i+j-1)%n]-1)
                {
                    f2=0;
                    break;
                }
        }
        (f1||f2)?puts("YES"):puts("NO");
    }
    return 0;
}