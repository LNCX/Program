#include<bits/stdc++.h>
using namespace std;
int a,b;
int sum=0,mid=0;
int main() 
{
    scanf("%d%d",&a,&b);
    while(a) 
    {
        sum+=a;
        mid+=a;
        a=mid/b;
        mid%=b;
    }
    printf("%d\n",sum);
    return 0;
}
