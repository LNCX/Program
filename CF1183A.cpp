#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res%4==0;
}
int main()
{
    int n ;
    cin>>n;
    for(int x=n;;x++)
    {
        if(check(x))
        {
            cout<<x<<endl;
            break;
        }
    }
    return 0;
}