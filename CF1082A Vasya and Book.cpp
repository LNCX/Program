#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y,d,ans1=0,ans2=0;
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if(abs(y-x)%d==0) cout<<abs(y-x)/d<<endl;
        else
        {
            ans1+=ceil(x/d);//翻到第一页;
            if((x-1)%d!=0) ans1=inf;
            else ans1+=(x-1)/d;
            
            ans2+=ceil((n-y)/d);
            if((n-y)%d!=0) ans2=inf;
            else ans2+=(n-y)/d;

            if(ans1==ans2==inf) cout<<-1<<endl;
            else cout<<min(ans1,ans2)<<endl;
        }
    }
    return 0;
}