#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000010;
char s[N],re[1000];
char ask(LL j,LL k)
{
    k=min(k,2000000000ll);
    printf("? %lld %lld\n",j,k);
    fflush(stdout);
    scanf("%s",re);
    return re[0];
}
int main()
{
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='e'||s[0]=='m')
            break;
        char w=ask(0ll,1ll);
        if(w=='x')
        {
            printf("! 1\n");
            fflush(stdout);
            continue;
        }
        LL j=1;LL k=2;
        int flag=0;
        for(int i=1;i<=30;i++)
        {
            w=ask(j,k);
            if(w=='x')
            {
                flag=1;
                break;
            }
            else j=k,k*=2;
        }
        if(flag)
        {
            LL mid=(j+k)>>1;
            for(int i=1;i<=29;i++)
            {
                mid=(j+k)>>1;
                w=ask(mid,k);
                if(w=='x') j=mid;
                else k=mid;
            }
            printf("! %lld\n",max(j,k));
            fflush(stdout);
        }
    }
    return 0;
}