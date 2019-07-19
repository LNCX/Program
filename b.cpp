#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long LL;
const int MxN=1e6+10086,inf=192608170;
using namespace std;
inline int read(){
    int ans=0,b=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')b=-1;else b=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ans=ans*10+ch-48;ch=getchar();}
    return ans*b;
}
class Splay{
#define si(x) node[x].si
#define va(x) node[x].va
#define fa(x) node[x].fa
#define sm(x) node[x].sm
#define tP(x) node[x].tagPlus
#define sn(x,i) node[x].ch[i]
#define ls sn(x,0)
#define rs sn(x,1)
public:
    Splay(){
        size=root=top=1;va(1)=inf;
        newNode(sn(1,0),1,-inf);
        pushUp(1);size++;
    }
    int ask(int k){
        return va(fnd(k));
    }
    int insert(int k){
        int p=pre(k),s=suc(k);
        splay(p),splay(s,p);
        if(sn(s,0))sm(sn(s,0))++;
        else newNode(sn(s,0),s,k);
        pushUp(s),pushUp(p);
        splay(sn(s,0));
        size++;
        return 0;
    }
    int remove(int k){
        int p=pre(k),s=suc(k);
        splay(s),splay(p,s);
        if(sn(p,1))splay(sn(p,1));
        th.push(sn(root,0));
        size-=si(sn(root,0))-1;
        leave+=si(sn(root,0))-1;   
        newNode(sn(root,0),root,-inf);
        pushUp(root);
        return 0;
    }
    int add(int v){
        return va(root)+=v,tP(root)+=v,0;
    }
    int del(int v){
        return va(root)-=v,tP(root)-=v,0;
    }
    int fnd(int k){
        int x=root;
        while(!pushDown(x)){
            if(ls&&si(ls)>=k)x=ls;
            else if(rs&&si(ls)+sm(x)<k)k-=si(ls)+sm(x),x=rs;
            else return x;
        }
        return x;
    }
    int rnk(int k){
        int x=root;
        while(!pushDown(x)&&sn(x,k>va(x))&&k!=va(x))x=sn(x,k>va(x));
        splay(x);
        return si(sn(x,0));
    }
    int pre(int k){
        rnk(k);
        if(va(root)<k)return root;
        int x=sn(root,0);
        while(rs)pushDown(x),x=rs;
        return x;
    }
    int suc(int k){
        rnk(k);
        if(va(root)>k)return root;
        int x=sn(root,1);
        while(ls)pushDown(x),x=ls;
        return x;
    }
    int rt(){
        return root;
    }
    int sz(){
        return size;
    }
    int lv(){
        return leave;
    }
private:
    int root,size,top,leave;
    struct Node{
        int ch[2],si,va,fa,sm,tagPlus;
    }node[MxN];
    queue<int>th;
    int ws(int x){
        return x==sn(fa(x),1);
    }
    int rotate(int x){
        int f=fa(x),ff=fa(f),h=ws(x),w=sn(x,h^1);
        sn(f,h)=w;fa(w)=f;
        sn(ff,ws(f))=x;fa(x)=ff;
        sn(x,h^1)=f;fa(f)=x;
        return pushUp(f),pushUp(x);
    }
    int splay(int x,int pos=0){
        for(;fa(x)!=pos;rotate(x))if(fa(fa(x))!=pos)rotate(ws(fa(x))==ws(x)?fa(x):x);
        if(pos==0)root=x;return 0;
    }
    int pushUp(int x){
        return si(x)=si(ls)+si(rs)+sm(x),0;
    }
    int pushDown(int x){
        if(!x)return 1;
        if(!tP(x))return 0;
        if(ls)va(ls)+=tP(x),tP(ls)+=tP(x);
        if(rs)va(rs)+=tP(x),tP(rs)+=tP(x);
        return tP(x)=0;
    }
    int delNode(){
        if(th.empty())th.push(++top);
        int x=th.front();th.pop();
        if(ls)th.push(ls);
        if(rs)th.push(rs);
        ls=rs=tP(x)=0;
        return x;
    }
    int newNode(int &x,int f,int v){
        x=delNode();
        si(x)=sm(x)=1;
        va(x)=v;fa(x)=f;
        return x;
    }
#undef ls
#undef rs
#undef si
#undef va
#undef fa
#undef sm
#undef tP
#undef sn
}T;
int n,m,k;
char ch[10];
int main(int argc,char** argv){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        scanf("%s%d",ch,&k);
        switch(ch[0]){
            case('I'):if(k>=m)T.insert(k);break;
            case('A'):T.add(k);break;
            case('S'):T.del(k);T.remove(m);break;
            case('F'):if(T.sz()-2<k) puts("-1");else printf("%d\n",T.ask(T.sz()-k));break;
        }
    }
    printf("%d",T.lv());
}
