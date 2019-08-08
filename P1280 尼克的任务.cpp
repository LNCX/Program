#include<bits/stdc++.h>
using namespace std;
const int N=45;
int l[N],n,sum,ans;
int get()
{
    int i,a=0,b=0,c=0;
    for(i=1;i<=n;i++)
    {
        a+=l[i];
        if(a>=sum/3.0) break;
    }
    i++;
    for(;i<=n;i++)
    {
        b+=l[i];
        if(b>=(sum-a)/2.0)
        {
            c=sum-a-b;
            break;
        }
    }
    double p=(double)(a+b+c)/2.0;
    if(a>=b+c||b>=a+c||c>=a+b||a<=0||b<=0||c<=0) return 1;
    return -100.0*sqrt((double)p*(p-a)*(p-b)*(p-c));
}
void SA()
{
    int now=ans;
    double T=5000,delta=0.998;
    while(T>1e-14)
    {
        int x=rand()%n+1,y=rand()%n+1;
        swap(l[x],l[y]);
        int p=get(),d=p-now;
        if(now<0) now=p;
        else if(exp(-d/T)*RAND_MAX>rand()) now=p;
        else swap(l[x],l[y]);
        if(ans>now) ans=now;
        T*=delta;
    }
}
void solve()
{
    random_shuffle(l+1,l+1+n);
    ans=get();
    while((double)clock()/CLOCKS_PER_SEC<0.9) SA();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&l[i]),sum+=l[i];
    srand(19260817),srand(rand()),srand(rand());
    solve();
    cout<<-ans<<endl;
    return 0;
}