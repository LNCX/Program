#include<bits/stdc++.h>
using namespace std;
struct student{int data;int rank;}a[2005],b[2005];
bool cmp1(student a,student b){return a.data>b.data;}
bool cmp2(student a,student b){return a.rank<b.rank;}
int main()
{
    int m,n,k,l,d;
    cin>>m>>n>>k>>l>>d;
    for(int i=1;i<=d;i++)
	{
        int x,y,q,p;
        cin>>x>>y>>q>>p;
        if(x==q){a[min(y,p)].data++; a[min(y,p)].rank=min(y,p);}
        if(y==p){b[min(x,q)].data++; b[min(x,q)].rank=min(x,q);}
    }
    sort(a+1,a+2005,cmp1);
    sort(b+1,b+2005,cmp1);
    sort(a+1,a+l+1,cmp2);
    sort(b+1,b+k+1,cmp2);
    for(int i=1;i<=k;i++)cout<<b[i].rank<<' ';cout<<endl;
    for(int i=1;i<=l;i++)cout<<a[i].rank<<' ';cout<<endl;    
}
