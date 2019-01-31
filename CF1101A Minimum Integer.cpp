#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
		int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
		if(d<l||d>r)
			cout<<d<<endl;
		else
        {
            int x=r-r%d+d;
            cout<<x<<endl;
		}
	}
	return 0;
}