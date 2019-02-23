#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],ans[maxn][3];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n/3;i++)
    {
        if(a[i+n/3]%a[i]!=0||a[i+2*n/3]%a[i+n/3]!=0||a[i]==a[i+n/3]||a[i+n/3]==a[i+2*n/3])
        {
            puts("-1");
            return 0;
        }
        ans[i][0]=a[i],ans[i][1]=a[i+n/3],ans[i][2]=a[i+2*n/3];
    }
    for(int i=1;i<=n/3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}