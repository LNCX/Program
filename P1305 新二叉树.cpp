#include<bits/stdc++.h>
using namespace std;
int n;
char a[30][3];
void f(char x)
{
    if(x!='*')
    {
        cout<<x;
        for(int i=1;i<=n;i++)
        if(a[i][0]==x)
        {
            f(a[i][1]);
            f(a[i][2]);
        }
    }
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]);
	f(a[1][0]);
}

