#include<windows.h>
#include<cstdio>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
void luogu()
{
	ShellExecute(NULL, ("open"), ("chrome.exe"), ("http://www.luogu.org"), NULL, SW_SHOW);
}
void libreoj()
{
	ShellExecute(NULL, ("open"), ("chrome.exe"), ("http://www.loj.ac"), NULL, SW_SHOW);
}
void openjudge()
{
	ShellExecute(NULL, ("open"), ("chrome.exe"), ("http://www.noi.openjudge.cn"), NULL, SW_SHOW);
}
void timer()
{
	system("start \\C++\\timer.exe");
}
int read()
{
	int ch=(int)getch();
	if(ch==27) return 0;
	if(ch==121) return 1;
	return 3; 
}
void dev()
{
	system("start \\C++\\Dev-C++\\devcppPortable.exe");
	char *source="\\C++\\Dev-C++\\zlib1.dll";
    char *destination="C:\\Windows\\System32\\zlib1.dll";
    CopyFile(source,destination,FALSE);
}
int main()
{
	printf("Open Timer\n");
	int ch=read();
	if(ch==0){dev();return 0;}
	else if(ch==1)	timer();
	
	printf("Opne Luogu\n");
	ch=read();
	if(ch==0){dev();return 0;}
	else if(ch==1)	luogu();
	
	printf("Open Libreoj\n");
	ch=read();
	if(ch==0){dev();return 0;}
	else if(ch==1)	libreoj();
	
	printf("Open Openjudge\n");
	ch=read();
	if(ch==0){dev();return 0;}
	else if(ch==1)	openjudge();
	
	dev();
}

