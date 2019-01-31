#include<iostream>
#include<cstring> 
using namespace std;
int ans[26],count[26];
char a[100][2][10];
int main()
{
	char a[100][2][10];
	int ans[26];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		memset(count,0,sizeof(count));
		cin>>a[i][0]>>a[i][1];
		for(int j=0;j<strlen(a[i][0]);j++)
			if(count[a[i][0][j]-'a']==0) count[a[i][0][j]-'a']++;
		for(int j=0;j<strlen(a[i][1]);j++)
			if(count[a[i][1][j]-'a']==0) count[a[i][1][j]-'a']++;
		for(int j=0;j<26;j++)
			ans[j]+=count[j];
	}
	for(int i=0;i<26;i++)
		cout<<ans[i]<<endl;
}
