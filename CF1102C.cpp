#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,x,y,a[maxn],cnt;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(x>y)
    {
        cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(a[i]<=x) cnt++;
    cout<<ceil(cnt/2.0)<<endl;
    return 0;
}