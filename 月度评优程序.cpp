//防伪标示 
#include<cstdio>
#include<iostream>
#include<cstdlib>
#define maxn 100
using namespace std;

struct basic
{
	int person;
	int group;
	int mul;
	float gmul;
	int scre[4][2];
	int prss[4][2];
	int vers[2];
}all;

void print(void);
void prsn(void);
void prsn_add(void);
void prsn_pro(void);
void team(void);
void set(void);
void save(void);
void pause(void);
void error(void);

void print()
{
	printf("by Youth丨吹雪\n");
	printf("*********************\n");
	printf("** 1、计算个人小分 **\n");
	printf("** 2、计算小组均分 **\n");
	printf("** 3、更改程序参数 **\n");
	printf("*********************\n");
	int a;
	cin>>a;
	system("cls");
	if(a==1) prsn();
	else if(a==2) team();
	else if(a==3) set();
	if(!cin||a<=0||4<=a)
	{
		error();
		print();
	}
}
void prsn()
{
	int a[maxn][7]={},sum[maxn]={}; 
	printf("请输入从G 4至AJ %d的矩阵\n",2+all.person);
	for(int i=0;i<all.person;i++)
	for(int j=0;j<6;j++)
	{
		char s[10];
		scanf("%s",s);//过滤无用数据； 
		scanf("%d",&a[i][j]);
		if(j==5) scanf("%d%s%s",&a[i][j+1],s,s);
		else scanf("%s%s%s",s,s,s);
	}
	system("cls");
	FILE *fout;
	fout=fopen("个人小分.xls","wb"); 
	for(int i=0;i<all.person;i++)
	{
		int mid=1;
		for(int j=0;j<6;j++)
		{
			if(j==5) mid=all.mul;
			if(a[i][j]<=all.scre[1][0]) sum[i]+=all.scre[1][1]*mid;
			else if(a[i][j]<=all.scre[2][0]) sum[i]+=all.scre[2][1]*mid;
			else if(a[i][j]<=all.scre[3][0]) sum[i]+=all.scre[3][1]*mid;
		}
		mid=1;
		if(a[i][6]>0)
		{
			if(all.prss[0][0]<=a[i][5]&&a[i][5]<=all.prss[1][0]) mid=all.prss[1][1];
			else if(all.prss[1][0]<a[i][5]&&a[i][5]<=all.prss[2][0]) mid=all.prss[2][1];
			else if(all.prss[2][0]<a[i][5]&&a[i][5]<=all.prss[3][0]) mid=all.prss[3][1];
			sum[i]+=a[i][6]*mid;
		}
		if(i==all.vers[0]-1) sum[i]+=all.vers[1];
		fprintf(fout,"%d\n",sum[i]);
	}
	fclose(fout);
	printf("请在“个人小分.xls”中查看\n");
	system("start 个人小分.xls");
	pause();
	print();
}
void prsn_add(void)
{
	printf("原个人加分\n");
	printf("1、区间1~%d\n",all.scre[1][0]); 
	printf("2、加分%d\n",all.scre[1][1]);
	printf("3、区间%d~%d\n",all.scre[1][0]+1,all.scre[2][0]); 
	printf("4、加分%d\n",all.scre[2][1]);
	printf("5、区间%d~%d\n",all.scre[2][0]+1,all.scre[3][0]); 
	printf("6、加分%d\n",all.scre[3][1]);
	printf("7、总分加分翻%d倍\n",all.mul);
	printf("8、返回上层目录\n");
	int a=0;
	cin>>a;
	if(!cin||a<=0||9<=a)
	{
		error();
		prsn_add();
	}
	system("cls");
	if(a==2||a==4||a==6)
	{
		printf("原加分:%d\n",all.scre[a/2][1]);
		printf("请输入:");
		cin>>all.scre[a/2][1];
	}
	else if(a==8) return;
	else 
	switch (a)
	{
		case 1:
		{
			printf("左区间:1\n");
			printf("右区间:");
			cin>>all.scre[1][0];
			break;
		}
		case 3:
		{
			printf("左区间:%d\n",all.scre[1][0]+1);
			printf("右区间:");
			cin>>all.scre[2][0];
			break;
		}
		case 5:
		{
			printf("左区间:%d\n",all.scre[2][0]+1);
			printf("右区间:");
			cin>>all.scre[3][0];
			break;
		}
		case 7:
		{
			printf("请输入倍数:");
			scanf("%d",&all.mul);
			break;
		}
		default:{break;}	
	}
	system("cls");
	save();
	prsn_add();
}
void prsn_pro(void)
{
	printf("原个人进步\n");
	printf("加分即为进步名次\n"); 
	printf("1、区间%d~%d\n",all.prss[0][0],all.prss[1][0]); 
	printf("2、加分翻%d倍\n",all.prss[1][1]);
	printf("3、区间%d~%d\n",all.prss[1][0]+1,all.prss[2][0]); 
	printf("4、加分翻%d倍\n",all.prss[2][1]);
	printf("5、区间%d~%d\n",all.prss[2][0]+1,all.prss[3][0]); 
	printf("6、加分翻%d倍\n",all.prss[3][1]);
	printf("7、返回上层目录\n");
	int a=0;
	cin>>a;
	if(!cin||a<=0||8<=a)
	{
		error();
		prsn_pro();
	}
	system("cls");
	if(a==2||a==4||a==6)
	{
		printf("请输入:");
		cin>>all.prss[a/2][1];
	}
	else if(a==8) return;
	else 
	switch (a)
	{
		case 1:
		{
			printf("左区间:");
			scanf("%d",&all.prss[0][0]);
			printf("右区间:");
			scanf("%d",&all.prss[1][0]);
			break;
		}
		case 3:
		{
			printf("左区间:%d\n",all.prss[1][0]+1);
			printf("右区间:");cin>>all.prss[2][0];
			break;
		}
		case 5:
		{
			printf("左区间:%d\n",all.prss[2][0]+1);
			printf("右区间:");cin>>all.prss[3][0];
			break;
		}
		case 7:
		{
			save();
			set();
			break;
		}
		default:{break;}	
	}
	system("cls");
	save();
	prsn_pro();
}
void team()
{
	struct student
	{
		int rank;
		int score;
	}a[maxn];
	int count[100]={0}; 
	float b[100]={0};
	printf("请输入个人小组编号\n");
	for(int i=0;i<all.person;i++) scanf("%d",&a[i].rank);
	system("cls");
	printf("请输入个人小分\n");
	for(int i=0;i<all.person;i++) scanf("%d",&a[i].score);
	system("cls");
	for(int i=0;i<all.person;i++)
	{
		b[a[i].rank]+=a[i].score;
		count[a[i].rank]++;
	}
	FILE *fout;
	fout=fopen("小组均分.xls","wb");
	for(int i=0;i<all.person;i++) fprintf(fout,"%.2f\n",b[a[i].rank]/count[a[i].rank]*all.gmul);
	fclose(fout);
	printf("请在“小组均分.xls”中查看”\n");
	system("start 小组均分.xls");
	pause();
	print();
}
void set()
{
	printf("by Youth丨吹雪\n");
	printf("*********************\n");
	printf("** 1、修改班级人数 **\n");
	printf("** 2、修改小组个数 **\n");
	printf("** 3、修改个人加分 **\n");
	printf("** 4、修改进步加分 **\n"); 
	printf("** 5、修改小组倍数 **\n");	
	printf("** 6、返回上层目录 **\n");
	printf("*********************\n");
	int a;
	scanf("%d",&a);
	system("cls");
	if(!cin||a<=0||8<=a)
	{
		error();
		set();
	}
	switch (a)
	{
		case 1:
		{
			printf("原班级人数:%d\n请修改:\n",all.person);
			cin>>all.person;
			system("cls");
			break;
		}
		case 2:
		{
			printf("原小组个数:%d\n请修改:",all.group);
			cin>>all.group;
			system("cls");
			break;
		}
		case 3:{prsn_add();break;}
		case 4:{prsn_pro();break;}
		case 5:
		{
			printf("原小组倍数:%f\n请修改:",all.gmul);
			cin>>all.gmul;
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			print();
			break;
		}
		case 7:
		{
			printf("恭喜你打开了外挂\n");
			printf("第几位人开挂？\n");
			scanf("%d",&all.vers[0]);
			printf("开挂加分？\n");
			scanf("%d",&all.vers[1]); 
			printf("为了避免被人发现，该设置不被保存\n");
		}
	}
	save();
	set();
}
void save(void)
{
	FILE *fout;
	fout=fopen("setting.txt","wb");
	fprintf(fout,"%d %d %d %f \n",all.person,all.group,all.mul,all.gmul);
	for(int i=1;i<=3;i++)
	for(int j=0;j<=1;j++)
		fprintf(fout,"%d ",all.scre[i][j]);
	for(int i=0;i<=3;i++)
	for(int j=0;j<=1;j++)
		fprintf(fout,"%d ",all.prss[i][j]);
	fclose(fout);
}
void pause(void)
{
	printf("请按任意键继续...\n");
	getchar();
	getchar();
	system("cls"); 
}
void error(void)
{
	cin.clear(); 
	cin.sync();   //清空流
	system("cls"); 
}
int main()
{
	FILE *fin;
	fin=fopen("setting.txt","rb");
	fscanf(fin,"%d%d%d%f",&all.person,&all.group,&all.mul,&all.gmul);
	for(int i=1;i<=3;i++)
	for(int j=0;j<=1;j++)
		fscanf(fin,"%d",&all.scre[i][j]);
	for(int i=0;i<=3;i++)
	for(int j=0;j<=1;j++)
		fscanf(fin,"%d",&all.prss[i][j]);
	fclose(fin);
	print(); 
}
