#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	char word;
	int a,b,c,d,q,w;
	scanf("%d%c%d%d%c%d",&a,&word,&b,&c,&word,&d);
	a=a*c,b=b*d;
	q=a/gcd(a,b),w=b/gcd(a,b);
	cout<<w<<" "<<q<<endl;
	return 0;
}

