#include<bits/stdc++.h>
using namespace std;
char word[30][21]={"zero","one","two","three","four","five",
"six","seven","eight","nine","ten","eleven","twelve","thirteen",
"fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty", "a","another","first","both","second","third"};
int main()
{
	int a[7]={0},count=0;
	for(int i=1;i<=6;i++)
	{
		char s[21];
		cin>>s;
		for(int j=0;j<=20;j++)
		if(!strncmp(s,word[j],max(strlen(s),strlen(word[j])))) 
		{
			a[count]=j*j%100;
			count++;
		}
		for(int j=21;j<=26;j++)
		if(!strncmp(s,word[j],max(strlen(s),strlen(word[j]))))
		{
			if(21<=j&&j<=23) a[count]=1;
			else if(j==24||j==25) a[count]=2*2;
			else if(j==26) a[count]=3*3;
			count++;
		}	
	}
	sort(a,a+count);
	int i=0;
	while(a[i]==0) i++;
	for(;i<count;i++)	
	cout<<a[i];
}
