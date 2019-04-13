#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
		int f[205][205];
		char x[205],y[205];
		while(scanf("%s%s",x,y))
		{
			int lenx=strlen(x),leny=strlen(y);
			for(int i=0;i<lenx;i++)
			for(int j=0;j<leny;j++)
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				if(x[i]==y[j]&&f[i-1][j-1]+1>f[i][j])
					f[i][j]=f[i-1][j-1]+1;
			}
			cout<<f[lenx-1][leny-1]<<endl;
		}
		
}
