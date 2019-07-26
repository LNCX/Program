#include<bits/stdc++.h>
using namespace std;
int n;
int ask(char c,int x)
{
    printf("%c %d\n",c,x);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}
int geta()
{
    int l=1,r=1e9,res=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(!ask('>',mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    return res;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int getd()
{
    vector<int>a,b;
    for(int i=1;i<=n;i++)
        a.push_back(i);
    srand(time(0));
    for(int i=1;i<=20;i++)
    {
        random_shuffle(a.begin(),a.end());
        srand(rand()),srand(rand());
    }
    for(int i=0;i<30&&i<a.size();i++)
        b.push_back(ask('?',a[i]));
    sort(b.begin(),b.end());
    int d=b[1]-b[0];
    for(auto i=2;i<b.size();i++)
        d=gcd(d,b[i]-b[i-1]);
    return d;
}
int main()
{
    cin>>n;
    int a=geta(),d=getd();
    printf("! %d %d\n",a-(n-1)*d,d);
    return 0;
}