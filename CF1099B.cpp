#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=1;
    while(a*a<n) a++;
    a--;
    if((a+1)*a>=n) cout<<2*a+1<<endl;
    else cout<<2*a+2<<endl;
    return 0;
}