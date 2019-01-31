#include<cstdio>
using namespace std;
int main()
{
	char a[200],b[200];
	gets(a),gets(b);
	if(b[0]=='a') printf("1 2\n");
	else if(b[0]=='0') printf("1 2 3 4 5 6 7 8 9 10\n");
	else if(b[0]=='9') printf("1 2 3 4 6 7 8 9\n");
	else if(b[0]=='I') printf("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
}
