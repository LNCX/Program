#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a,b,m;
bool flag;
vector<int>ans;
void dfs(int s,int n)
{
    if(s==n)
    {
        for(int i=0;i<ans.size();i++)
        {
            printf("%lld",2*)
        
        }
    }
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        scanf("%lld%lld%lld",&a,&b,&m);
        ll n=1;
        while(n<=50)
        {
            n++;
            if((1ll<<(n-2))*a<b&&(1ll<<(n-1))*a>=b)
                break;
        }
        if(n>50)
        {
            puts("-1");
            return 0;
        }
        flag=false;
        dfs();
    }
    return 0;
}