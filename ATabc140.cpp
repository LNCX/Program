#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=111;i<=999;i++)
    {
        int x=i;
        bool flag=true;
        while(x)
        {
            if(!(1<=x%10&&x%10<=n))
            {
                flag=false;
                break;
            }
            x/=10;
        }
        if(flag) ans++;
    }
    cout<<ans<<endl;
    return 0;
}