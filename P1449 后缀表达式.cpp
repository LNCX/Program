#include <bits/stdc++.h>
using namespace std;
stack<int> n;
char c;
int main()
{
    int s=0,a,b;
    while(c!='@')
    {
        c=getchar();
        if(c=='+')a=n.top(),n.pop(),b=n.top(),n.pop(),n.push(a+b);
        else if(c=='-')a=n.top(),n.pop(),b=n.top(),n.pop(),n.push(b-a);
        else if(c=='*')a=n.top(),n.pop(),b=n.top(),n.pop(),n.push(a*b);
        else if(c=='/')a=n.top(),n.pop(),b=n.top(),n.pop(),n.push(b/a);
        else if(c=='.')n.push(s),s=0;
        else s=s*10+c-'0';
    }
    printf("%d\n",n.top());
    return 0;
}