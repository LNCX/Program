#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
string s;
ll ans,c[N][N];
int cnt[N],a[N];
ll cal(int m)
{
    ll res=1;
    for(int i=0;i<=9;i++)
    {
        res*=c[m][cnt[i]];
        m-=cnt[i];
    }
    return res;
}
int main()
{
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++)
        a[i]=s[i]-'0',cnt[a[i]]++;
    c[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
            if(cnt[j])
            {
                cnt[j]--; 
                ans+=cal(n-i-1);
                cnt[j]++;
            }    
        cnt[a[i]]--;
    }
    cout<<ans<<endl;
    return 0;
}