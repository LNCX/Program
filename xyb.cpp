#include<bits/stdc++.h>
using namespace std;
int ans[1000],cnt;
bool check(int x)
{
    for(int i=0;i<=29&&(1<<i)<=x;i++)
        if(!(x&(1<<i)))return true;
    return false;
}
int main()
{
    int x;
    cin>>x;
    while(check(x))
    {
        if(!check(x+1))
        {
            ans[++cnt]=-1;
            break;
        }
        for(int i=29;i>=0;i--)
        {
            if((1<<i)>=x) continue;
            if(!((1<<i)&x))
            {
                ans[++cnt]=i;
                x^=(1<<(i+1))-1;
                x++;
                cout<<x<<endl;
                break;
            }
        }
    }
    cout<<cnt*2<<endl;
    for(int i=1;i<=cnt;i++)
        printf("%d ",ans[i]+1);
    return 0;
}