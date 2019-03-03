#include<bits/stdc++.h>
using namespace std;
bool flag;
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=x) a-=x;
    else flag=1;
    if(a+b>=y) a-=y;
    else flag=1;
    if(a+b+c<z)flag=1; 
    if(flag)puts("NO");
    else puts("YES");
    return 0;
}