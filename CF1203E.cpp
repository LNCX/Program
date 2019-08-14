#include<bits/stdc++.h>
using namespace std;
const int N=15e4+5;
int a[N],vis[N]={1},n,cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        for(int j=-1;j<=1;j++)
            if(!vis[a[i]+j])
            {
                vis[a[i]+j]=1;
                cnt++;
                break;
            }                
    }
    cout<<cnt<<endl;
    return 0;
}