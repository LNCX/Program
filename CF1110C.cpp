#include<bits/stdc++.h>
using namespace std;
map<int,int>M;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int q;
    cin>>q;
    M[3]=1,M[7]=1,M[15]=5,M[31]=1,M[63]=21,M[127]=1,M[255]=85,M[511]=73,M[1023]=341,M[2047]=89,M[4095]=1365,M[8191]=1,M[16383]=5461,M[32767]=4681,M[65535]=21845,M[131071]=1,M[262143]=87381,M[524287]=1,M[1048575]=349525,M[2097151]=299593,M[4194303]=1398101,M[8388607]=178481,M[16777215]=5592405,M[33554431]=1082401;
    for(int t=1;t<=q;t++)
    {
        int a,b=0;
        scanf("%d",&a);
        if(M[a])
        {
            printf("%d\n",M[a]);
            continue;
        }
        for(int i=0;(1<<i)<=a;i++)
            if(((1<<i)&a)==0)
                b+=(1<<i);
        printf("%d\n",gcd(a^b,a&b));
    }
    return 0;
}