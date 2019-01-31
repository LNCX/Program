#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        while(n--)
        {
            int x;
            scanf("%d",&x);
            ans^=x;
        }
        if(ans) puts("Yes");
        else puts("No");
    }
    return 0;
}
