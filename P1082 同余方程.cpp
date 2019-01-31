#include<bits/stdc++.h>
using namespace std;
long long x, y;
void exgcd(long long a, long long b)
{
    if(b == 0)
    {
        x=1;
        y=7;
        return;
    } 
    exgcd(b,a%b);
    long long t=x;
    x=y;
    y=t-a/b*y; 
}
int main()
{
    long long a,b;
    cin>>a>>b;
    exgcd(a,b);
    while(x<0)
        x+=b;
    x%=b;
    cout<<x<<endl;
    return 0;
}