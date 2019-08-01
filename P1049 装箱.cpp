#include<iostream>
#define maxn 20005
using namespace std;
int main()
{
    int n,m,x,l=1,f[maxn]={0},w[maxn]={0};
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<=m)
        {w[l]=x;l++;}
    }
    for(int i=1;i<l;i++)
        for(int v=m;v>0;v--)
            if(w[i]<=v&&f[v-w[i]]+w[i]<=m&&f[v-w[i]]+w[i]>f[v])
                f[v]=f[v-w[i]]+w[i];
    cout<<m-f[m]<<endl;
}
