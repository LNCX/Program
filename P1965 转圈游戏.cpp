#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||'9'<c) c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
int power(int a,int b,int p)
{
    a%=p;
    int ans=1;
    while(b)
    {
        if(b&1) ans=a*ans%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
int main()
{
    int n=read(),m=read(),k=read(),x=read();
    cout<<(x%n+m%n*power(10,k,n)%n)%n<<endl;
    return 0;
}