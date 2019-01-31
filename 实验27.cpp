#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int num;
	int chinese;
	int math;
	int english;
	int total;
} s[301];

bool cmp(struct stu a,struct stu b)
{
	if(a.total!=b.total)
		return a.total>b.total;
	else if(a.chinese!=b.chinese)
		return a.chinese>b.chinese;
	else
		return a.num<b.num;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		s[i].num=i;
		cin>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].total=s[i].chinese+s[i].math+s[i].english	;
	}
	sort(s+1,s+n+1,cmp);

	for(int i=1; i<=5; i++)
	{
		cout<<s[i].num<<" "<<s[i].total<<endl;
	}
	return 0;
}
