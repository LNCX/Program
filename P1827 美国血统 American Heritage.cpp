#include<bits/stdc++.h>
using namespace std;
string a,b;
void print(int x,int y,int p,int q) 
{
    if(x>y||p>q) return;
    int i=b.find(a[x]);
    print(x+1,x+i-p,p,i-1);
    print(x+i-p+1,y,i+1,q);
    cout<<a[x];
}
int main() 
{
    cin>>b>>a;
    int l=a.size()-1;
    print(0,l,0,l);
    return 0;
}