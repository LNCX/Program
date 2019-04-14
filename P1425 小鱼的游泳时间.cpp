#include<iostream>
using namespace std;
int i=0,a[105];
int main()
{
    do
    {
    	cin>>a[i];
		i++;
	}while(a[i-1]!=0);
    for(int j=i-2;j>=0;j--) 
		cout<<a[j]<<" ";
}
