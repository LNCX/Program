#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>=2*m)
    {
        if(m==0) cout<<1<<endl;
        else cout<<m<<endl;
    }
    else
        printf("%d\n",n-m);
    return 0;
}