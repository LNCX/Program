#include<bits/stdc++.h>
using namespace std;
int a[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main()
{
	int ans=0;
	char word;
	while(1)
	{
		word=getchar();
		if(word==' ') ans++;
		else if('a'<=word&&word<='z') ans+=a[word-'a'];
		else break;
	}
	cout<<ans<<endl;
	return 0;
}

