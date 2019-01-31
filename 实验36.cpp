#include <cstdio>
#include <algorithm>
using namespace std;
struct P{
    int id;
    long long x;
    int fx;
    bool turn;
}a[10005],now[10005];//a数组用于保存，now数组用于计算
char s[2];
bool cmp(P p,P q){//排序还回去
    return p.id<q.id;
}
bool cmp2(P p,P q){//按照位置排序
    return p.x<q.x;
}
int main(){
    int test_number;
    int l,t,n;
    scanf("%d",&test_number);
    for(int k=1;k<=test_number;k++){
        scanf("%d%d%d",&l,&t,&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%s",&a[i].x,s);//读入
            if(s[0]=='L'){
                a[i].fx=-1;
            }
            else{
                a[i].fx=1;
            }
            a[i].turn=0;
            a[i].id=i;
        }
        for(int i=1;i<=n;i++){
            now[i]=a[i];
            now[i].x+=now[i].fx*t;//计算每只蚂蚁的位置
        }
        sort(a+1,a+1+n,cmp2);
        sort(now+1,now+1+n,cmp2);
        for(int i=1;i<=n;i++){
            if(i+1<=n&&now[i].x==now[i+1].x){
                now[i].turn=now[i+1].turn=1;
            }
            a[i].turn=now[i].turn;
            a[i].x=now[i].x;
            a[i].fx=now[i].fx;
        }//根据相对位置不改变来进行还原
        sort(a+1,a+1+n,cmp);
        printf("Case #%d:\n",k);
        for(int i=1;i<=n;i++){
            if(a[i].turn){
                printf("%lld Turning\n",a[i].x);
            }
            else if(a[i].x>l||a[i].x<0){
                puts("Fell off");
            }
            else if(a[i].fx==1){
                printf("%lld R\n",a[i].x);
            }
            else{
                printf("%lld L\n",a[i].x);
            }
        }//判断四种情况
        puts("");
    }
    return 0;
}
