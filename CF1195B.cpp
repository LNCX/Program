#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,k;
    scanf("%lf%lf",&n,&k);
    printf("%d\n",(int)((2*n+3)/2.0-sqrt(8*n+8*k+9)/2.0));
    return 0;
}