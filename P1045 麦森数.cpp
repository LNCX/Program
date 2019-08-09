#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct lint
{
    int len;
    int num[1500];
    friend lint operator *(lint a,lint b)
    {
        lint ans;ans.len=a.len+b.len;
        memset(ans.num,0,sizeof(ans.num));
        for(int i=1;i<=a.len;i++)
            for(int j=1;j<=b.len;j++)
            {
                ans.num[i+j-1]+=a.num[i]*b.num[j];
                ans.num[i+j]+=ans.num[i+j-1]/10;
                ans.num[i+j-1]%=10;
            }
        while(ans.len>501||(ans.len>1&&ans.num[ans.len]==0)) ans.len--;
        return ans;
    }
    friend lint operator -(lint a,lint b)
    {
        lint ans;memset(ans.num,0,sizeof(ans.num));
        while(ans.len<=a.len||ans.len<=b.len)
        {
            if(a.num[ans.len]<b.num[ans.len])
            {
                a.num[ans.len+1]-=1;
                a.num[ans.len]+=10;
            }
            ans.num[ans.len]=a.num[ans.len]-b.num[ans.len];
            ans.len++;
        }
        while(ans.len>501||(ans.len>1&&ans.num[ans.len]==0)) ans.len--;
        return ans;
    }
}a,e;
lint power(lint a,int p)
{
    lint ans;
    memset(ans.num,0,sizeof(ans.num));
    ans.num[1]=1,ans.len=1; 
    while(p)
    {
        if(p%2==1)
            ans=ans*a;
        a=a*a;
        p/=2;
    }
    return ans;
}
int main()
{
    int p;
    cin>>p;
    printf("%d\n",(int)(p*log10(2)+1));
    e.num[1]=1,a.num[1]=2,e.len=a.len=1;
    lint b=power(a,p);b=b-e;
    for(int i=500;i>=1;i--)
    {
        if(i%50==0&&i!=500) puts(" ");
        i>b.len?putchar('0'):printf("%d",b.num[i]);
    }
    puts("");
    return 0;
}