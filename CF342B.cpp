#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int n,m,s,f;
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&f);
    int pos=s,tim=1;
    if(s<f)
    {
        for(int i=1;i<=m;i++)
        {
            LL t;
            int l,r;
            scanf("%lld%d%d",&t,&l,&r);
            if(pos==f) return 0;
            while(tim<t)
            {
                tim++;
                pos++;
                putchar('R');
                if(pos==f) return 0; 
            }
            if(pos>r||pos<l-1)
            {
                pos++;
                putchar('R');
            }
            else putchar('X');
            tim++;
        }
        while(pos!=f) putchar('R'),pos++;
    }
    if(s>f)
    {
        for(int i=1;i<=m;i++)
        {
            LL t;
            int l,r;
            scanf("%lld%d%d",&t,&l,&r);
            if(pos==f) return 0;
            while(tim<t)
            {
                tim++;
                pos--;
                putchar('L');
                if(pos==f) return 0; 
            }
            if(pos==f) break; 
            if(pos>r+1||pos<l)
            {
                pos--;
                putchar('L');
            }
            else putchar('X');
            tim++;
        }
        while(pos!=f) putchar('L'),pos--;
    }
    return 0;
}