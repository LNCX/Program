#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s1[N],s2[N];
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--) 
    {
		scanf("%s%s",s1,s2);
		int p1,p2;
		for(p1=p2=0;s2[p2];p2++) 
        {
			if(s1[p1]==s2[p2]) p1++;
			else if(!p2||s2[p2]!=s2[p2-1]) break;
		}
		puts(s2[p2]||s1[p1]?"NO":"YES");
	}
	return 0;
}
