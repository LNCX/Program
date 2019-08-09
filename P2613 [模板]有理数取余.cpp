#include<bits/stdc++.h>
using namespace std;
const int mod=19260817,N=1e4+5;
class lint
{
    private:
        int len,d[N];
        friend lint operator*(const lint a,const lint b)
        {
            
        }
        friend lint operator%(const lint a,int b)
        {

        }
    
    public:
        lint()
        {
            len=1;
            memset(d,0,sizeof(d));
        }      
        void read()
        {
            
        }
        void print()
        {

        }
};
lint power(lint a,lint b)
{
    a=a%mod;
    lint res=1;
    while(b)
    {
        if(b&1) (res*=a)%=mod;
        b>>=1,(a*=a)%=mod;
    }
    return res;
}
int main()
{
    lint a,b;
    a.read(),b.read();
    cout<<a*power(b,mod-2)%mod<<endl;
    return 0;
}