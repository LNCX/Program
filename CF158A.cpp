#include<bits/stdc++.h>
using namespace std;
int a[51],n,k,s;
int main ()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int p=a[k];  
    for(int i=1;i<=n;i++) 
    {
        if(a[i]<=0)
        {
            printf("%d",s);  
            return 0;
        }
        if(s>=k)
        {
            if(p==a[i]) s++;  
            else break;  
        }  
        else s++;  
    }   
    printf("%d",s);  
    return 0;
}