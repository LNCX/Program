#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
//¡ö
int map[6][11];
void gotoxy()//Î»ÖÃº¯Êý
{
	int x=0,y=0;
	COORD pos;
	pos.X=2*x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void print(int x,int y)
{
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=10; j++)
			if(i!=x||j!=y)
				printf("¡ö");
			else printf("  ");
		printf("\n");
	}
}
int main()
{
	int a=1,b=1;
	gotoxy();
	print(a,b);
	while(1)
	{
		getch();
		int c=getch();
		switch (c)
		{
			case 72://up
				if(a>1)
				{
					gotoxy();
					print(--a,b);
				}
			break;
			case 80://down
				if(a<5)
				{
					gotoxy();
					print(++a,b);
				}
			break;
			case 75://left
				if(b>1)
				{
					gotoxy();
					print(a,--b);
				}
			break;
			case 77://right
				if(b<10)
				{
					gotoxy();
					print(a,++b);
				}
			break;
		}
	}
	return 0;
}
