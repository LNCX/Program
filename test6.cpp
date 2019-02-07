#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int ans,ans1;
int main()
{
    for(int i=2;i<=25;i++)
    {
        int a=(1<<i)-1;
        for(int b=1;b<a;b++)
        {
            int t=gcd(a^b,a&b);
            if(t>=ans)
            {
                ans=t;
                ans1=b;
            }
        }
        printf("M[%d]=%d,",a,ans);
        ans=0;
    }
    return 0;
}