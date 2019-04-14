#include<cstdio>
using namespace std;
int sub[4],k;
bool deal(int x)
{
    sub[1]=x/100;
    sub[2]=(x%10000)/10;
    sub[3]=x%1000;
    if(!sub[1]%k&&!sub[2]%k&&!sub[3]%k)
        return true;
    return false;
}
int main()
{
   scanf("%d",&k);
   for(int i=10000;i<=30000;i++)
    if(deal(i)) printf("%d",i);
}
