#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s1[5]={'h','a','p','p','y'};
	int count=0;
	char s2[100];
	cin>>s2;
	for(int  i=0;i<strlen(s2);i++)
		if(s1[count]==s2[i]) count++;
	if(count==5) cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
}
