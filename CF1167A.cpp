#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        bool flag=false;
        for(int i=0;i<n;i++)
            if(s[i]=='8'&&n-i>=11)
            {
                flag=true;
                break;
            }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}