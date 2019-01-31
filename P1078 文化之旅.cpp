#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while('0'>c||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
int main()
{
    int n=read(),k=read(),m=read(),s=read(),t=read();
    
    return 0;
}