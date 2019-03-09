#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	float ans=0;
	cin>>n;
	if(n<=30) ans+=n*0.2;
	if(30<=n&&n<=60) ans+=6+(n-30)*0.6;
	if(ans==0)	cout<<"NO"<<endl;
	else printf("%.2f\n",ans);
}

