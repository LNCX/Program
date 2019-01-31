#include <time.h>
#include <iostream>

using namespace std;

# define      MAXN      100
int a[MAXN];
int counts=0;

void printtime(void) //打印当前时间的函数 
{ 
      char tmpbuf[128]; 
      time_t ltime; 
      struct tm *today;

      time(<ime); 
      today = localtime(<ime ); 
      strftime(tmpbuf,128,"%Y-%m-%d %H:%M:%S",today); 
      cout<<tmpbuf<<endl; 
}


void      comb(int m,int k)
{     int i,j;
      for (i=m;i>=k;i--)
      {     a[k]=i;
          if (k>1)
              comb(i-1,k-1);
          else
          {   
              counts++;
              /*
              for (j=a[0];j>0;j--)
                  printf("%4d",a[j]);
              printf("/n");
              */
          }
      }
}

int main()
{   

      int m,r;
      cout<<"m"<<endl;
      cin>>m;
      cout<<"r"<<endl;
      cin>>r;
      counts=0;
      a[0]=r;
      printtime();
      comb(m,r);
      cout<<counts<<endl;
      printtime();
      return 0;
}


