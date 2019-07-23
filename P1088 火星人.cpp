#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=1;i<=m;i++)
        next_permutation(a.begin(),a.end());
    for(auto i:a) printf("%d ",i);
    return 0;
}