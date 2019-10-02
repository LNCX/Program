#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int main()
{
    srand(time(0));
    int n=rand()%N,k=rand()%1000;
    //printf("%d %d\n",n,k);
    puts("200000 200000");
    for(int i=1;i<=n;i++)
        printf("%d ",rand()%1000);
    return 0;
}
