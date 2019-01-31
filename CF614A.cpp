#include<bits/stdc++.h>
using namespace std;
long double l,r,w,cnt,wn=1;
int main()
{
    cin>>l>>r>>w;
    if(w==1)
    {
        if(l==1)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
        return 0;
    }
    while(wn<l)
        wn*=w;
    while(wn>=l&&wn<=r)
    {
        cout<<(long long)wn<<' ';
        wn*=w;cnt++;
    }
    if(!cnt)
        cout<<-1<<endl;
    else
        cout<<endl;
    return 0;
}