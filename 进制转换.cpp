#include<bits/stdc++.h>
using namespace std;
int m;
char c[1005];
int main()
{
	scanf("%d%s",&m,c);
	for(int i=0;i<strlen(c);i++)
	{
	  if(i!=0&&c[i]!='0') printf("+");
      if (c[i]=='0') continue;
      printf("%c*%d^%d",c[i],m,strlen(c)-i-1);
	}
	return 0;
}

