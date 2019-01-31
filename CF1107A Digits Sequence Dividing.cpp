#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            scanf("%1d",&a[i]);
        if(n==2&&a[1]>=a[2])
            {puts("NO");continue;}
        puts("YES");
        printf("2\n%d ",a[1]);
        for(int i=2;i<=n;i++)
            printf("%d",a[i]);
        puts("");
    }
    return 0;
}