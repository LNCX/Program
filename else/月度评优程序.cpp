//��α��ʾ 
#include<cstdio>
#include<iostream>
#include<cstdlib>
#define N 100
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
	printf("by Youthح��ѩ\n");
	printf("*********************\n");
	printf("** 1���������С�� **\n");
	printf("** 2������С����� **\n");
	printf("** 3�����ĳ������ **\n");
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
	int a[N][7]={},sum[N]={}; 
	printf("�������G 4��AJ %d�ľ���\n",2+all.person);
	for(int i=0;i<all.person;i++)
	for(int j=0;j<6;j++)
	{
		char s[10];
		scanf("%s",s);//�����������ݣ� 
		scanf("%d",&a[i][j]);
		if(j==5) scanf("%d%s%s",&a[i][j+1],s,s);
		else scanf("%s%s%s",s,s,s);
	}
	system("cls");
	FILE *fout;
	fout=fopen("����С��.xls","wb"); 
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
	printf("���ڡ�����С��.xls���в鿴\n");
	system("start ����С��.xls");
	pause();
	print();
}
void prsn_add(void)
{
	printf("ԭ���˼ӷ�\n");
	printf("1������1~%d\n",all.scre[1][0]); 
	printf("2���ӷ�%d\n",all.scre[1][1]);
	printf("3������%d~%d\n",all.scre[1][0]+1,all.scre[2][0]); 
	printf("4���ӷ�%d\n",all.scre[2][1]);
	printf("5������%d~%d\n",all.scre[2][0]+1,all.scre[3][0]); 
	printf("6���ӷ�%d\n",all.scre[3][1]);
	printf("7���ּܷӷַ�%d��\n",all.mul);
	printf("8�������ϲ�Ŀ¼\n");
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
		printf("ԭ�ӷ�:%d\n",all.scre[a/2][1]);
		printf("������:");
		cin>>all.scre[a/2][1];
	}
	else if(a==8) return;
	else 
	switch (a)
	{
		case 1:
		{
			printf("������:1\n");
			printf("������:");
			cin>>all.scre[1][0];
			break;
		}
		case 3:
		{
			printf("������:%d\n",all.scre[1][0]+1);
			printf("������:");
			cin>>all.scre[2][0];
			break;
		}
		case 5:
		{
			printf("������:%d\n",all.scre[2][0]+1);
			printf("������:");
			cin>>all.scre[3][0];
			break;
		}
		case 7:
		{
			printf("�����뱶��:");
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
	printf("ԭ���˽���\n");
	printf("�ӷּ�Ϊ��������\n"); 
	printf("1������%d~%d\n",all.prss[0][0],all.prss[1][0]); 
	printf("2���ӷַ�%d��\n",all.prss[1][1]);
	printf("3������%d~%d\n",all.prss[1][0]+1,all.prss[2][0]); 
	printf("4���ӷַ�%d��\n",all.prss[2][1]);
	printf("5������%d~%d\n",all.prss[2][0]+1,all.prss[3][0]); 
	printf("6���ӷַ�%d��\n",all.prss[3][1]);
	printf("7�������ϲ�Ŀ¼\n");
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
		printf("������:");
		cin>>all.prss[a/2][1];
	}
	else if(a==8) return;
	else 
	switch (a)
	{
		case 1:
		{
			printf("������:");
			scanf("%d",&all.prss[0][0]);
			printf("������:");
			scanf("%d",&all.prss[1][0]);
			break;
		}
		case 3:
		{
			printf("������:%d\n",all.prss[1][0]+1);
			printf("������:");cin>>all.prss[2][0];
			break;
		}
		case 5:
		{
			printf("������:%d\n",all.prss[2][0]+1);
			printf("������:");cin>>all.prss[3][0];
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
	}a[N];
	int count[100]={0}; 
	float b[100]={0};
	printf("���������С����\n");
	for(int i=0;i<all.person;i++) scanf("%d",&a[i].rank);
	system("cls");
	printf("���������С��\n");
	for(int i=0;i<all.person;i++) scanf("%d",&a[i].score);
	system("cls");
	for(int i=0;i<all.person;i++)
	{
		b[a[i].rank]+=a[i].score;
		count[a[i].rank]++;
	}
	FILE *fout;
	fout=fopen("С�����.xls","wb");
	for(int i=0;i<all.person;i++) fprintf(fout,"%.2f\n",b[a[i].rank]/count[a[i].rank]*all.gmul);
	fclose(fout);
	printf("���ڡ�С�����.xls���в鿴��\n");
	system("start С�����.xls");
	pause();
	print();
}
void set()
{
	printf("by Youthح��ѩ\n");
	printf("*********************\n");
	printf("** 1���޸İ༶���� **\n");
	printf("** 2���޸�С����� **\n");
	printf("** 3���޸ĸ��˼ӷ� **\n");
	printf("** 4���޸Ľ����ӷ� **\n"); 
	printf("** 5���޸�С�鱶�� **\n");	
	printf("** 6�������ϲ�Ŀ¼ **\n");
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
			printf("ԭ�༶����:%d\n���޸�:\n",all.person);
			cin>>all.person;
			system("cls");
			break;
		}
		case 2:
		{
			printf("ԭС�����:%d\n���޸�:",all.group);
			cin>>all.group;
			system("cls");
			break;
		}
		case 3:{prsn_add();break;}
		case 4:{prsn_pro();break;}
		case 5:
		{
			printf("ԭС�鱶��:%f\n���޸�:",all.gmul);
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
			printf("��ϲ��������\n");
			printf("�ڼ�λ�˿��ң�\n");
			scanf("%d",&all.vers[0]);
			printf("���Ҽӷ֣�\n");
			scanf("%d",&all.vers[1]); 
			printf("Ϊ�˱��ⱻ�˷��֣������ò�������\n");
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
	printf("�밴���������...\n");
	getchar();
	getchar();
	system("cls"); 
}
void error(void)
{
	cin.clear(); 
	cin.sync();   //�����
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
