#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	LL r,h;
    scanf("%lld%lld",&r,&h);
	LL ans=2*(h/r);
	LL res=h%r;
	if(res*2>=sqrt(3.0)*double(r)) ans+=3;
	else if(res*2LL>=r) ans+=2;
	else ans++;
	cout<<ans<<endl;
	return 0;
}