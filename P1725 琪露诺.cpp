#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int a[N],n,L,R,f[N];
deque< pair<int,int> >q;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    arg=x*f;
    read(args...);
}
int main()
{
	read(n,L,R);
	for(int i=0;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=R-L+1;i++)
		q.push_back(make_pair(n+i,0));
	for(int i=n;i>=0;i--)
	{
		if(q.back().first>R+i) q.pop_back();
		while(f[i+L]+a[i+L]>q.front().second&&!q.empty())
			q.pop_front();
		q.push_front(make_pair(i+L,f[i+L]+a[i+L]));
		f[i]=q.back().second;
	}
	cout<<f[0]<<endl;
    return 0;
}