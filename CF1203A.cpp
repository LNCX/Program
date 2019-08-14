#include<bits/stdc++.h>
using namespace std;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    arg=x*f;
    read(args...);
}
const int N=205;
int a[N];
int main()
{
    int q;
    read(q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            read(a[i]);
        bool f1=1,f2=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                for(int j=1;j<n;j++)
                    if(a[(i+j)%n]!=a[(i+j-1)%n]+1)
                    {
                        f1=0;
                        break;
                    }
            }
            if(a[i]==n)
            {
                for(int j=1;j<n;j++)
                    if(a[(i+j)%n]!=a[(i+j-1)%n]-1)
                    {
                        f2=0;
                        break;
                    }
            }
        }
        if(f1||f2) puts("YES");
        else puts("NO");
    }
    return 0;
}