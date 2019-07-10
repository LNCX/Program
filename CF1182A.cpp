#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2) cout<<0<<endl;
    else cout<<(long long)pow(2ll,n/2)<<endl;
    return 0;
}