#include<bits/stdc++.h>
using namespace std;
int a[4]={-1,-1,-1,-1};
int main()
{
    int x;
    cin>>x;
    for(int i=0;i<=2;i++)
        a[(x+i)%4]=i;
    if(a[1]!=-1) printf("%d A\n",a[1]);
    else if(a[3]!=-1) printf("%d B\n",a[3]);
    else if(a[2]!=-1) printf("%d C\n",a[2]);
    else printf("%d D\n",a[0]);

    return 0;
}