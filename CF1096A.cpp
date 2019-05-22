#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==1) printf("%d %d\n",l,l+1);
        else printf("%d %d\n",l,2*l);
    }
    return 0;
}