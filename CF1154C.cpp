#include<iostream>
using namespace std;
int a[5];
const int mp[]={0,1,2,3,1,3,2,1};
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	int ans=0;
	for(int i=1;i<=7;i++)
    {
		int b=min((a[1])/3,min((a[2])/2,(a[3])/2));
        int d[4]={0,a[1]-3*b,a[2]-2*b,a[3]-2*b};
        int c=b*7;
        for(int j=1;j<=7;j++)
        {
            if(d[mp[j]])
                d[mp[j]]--,c++;
            else break;
        }
        a[mp[i]]++;
        ans=max(ans,c-i+1);
    }
    cout<<ans<<endl;
    return 0;
}