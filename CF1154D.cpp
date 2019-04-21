#include<iostream>
using namespace std;
int ans,x;
int main()
{
    int n,a,b,pa,pb;
	cin>>n>>b>>a;
    pa=a;pb=b;
    for(ans=0;ans<n;ans++)
    {
        cin>>x;
        if(x&&a<pa&&b)
        {
            a++;
            b--;
        }
        else if(!x&&a)a--;
        else if(a==0&&b==0)break;
        else if(a)a--;
        else if(b)b--;
        else break;
    }
    cout<<ans<<"\n";
}