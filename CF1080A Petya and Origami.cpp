#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    printf("%d\n",(n*2+k-1)/k+(n*5+k-1)/k+(n*8+k-1)/k);;
}