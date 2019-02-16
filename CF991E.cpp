#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int num[10],mid[10];
LL A[20],ans=0;
void dfs(int x)
{
    if(x==10)
    {
        int cnt=0;
        for(int i=0;i<10;i++)
            cnt+=mid[i];
        LL p=A[cnt];
        for(int i=0;i<10;i++)
            p/=A[mid[i]];
        if(mid[0]>=1)
            p-=(p*mid[0]/cnt);
        ans+=p;
        return ;
    }
    for(int i=1;i<=num[x];i++)
    {
        mid[x]=i;
        dfs(x+1);
    }
    if(num[x]==0)
        dfs(x+1);
}
int main()
{
    string s;cin>>s;
    for(int i=0;i<s.length();i++)
        num[s[i]-'0']++;
    A[0]=1;
    for(LL i=1;i<=19;i++)
        A[i]=A[i-1]*i;
    dfs(0);
    cout<<ans<<endl;
    return 0;   
}