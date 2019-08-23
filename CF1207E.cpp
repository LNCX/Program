#include<bits/stdc++.h>
using namespace std;
int main()
{
    printf("? ");
    for(int i=0;i<=99;i++)
        printf("%d ",i);
    puts("");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    x>>=7,x<<=7;
    printf("? ");
    for(int i=1;i<=100;i++)
        printf("%d ",i<<7);
    puts("");
    fflush(stdout);
    int y;
    scanf("%d",&y);
    for(int i=0;i<=6;i++)
        if(y&(1<<i))
            x+=(1<<i);
    printf("! %d\n",x);
    fflush(stdout);
    return 0;
}