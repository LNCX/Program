#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main()
{
    int n,odd=0,even=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
        x%2?odd++:even++;
    }
    if(odd&&even) sort(a.begin(),a.end());
    for(auto i:a)
        printf("%d ",i);
    return 0;
}