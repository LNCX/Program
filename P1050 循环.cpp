#include<bits/stdc++.h>
using namespace std;
int n;
struct lint
{
    static const int N=305;
    int num[N];
    lint(){memset(num,0,sizeof(num));num[0]=1;}
    friend lint operator*(const lint a,const lint b)
    {
        lint c;
        c.num[0]=a.num[0]+b.num[0];
        for(int i=1;i<=a.num[0];i++)
            for(int j=1;j<=b.num[0];j++)
            {
                c.num[i+j-1]+=a.num[i]*b.num[j];
                c.num[i+j]+=c.num[i+j-1]/10;
                c.num[i+j-1]%=10;
            }
        while(c.num[0]>1&&c.num[c.num[0]]==0) c.num[0]--;
        while(c.num[0]>n) c.num[c.num[0]--]=0;
        return c;
    }
    friend lint operator*(const lint a,const int b)
    {
        lint c;
        c.num[0]=a.num[0]+10;
        for(int i=1;i<=c.num[0];i++)
        {
            c.num[i]+=a.num[i]*b;
            c.num[i+1]+=c.num[i]/10;
            c.num[i]%=10;
        }
        while(c.num[0]>1&&c.num[c.num[0]]==0) c.num[0]--;
        while(c.num[0]>n) c.num[c.num[0]--]=0;
        return c;
    }
    void read()
    {
        char s[N];
        scanf("%s",s);
        num[0]=strlen(s);
        for(int i=0;i<num[0];i++)
            num[num[0]-i]=s[i]-'0';
        while(num[0]>1&&num[num[0]]==0) num[0]--;
    }
    void print()
    {
        for(int i=num[0];i>=1;i--)
            printf("%d",num[i]);
        puts("");
    }
};
lint a,b,ans;
void init()
{
    a.read();
    scanf("%d",&n);
    while(a.num[0]>n) a.num[a.num[0]--]=0;
    b=a;
    ans.num[0]=ans.num[1]=1;
}
int main()
{
    init();
    for(int i=1;i<=a.num[0];i++)
    {
        bool flag=false;
        lint c=b;
        for(int j=1;j<=10;j++)
        {
            if((a*c).num[i]==a.num[i])
            {
                ans=ans*j;
                flag=true;
                b=c;
                break;
            }
            c=b*c;
        }
        if(!flag)
        {
            puts("-1");
            return 0 ;
        }
    }
    ans.print();
    return 0;
}