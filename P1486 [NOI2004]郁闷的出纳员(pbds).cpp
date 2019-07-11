#pragma GCC optimize ("O10000")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;  
using namespace __gnu_pbds;  
int n,m,k,s,ans;  
struct node
{
    int v,id;  
    node(int a,int b){v=a;id=b;}  
    bool operator >(node b) const{return v==b.v?id>b.id:v>b.v;}
};  
tree<node,null_type,greater<node>,rb_tree_tag,tree_order_statistics_node_update>T,TE;  
inline int read()
{
    int x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=false;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return f?x:-x;
}
int main()
{  
    char c[10];  
    scanf("%d%d",&n,&m);  
    while(n--)
    {
        scanf("%s",c);
        k=read();
        if(*c=='I'){k+=s;if(k>=m)T.insert(node(k,n));}  
        else if(*c=='A') m-=k,s-=k;  
        else if(*c=='S'){m+=k,s+=k;T.split(node(m,-1),TE);ans+=TE.size();}
        else if(*c=='F')printf(k>(int)T.size()?"-1\n":"%d\n",T.find_by_order(k-1)->v-s);  
    }  
    printf("%d\n",ans);  
    return 0;  
}  