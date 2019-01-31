#include<stdio.h>
int main()
{ 
    int m=0,t,n,s=0,i;int a;
    bool enough=true;
    for(i=1;i<=12;i++)
    { 
        scanf("%d",&t);
        m=m+300-t;
        if(m>=0){n=m/100;m=m-n*100;s=s+100*n;}
	    else{printf("-%d",i);enough=false;break;}
    }
    if(enough)
    {
        a=s*1.2+m;
        printf("%d",a);
    }
}
