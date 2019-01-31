#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(x==0) printf("0\n");
        else printf("%d\n",x/7+1);
    }
    return 0;
}