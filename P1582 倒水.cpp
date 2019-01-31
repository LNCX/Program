#include<cstdio>
using namespace std;
int n,k,ans;
int work(int x)
{
	int num=0;
	while(x)
	{
		x-=x&-x;
		num++;
	}
	return num;
}
int main()
{
	scanf("%d%d",&n,&k);
	while(work(n)>k) 
		ans+=n&-n,n+=n&-n;
	printf("%d\n",ans);
	return 0;
}
