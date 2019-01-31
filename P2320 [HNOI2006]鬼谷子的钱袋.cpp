#include<bits/stdc++.h>
using namespace std;
int a[105],n=0;
int main()
{
    int m;
    cin>>m;
    while(m)
    {
        a[++n]=(m+1)>>1;
        m>>=1;
    }
    cout<<n<<endl;
    for(int i=n;i>=1;i--)
        printf("%d ",a[i]);
    printf("\n");
}