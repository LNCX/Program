#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N=100006;
LL a[N];
string s;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    cin>>s;
    bool flag=0;
    LL ans=0,k=0,num=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W')
        {
            flag=1;
            k+=a[i];
            ans+=3*a[i];
        }
        else if(s[i]=='G')
        {
            k+=a[i];
            ans+=5*a[i];
            num+=(a[i]<<1);
        }
        else
        {
            ans+=a[i];
            k-=a[i];
            if(k<0)
            {
                ans-=k*(flag?3:5);
                k=0;
            }
        }
        num=min(num,k);
    }
    if(k>0)ans-=(num<<1)+(k-num);
    cout<<ans<<endl;
    return 0;
}