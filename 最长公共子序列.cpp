#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char a[200],b[200];
		cin>>a>>b;
		int lena=strlen(a),lenb=strlen(b);
		int f[lena+1][lenb+1]={};
		for(int i=1;i<=lena;i++)
		for(int j=1;j<=lenb;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i-1]==b[j-1])
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
		cout<<f[lena][lenb]<<endl;	
	} 
}
