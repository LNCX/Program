#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct lint
{
    int len,num[N];
    friend lint operator +(lint a,lint b)
    {
        lint res;res.len=1;
        memset(res.num,0,sizeof(res.num));
        while(res.len<=a.len||res.len<=b.len)
        {
            res.num[res.len]+=a.num[res.len]+b.num[res.len];
            res.num[res.len+1]+=res.num[res.len]/10;
            res.num[res.len]%=10;
            res.len++;
        }
        while(res.len>1&&res.num[res.len]==0) res.len--;
        return res;
    }
    friend bool operator <(lint a,lint b)
    {
        if(a.len<b.len) 
            return true;
        if(a.len>b.len) 
            return false;
        for(int i=a.len;i>=1;i--)
        {
            if(a.num[i]<b.num[i]) return true;
            if(a.num[i]>b.num[i]) return false;
        }
        return false;
    }
    void print()
    {
        for(int i=len;i>=1;i--)
            printf("%d",num[i]);
        puts("");
    }
};
lint turn(string a)
{
    lint res;
    res.len=a.length();
    for(int i=1;i<=res.len;i++)
        res.num[i]=a[res.len-i]-'0';
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
int n;
string s;
int main()
{
    cin>>n>>s;
    if(n%2==0)
    {
        lint res=turn(s.substr(0,n/2))+turn(s.substr(n/2,n/2));
        res.print();
    }
    else 
    {
        lint a=turn(s.substr(0,n/2))+turn(s.substr(n/2,n-n/2));
        lint b=turn(s.substr(0,n/2+1))+turn(s.substr(n/2+1,n-n/2-1));
        if(b<a)swap(a,b);
        a.print();
    }
    return 0;
}