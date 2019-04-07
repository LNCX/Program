#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
double f[maxn];
int main()
{
    int m;
    cin>>m;
    for(int i=m;i>=0;i--)
    {
        double sum=0;
        for(int j=0;j<=m;j++)
            sum+=f[__gcd(i,j)];
        f[i]=1+sum/m;
        cout<<f[i]<<endl;
    }
    cout<<f[0]<<endl;
    return 0;
}