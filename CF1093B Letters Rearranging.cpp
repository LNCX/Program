#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[30]={0},flag=1;
        char s[1005];
        cin>>s;
        for(int i=1;i<strlen(s);i++)
            if(s[i]!=s[i-1])
                flag=0;
        if(flag) {cout<<-1<<endl;continue;}
        for(int i=0;i<strlen(s);i++)
            a[s[i]-'a']++;
        for(int i=0;i<26;i++)
            for(int j=1;j<=a[i];j++)
                printf("%c",i+'a');
        cout<<endl;
    }
    return 0;
}