#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node 
{
    int val,arr[30];
    node() 
    {
        val=0;
        memset(arr,0,sizeof(arr));
    }
}ch[N*2];
int top,len,n,k;
char s[N];
void insert(int x, int d) 
{
    if(d==len)
        return;
    int mv=s[d]-'a';
    if (ch[x].arr[mv]==0)
        ch[x].arr[mv]=++top;
    insert(ch[x].arr[mv],d+1);
}
int solve(int x) 
{
    int& ans=ch[x].val;
    ans=0;
    bool flag=true;
    for(int i=0;i<26;i++) 
    {
        if(ch[x].arr[i]) 
        {
            flag=false;
            ans|=solve(ch[x].arr[i]);
        }
    }
    if(flag) ans=1;
    return 3-ans;
}
int main () 
{
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++) 
    {
        scanf("%s",s);
        len=strlen(s);
        insert(0, 0);
    }
    solve(0);
    int ans=ch[0].val;
    if(ans<2) printf("Second\n");
    else if (ans==2) printf("%s\n",k&1?"First":"Second");
    else printf("First\n");
    return 0;
}
