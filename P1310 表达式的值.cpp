#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=1e4+7;
int l,f[maxn][2],popf=0,pop=0;
char p[maxn],a[maxn],ch;
void push()
{
    popf++;
    f[popf][0]=1;
    f[popf][1]=1;
}
void push(char x)
{
    pop++;p[pop]=x;
}
void work(char c)
{
    int x=f[popf][0],y=f[popf][1];
    int p=f[popf-1][0],q=f[popf-1][1];
    popf--;
    if(c=='+')
    {
        f[popf][0]=(x*p)%mod;
        f[popf][1]=(x*q+y*p+y*q)%mod;
    }
    if(c=='*')
    {
        f[popf][0]=(x*p+x*q+y*p)%mod;
        f[popf][1]=(y*q)%mod;
    }
}
int main()
{
    scanf("%d%s",&l,a);
    if(a[0]!='(')push(); 
    for(int i=0;i<l;i++)
    {
        ch=a[i];
        if(ch=='+')
        {
            char c=p[pop];
            while(c=='*')
              {work(c);pop--,c=p[pop];}
            push(ch);
            if(a[i+1]!='(')
              push();
        }
        else if(ch=='(')
        {
            push(ch);
            if(a[i+1]!='(')
              push();
        }
        else if(ch=='*')
        {
            push(ch);
            if(a[i+1]!='(')
              push();
        }
        else if(ch==')')
        {
            char c=p[pop];
            while(c!='(')
            {
                work(c);
                pop--;
                c=p[pop];
            }
            pop--;
        }
    }
    while(pop)
    {
        work(p[pop]);
        pop--;
    }
    cout<<f[1][0]<<endl;
    return 0;
}