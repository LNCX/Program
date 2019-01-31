#include<bits/stdc++.h>
using namespace std;
int s[101],b[101],n,m,A,B;
int main()
{
    scanf("%d%d%d",&A,&B,&n);
    for (int i=1;i<=n;i++)
     scanf("%d",&s[i]);
    s[n+1]=0; 
    s[n+2]=990; 
    s[n+3]=1010; 
    s[n+4]=1970;
    s[n+5]=2030;
    s[n+6]=2940;
    s[n+7]=3060;
    s[n+8]=3930;
    s[n+9]=4060;
    s[n+10]=4970;
    s[n+11]=5030;
    s[n+12]=5990;
    s[n+13]=6010;
    s[n+14]=7000;  
    n+=14;  
    sort(s+1,s+1+n);
    b[1]=1; 
    for (int i=2;i<=n;i++)  
     for (int j=1;j<=i-1;j++) 
      if (s[i]-s[j]>=A&&s[i]-s[j]<=B) 
       b[i]+=b[j];  
    cout<<b[n]<<endl;
}
