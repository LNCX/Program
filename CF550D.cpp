#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>k;
    if(k==1)
    {
        printf("YES\n2 1\n1 2\n");
        return 0;
    }
    if(k%2==0)
    {
        printf("NO\n");
        return 0;
    }
    n=k+2;
    printf("YES\n");
    printf("%d %d\n",n*2,n*k);
    printf("%d %d\n",n-1,n-2);
    printf("%d %d\n",2*n-1,2*n-2);
    for(int i=1; i<=n-3;i++)
    {
        printf("%d %d\n",n,i);
        printf("%d %d\n",n-1,i);
        printf("%d %d\n",n-2,i);
        printf("%d %d\n",2*n,n+i);
        printf("%d %d\n",2*n-1,n+i);
        printf("%d %d\n",2*n-2,n+i);
    }
    for(int i=1;i<=n-3;i++)
        for(int j=i+1+(int)(i%2);j<=n-3;j++)
        {
            printf("%d %d\n",i,j);
            printf("%d %d\n",n+i,n+j);
        }
    printf("%d %d\n",n,n+n);
    return 0;
}
