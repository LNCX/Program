#include<bits/stdc++.h>
using namespace std;
int lena=0,flag=1;
char a[105],b[105],c[105],word[105];
bool used[26]={0};
int main()
{
	scanf("%s%s%s",a,b,word);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
	{
		if((c[a[i]-'A']=='\000'&&!used[b[i]-'A'])||c[a[i]-'A']==b[i])
		{
			c[a[i]-'A']=b[i];
			used[b[i]-'A']=1;
		}	
		else
		{
			flag=0;
			break;
		}
	}
	for(int i=0;i<26;i++)
	if(c[i]=='\000')
	{
		flag=0;
		break;
	}
	if(flag)
	for(int i=0;i<strlen(word);i++)
		printf("%c",c[word[i]-'A']);
	else printf("Failed\n");
}
