#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int N=1015;
struct mrz_p
{
    string na;
    char FM;
    int a,b;
    double score;
    int aa[N],bb[N];
} p[N>>1];
int rate[N>>1],Mp[N*10],Op[N*10];
int T,n,m,n_M,n_O,n_gr;
string gn[N>>1],pn[N>>1],ptn[N>>1];
void ini()
{
    memset(p,0,sizeof(p));
    memset(Mp,0,sizeof(Mp));
    memset(Op,0,sizeof(Op));
    memset(rate,0,sizeof(rate));
    // memset(gn,0,sizeof(gn));
    // memset(pn,0,sizeof(pn));
    // memset(ptn,0,sizeof(ptn));
    return;
}
void read()
{
    int k;
    cin>>n>>m>>n_M;
    for(int i=1;i<=n_M;i++) 
    {
        cin>>k;
        Mp[k]=1;
    }
    cin>>n_O;
    for(int i=1;i<=n_O;i++) 
    {
        cin>>k;
        Op[k]=1;
    }
    cin>>n_gr;
    // exit(0);
    for(int i=1;i<=n_gr;i++) 
    {
        // cerr << "!!" << i << "!!" << endl;
        // string tmp;
        // cin>>tmp;
        // gn[i] = tmp;
        cin>>gn[i];
        cin>>rate[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>pn[i]>>ptn[i];
        p[i].na=pn[i];
        cin>>p[i].FM;
        cin>>p[i].a>>p[i].b;
        for(int j=1;j<=p[i].a;j++) cin>>p[i].aa[j];
        for(int j=1;j<=p[i].b;j++) cin>>p[i].bb[j];
    }
    return;
}
bool check(int k)
{
    for(int i=2;i<=k>>1+1;i++) if(k%i==0) return false;
    return true;
}
bool cmpa(int k1,int k2)
{
    return k1>k2;
}
bool cmpb(mrz_p k1,mrz_p k2)
{
    return k1.score>k2.score;
}
double co(int k)
{
    double ret=0;
    if(p[k].FM=='F') ret+=33;
    for(int i=1;i<=n_gr;i++) if(ptn[k]==gn[i])
    {
        if(rate[i]==1) ret+=36;
        else if(rate[i]==2) ret+=27;
        else if(rate[i]==3) ret+=18;
        break;
    }
    for(int i=1;i<=p[k].a;i++)
    {
        if(Mp[p[k].aa[i]]==1) ret+=2.5;
        else if(Op[p[k].aa[i]]==1) ret+=1.5;
        else if(check(p[k].aa[i])==true) ret+=1;
        else ret+=0.3;
    }
    sort(p[k].bb,p[k].bb+p[k].b+1,cmpa);
    ret+=max(0.0,(p[k].bb[3]-1200.0)/100.0)*1.5;
    return ret;
}
int main()
{
    cin>>T;
    for(int __i=1;__i<=T;__i++)
    {
        ini();
        read();
        for(int i=1;i<=n;i++) p[i].score=co(i);
        sort(p,p+n+1,cmpb);
        for(int i=1;i<=m;i++) cout<<pn[i]<<" "<<p[i].score<<endl;
    }
    return 0;
}