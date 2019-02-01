#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c[20];
	scanf("%s", c);
	for(int i=0;c[i];)
	{
		if(i==0&&c[i]=='9')
		{
			i++;
			continue;
		}
		else if(c[i]>='5')
		{
			c[i]='9'-c[i]+'0';
			i++;continue;
		}
		i++;
	}
	printf("%s\n", c);
	return 0;
}
