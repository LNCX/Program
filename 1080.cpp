#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
	char a[4][100],word;
	int count[26]={0},max=0;;
	for(int i=0;i<4;i++) gets(a[i]);
	for(int i=0;i<4;i++) for(int j=0;j<strlen(a[i]);j++) count[a[i][j]-65]++;
	for(int i=0;i<26;i++) if(count[i]>max) max=count[i];
	char print[max][26];
	memset(print,'*',sizeof(print));
	for(int i=0;i<26;i++) for(int j=0;j<max-count[i];j++) print[j][i]=' ';
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<26;j++) printf("%c ",print[i][j]);
		printf("\n");
	}
	for(word=65;word<=90;word++) printf("%c ",word);
}
