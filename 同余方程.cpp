#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&c,&b ))
    {
        if(!(a||b||c))
        {
            break;
            puts("No Solution");
        }
        int x,y,d=exgcd(a,b,x,y);
        cerr<<x<<" "<<y<<endl;
        if(c%d!=0) puts("No Solution");
        x*=c/d;
        printf("%d\n",(x+b/d)%(b/d));
    }
    return 0;
}