#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int m,n,a[N];
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
class RMQ
{
    private:
        int f[N][20],log[N]={-1};
    public:
        RMQ(){memset(f,0x3f3f3f3f,sizeof(f));}
        void insert()
        {
            for(int i=1;i<=n;i++)
            {
                log[i]=log[i>>1]+1;
                f[i][0]=a[i];
            }
            for(int j=1;(1<<j)<=n;j++)
                for(int i=1;i+(1<<j)-1<=n;i++)
                    f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
        int query(int l,int r)
        {
            int k=log[r-l+1];
            return min(f[l][k],f[r-(1<<k)+1][k]);
        }
}st;
int main()
{
    read(n,m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    st.insert();
    for(int i=1;i<=m;i++)
    {
        int l,r;
        read(l,r);
        printf("%d ",st.query(l,r));
    }
    puts("");
    return 0;
}