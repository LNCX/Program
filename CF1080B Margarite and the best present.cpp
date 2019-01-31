#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if((r-l+1)%2==0)
        {
            int neg=1;
            if(l%2==0) neg=-1;
            printf("%d\n",neg*(r-l+1)/2); 
        }
        else
        {
            int neg=1,ans=0;
            if(l%2==0) neg=-1;
            ans+=neg*(r-l)/2;
            neg=1;
            if(r%2==1) neg=-1;
            ans+=neg*r;
            printf("%d\n",ans);
        }
    }
}