#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        n>>=1;
        while(n--)
        {
            int cnt=0;
            int a,b;
            scanf("%d%d",&a,&b);
            int x=(a-1)|(b-1);
            while(x&1)
            {
                cnt++;
                x>>=1;
            }
            ans^=cnt;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}