#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
LL z,x,f[N];
int k,n,m,l[N],r[N];
int main()
{
    scanf("%d%lld%d%d",&k,&x,&n,&m);
    for(int i=0;i<=n/2;i++)
    for(int j=0;j<=m/2;j++)
        for(int a=0;a<2;a++) for(int b=0;b<2;b++)
        for(int c=0;c<2;c++) for(int d=0;d<2;d++)
        {
            if(i*2+a+b>n||j*2+c+d>m)continue;
            f[1]=i;f[2]=j;f[3]=i+j;l[2]=c;r[2]=d;
            if(b==1&&c==1) f[3]++;
            l[3]=a;r[3]=d;
            for(z=4;z<=k;z++)
            {
                f[z]=f[z-1]+f[z-2];
                l[z]=l[z-2];
                r[z]=r[z-1];
                if(r[z-2]==1 && l[z-1]==1) f[z]++;
            }
            if(f[k]==x)
            {
                if(a==1) printf("C");
                for(int o=1;o<=i;o++)
                    printf("AC");
                for(int p=a+i*2;p<n-b;p++)
                    printf("M");
                if(b==1) printf("A");
                printf("\n");
                if(c==1) printf("C");
                for(int o=1;o<=j;o++)
                    printf("AC");
                for(int p=c+j*2;p<m-d;p++)
                    printf("M");
                if(d==1) printf("A");
                printf("\n");
                return 0;
            }
        }
    puts("Happy new year!");
    return 0;
}