#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int x=1;x<=9;x++)
	for(int y=1;y<=9;y++)
		cout<<x+y/9<<" "<<y%9+1<<endl;
}
