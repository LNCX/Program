#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
bool bb[9],b[50000];//�������� 
int MS[9];//������Ҫת������ħ��״̬ 
char re[10];//������� 
struct node{    //ÿ������ʾ��ħ���״̬ 
    int a[9];    //ħ���ϵ����� 
    int step,father;//�ѱ任��������ǰ�� 
    char c;//��һ������ת�� 
}l[50000];//�ܹ�ֻ��40000�������У����Զ��в��ؿ��ܴ� 

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
}//ͨ����������Ŀ��ڵ��ǰ�����л������ 

int fc(int x){        //�׳� 
    if(x==0)return 0;
    if(x==1)return 1;
    return x*fc(x-1);
}
inline int KT(node x){        //����չ�������� 
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
    l[1].father=0;//��ʼ�� 
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
                l[tail].father=head;//��¼��״̬��ǰ����ǰһ���� 
                l[tail].c=i+'A'-1;
            }
        }
    }while(head<tail);//bfs�İ��� 
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
    return x;//��Ŀ��˵���ֱ任 
}
