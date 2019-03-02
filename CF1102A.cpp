#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n;
    cin>>n;
    n%=4;
    if(n==0||n==3)
        puts("0");
    else puts("1");
    return 0;
}