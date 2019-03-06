#include<bits/stdc++.h>
using namespace std;
int f[200001],n,x,y,t;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==0)
        {
            scanf("%d",&y);
                t++;
            f[t]=max(f[t-1],y);
        }
        if(x==1&&t!=0)
            t--;
        if(x==2)
            cout<<f[t]<<endl;
    }
    return 0;
}