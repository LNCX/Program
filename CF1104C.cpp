#include<bits/stdc++.h>
using namespace std;
string s;
int a[2][2]={1,1,3,1},b[4][2]={1,3,2,3,3,3,4,3};
int main()
{
	cin>>s;
	int len=s.length(),s1=0,s2=0;
	for(int t=0;t<len;t++)
	{
		if(s[t]=='0')
		{
            printf("%d %d\n",a[s1][0],a[s1][1]);
			s1++;
		}
	    else if(s[t]=='1')
		{
            printf("%d %d\n",b[s2][0],b[s2][1]);
			s2++;
		}
		if(s1==2) s1=0;
		else if(s2==4) s2=0;
	}
	return 0;
}
