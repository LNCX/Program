#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
bool a[maxn];
int main()
{
    int p,n;
    cin>>p>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(!a[x%p]) a[x%p]=1; 
        else
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}