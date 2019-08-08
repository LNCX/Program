#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ans=0,n,m,cnt,dif;
char a[N],b[N];
int main()
{
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1),m=strlen(b+1);
    for(int i=1;i<=m;i++)
        if(a[i]!=b[i])
            dif++;
    for(int i=1;i<m;i++)
        if(b[i]!=b[i+1])
            cnt++;
    cnt%=2;
    if(dif%2==0) ans++;
    for(int i=1;i+m<=n;i++)
    {
        if(a[i]!=b[1]) dif++;
        if(a[i+m]!=b[m]) dif++;
        dif+=cnt;
        if(dif%2==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}