#include<bits/stdc++.h>
#define dy(a,b) (fabs(a-b)<eps)
using namespace std;
const double eps=1e-8;
int n=0,m=0,ans=0;
double x[20],y[20],pa[20],pb[20],tx[20],ty[20];
void dfs(int c,int u,int v)
{
    if(u+v>=ans) return;
    if(c>n)
    {
        ans=u+v;
        return;
    }
    bool flag=false;
    for(int i=1;i<=u;i++)
        if(dy(pa[i]*x[c]*x[c]+pb[i]*x[c],y[c]))
        {
            dfs(c+1,u,v);
            flag=true;
            break;
        }
    if(!flag)
    {
        for(int i=1;i<=v;i++)
        {
            if(dy(x[c],tx[i])) continue;
            double a=(y[c]*tx[i]-ty[i]*x[c])/(x[c]*x[c]*tx[i]-tx[i]*tx[i]*x[c]);
            double b=(y[c]-x[c]*x[c]*a)/x[c];
            if(a<0)
            {   
                pa[u+1]=a;
                pb[u+1]=b;
                double q=tx[i],w=ty[i];
                for(int j=i;j<v;j++)
                {
                    tx[j]=tx[j+1];
                    ty[j]=ty[j+1];
                }
                dfs(c+1,u+1,v-1);
                for(int j=v;j>i;j--) 
                {
                    tx[j]=tx[j-1];
                    ty[j]=ty[j-1];
                }
                tx[i]=q;
                ty[i]=w;
            }
        }
        tx[v+1]=x[c];
        ty[v+1]=y[c];
        dfs(c+1,u,v+1);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) 
            scanf("%lf%lf",&x[i],&y[i]);
        ans=0x7fffffff;
        dfs(1,0,0);
        printf("%d\n",ans); 
    } 
    return 0;
}