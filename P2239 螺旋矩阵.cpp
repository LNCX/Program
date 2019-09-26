#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans,mi=0x3f3f3f3f;
    scanf("%d%d%d",&n,&i,&j);
    mi=min(i,min(j,min(n-i+1,n-j+1)));
    if(i<=j)ans=mi*(4*(n-1)-4*mi)+10*mi-4*n-3+i+j;
    else ans=mi*(4*n-4*mi)+2*mi+1-i-j;
    cout<<ans<<endl;
    return 0;
}