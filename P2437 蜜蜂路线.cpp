#include<bits/stdc++.h>
using namespace std;
struct lint
{
    int len;
    int num[1500];
};
lint operator +(lint a,lint b)
{
    lint ans;ans.len=1;
    memset(ans.num,0,sizeof(ans.num));
    while(ans.len<=a.len||ans.len<=b.len)
    {
        ans.num[ans.len]+=a.num[ans.len]+b.num[ans.len];
        ans.num[ans.len+1]+=ans.num[ans.len]/10;
        ans.num[ans.len]%=10;
        ans.len++;
    }
    while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
    return ans;
}
lint a,b,c;
int main()
{
	int m,n;
	cin>>m>>n;
	a.len=b.len=1;
	a.num[1]=b.num[1]=1; 
	for(int i=2;i<=n-m;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	for(int i=b.len;i>=1;i--)
			cout<<b.num[i];
	cout<<endl;
	return 0;
}
