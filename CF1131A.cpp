#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL w1,h1,w2,h2;
    scanf("%lld%lld%lld%lld",&w1,&h1,&w2,&h2);
    cout<<2LL*(h2+h1+max(w1,w2)+2LL)<<endl;
    return 0;
}