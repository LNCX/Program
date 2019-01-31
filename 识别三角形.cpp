#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	if(x+y>z&&x+z>y&&y+z>x){
	if(x==y||y==z||z==x||(x==y)&&(y==z)) 
	printf("Equilateral");
	else
    if(x*x==y*y+z*z||x*x+y*y==z*z||y*y==x*x+z*z) printf("Right");
	else 
	printf("General");
	}
	else printf("No");
	return 0;
}
