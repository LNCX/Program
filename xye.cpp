#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
multimap<int,int>m;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]),m[b[i]]=i;
    for(int i=1;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++)
        if(b[i]>c[i]) return puts("0"),0;
    
    
}