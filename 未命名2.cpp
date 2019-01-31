#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
bool bb[9],b[50000];//判重数组 
int MS[9];//我们需要转换到的魔板状态 
char re[10];//用于输出 
struct node{    //每个结点表示该魔板的状态 
    int a[9];    //魔板上的数字 
    int step,father;//已变换步数和其前驱 
    char c;//上一步做的转换 
}l[50000];//总共只有40000多种排列，所以队列不必开很大 

void print(node x){
    int s=0;
    while(x.father!=0){
        re[++s]=x.c;
        x=l[x.father];
    }
    for(int i=s;i>=1;i--){
        printf("%c",re[i]);
    }
    return;
}//通过反复调用目标节点的前驱进行回溯输出 

int fc(int x){        //阶乘 
    if(x==0)return 0;
    if(x==1)return 1;
    return x*fc(x-1);
}
inline int KT(node x){        //康拓展开在这里 
    int num=0;
    for(int i=1;i<=8;i++){
        int s=0;
        for(int j=i+1;j<=8;j++){
            if(x.a[i]>x.a[j])s++;
        }
        num+=s*fc(8-i);
    }
    return num;
}
inline void swapp(int &a,int &b) 
{int c=a;a=b;b=c;}
node A(node),B(node),C(node);

int main(){
    for(int i=1;i<=8;i++)scanf("%d",&MS[i]);
    int head=0,tail=1;
    for(int i=1;i<=9;i++)l[1].a[i-1]=i-1;
    l[1].step=0;
    l[1].father=0;//初始化 
    do
    {
        head++;
        int flag=1;
        for(int i=1;i<=8;i++){
            if(l[head].a[i]!=MS[i]){
                flag=0;break;
            }
        }
        if(flag){
            printf("%d\n",l[head].step);
            print(l[head]);
            return 0;
        }

        for(int i=1;i<=3;i++){
            node k;
            if(i==1)k=A(l[head]);
            if(i==2)k=B(l[head]);
            if(i==3)k=C(l[head]);
            int kk=KT(k);
            if(!b[kk]){
                b[kk]=1;
                tail++;
                l[tail]=k;
                l[tail].step++;
                l[tail].father=head;//记录该状态的前驱（前一步） 
                l[tail].c=i+'A'-1;
            }
        }
    }while(head<tail);//bfs的板子 
    printf("0");
    return 0;
}
node A(node x){
    for(int i=1;i<=4;i++)
        swapp(x.a[i],x.a[9-i]);
    return x;
}
node B(node x){
    for(int i=4;i>=2;i--){
        swapp(x.a[i-1],x.a[i]);
        swapp(x.a[9-i],x.a[10-i]);
    }
    return x;
}
node C(node x){
    swapp(x.a[3],x.a[2]);
    swapp(x.a[7],x.a[6]);
    swapp(x.a[2],x.a[6]);
    return x;//题目所说三种变换 
}
