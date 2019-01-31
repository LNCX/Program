#include<stdio.h>
int main()
{
    char sex[10];
    double m[45],f[45],num,t;
    int n,m1,f1,i,j;
    scanf("%d",&n);
    for (i=0,m1=0,f1=0;i<n;i++)
    {
        scanf("%s %lf",sex,&num);
        if (sex[0]=='m')
        {
            m[m1]=num;
            m1++;
        }
        if (sex[0]=='f')
        {
            f[f1]=num;
            f1++;
        }
    }
    for (i=0;i<m1-1;i++)
    {
        for (j=0;j<m1-i-1;j++)
        {
            if (m[j]>m[j+1])
            {
                t=m[j];m[j]=m[j+1];m[j+1]=t;
            }
        }
    }
    for (i=0;i<f1-1;i++)
    {
        for (j=0;j<f1-i-1;j++)
        {
            if (f[j]<f[j+1])
            {
                t=f[j];f[j]=f[j+1];f[j+1]=t;
            }
        }
    }
    for (i=0;i<m1;i++)
    {
        printf("%.2lf ",m[i]);
    }
    for (i=0;i<f1;i++)
    {
        printf("%.2lf ",f[i]);
    }
    return 0;
}
