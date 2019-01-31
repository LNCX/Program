#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
bool prime[MAXN];
int Prime[MAXN];
int num=0,n;
void make_prime()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i<=MAXN;i++)
    {
        if(prime[i])
        {
            Prime[num++]=i;
        }
        for(int j=0;j<num&&i*Prime[j]<MAXN;j++)
        {
            prime[i*Prime[j]]=false;
            if(!(i%Prime[j]))
                break;
        }
    }
    return;
}
int main()
{
	cin>>n;
	make_prime();
	return 0;
}
