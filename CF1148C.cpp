#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,a[maxn],b[maxn];
vector< pair<int,int> >v;
void change(int x,int y)
{
    swap(a[x],a[y]);
    b[a[x]]=x,b[a[y]]=y;
    v.push_back(make_pair(x,y));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=n/2&&i!=a[i])
        {
            if(i<=n/2)
            {
                change(i,n);
                change(a[n],n);
            }
            else
            {
                change(1,i);
                change(1,a[1]);
                change(1,i);
            }
        }
    }
    for(int i=n/2+1;i<=n;i++)
    {
        int k=b[i];
        if(k==a[k]) continue;
        change(1,k);
        change(1,a[1]);
        change(1,k);
    }
    printf("%d\n",v.size());
    for(auto i:v)
        printf("%d %d\n",i.first,i.second);
    // for(int i=1;i<n;i++)
    // {
    //     if(a[i]+1!=a[i+1])
    //     {
    //         puts("0");
    //         return 0;
    //     }
    // }
    // puts("xy");
    return 0;
}