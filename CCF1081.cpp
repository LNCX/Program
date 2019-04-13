#include<cstdio>
#include<cstring>
char a[200],t[200],x,y;
int p1,p2,p3,len,i;
void dd(char x,char y){
	if(x==y-1)
		return;
	int i,j,p=0;
	for(i=x+1;i<=y-1;i++)
		for(j=1;j<=p2;j++){
			if(p1==1)
				t[++p]=i;
			if(p1==2){
				if(i>96&&i<123)
					t[++p]=i-32;
				else
					t[++p]=i;
			}
			if(p1==3)
				t[++p]='*';
		}
	if(p3==1)
		for(i=1;i<=p;i++)
			printf("%c",t[i]);
	else
		for(i=p;i>=1;i--)
			printf("%c",t[i]);
}
int main(){
	scanf("%d%d%d%s",&p1,&p2,&p3,a+1);
	len=strlen(a+1);
	for(i=1;i<=len;i++)
		if(a[i]=='-'){
			x=a[i-1];
			y=a[i+1];
			if((x>96&&y<123&&x<y)||(x>47&&y<58&&x<y))
				dd(x,y);
			else
				printf("%c",a[i]);
		}
		else
			printf("%c",a[i]);
	return 0;
}
