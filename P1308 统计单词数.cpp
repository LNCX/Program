#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int i,j,n,m;
    char word[12];
    char text[1000001];
    gets(word);
    gets(text);
    int lenw = strlen(word),lent = strlen(text);
    int count = 0,cur = -1;
    int sum=0;
    bool flag = true;
    for(i=0;i<lenw;i++)
        if(word[i] >= 'a' && word[i] <= 'z') 
            word[i] = word[i]&~(1<<5);
    for(i=0;i<lent;i++) 
        if(text[i] >= 'a' && text[i] <= 'z') 
            text[i] = text[i]&~(1<<5);
    for(i=0;i<=lent;i++)
    {
        for(j=0;j<lenw;j++)
            if(text[i+j]!= word[j]) flag = false; 
        if(flag) 
        {
            if((text[i-1] == ' ' && text[i+lenw] == ' ')|| i==0)
            {
                count++;
                if(cur==-1)
                    cur = i;
            }
        } 
        flag = true;
    }
    if(cur==-1) puts("-1");
    else printf("%d %d",count,cur);
    return 0;
}