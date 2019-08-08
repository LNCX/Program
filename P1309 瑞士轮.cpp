#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,r;
struct node
{
    int s,w,n;
    bool operator<(const node x) const
    {
        if(s==x.s) return n<x.n;
        return s>x.s;
    }
}a[N],m1[N],m2[N];
void merge()
{
    int l1=1,l2=1,l=1;
    while(l1<=n&&l2<=n)
    {
        if(m1[l1].s==m2[l2].s)
            a[l++]=m1[l1].n<m2[l2].n?m1[l1++]:m2[l2++];
        else if(m1[l1].s>m2[l2].s)
            a[l++]=m1[l1++];
        else a[l++]=m2[l2++];
    }
    while(l1<=n)
        a[l++]=m1[l1++];
    while(l2<=n)
        a[l++]=m2[l2++];
}
int main()
{
    // freopen("/home/xjoi/Downloads/testdata (7).in","r",stdin);
    scanf("%d%d%d",&n,&r,&q);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i].s);
    for(int i=1;i<=2*n;i++)
    {
        a[i].n=i;        
        scanf("%d",&a[i].w);
    }
    sort(a+1,a+1+2*n);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[2*j].w<a[2*j-1].w)
            {
                a[2*j-1].s++;
                m1[j]=a[2*j],m2[j]=a[2*j-1];
            }
            else 
            {
                a[2*j].s++;
                m1[j]=a[2*j-1],m2[j]=a[2*j];
            }
        }
        merge();
        // for(int i=1;i<=2*n;i++)
        //     printf("%d ",a[i].s);
        // puts("");
    }
    cout<<a[q].n<<endl;
    return 0;
}