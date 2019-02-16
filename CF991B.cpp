#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],sum,ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(((double)sum/n+0.5)>=5)
            break;
        sum-=a[i];
        sum+=5;ans++;
    }
    printf("%d\n",ans);
    return 0;
}