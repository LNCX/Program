#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int count=0; 
int ranint(int a,int b)
{
	int r=rand()%(b-a+1)+a;
	return r; 
}
void prsn()
{
	int r=ranint(1,5); 
	if(r==1) cout<<"���������������½���";
	if(r==2) cout<<"����������������ߡ�";
	if(r==3) cout<<"�����ȶ���";
	if(r==4) cout<<"����ʱ�����ۡ�";

	r=ranint(1,4);
	if(r==1) cout<<"���ԳŽ��ۡ�";
	if(r==2) cout<<"���Գ�����30��ʱ�������Բ��㡣";
	if(r==3) cout<<"�ֱ۵õ��˳�ֵĶ�����";

	r=ranint(1,5);
	if(r==1) cout<<"�糿�ܲ��е�ͷ�Ρ�";
	if(r==2) cout<<"�ܲ���ǿ��ꡣ";
	if(r==3) cout<<"���ʱ�е��������ġ�";
	if(r==4) cout<<"���������ܲ���"; 
	
		
}
void pare()
{
	int r=ranint(1,4);
	if(r==1) cout<<"�㺢������������";
	if(r==2) cout<<"�㺢�����˸��Գš�";
	if(r==3) cout<<"�㺢������һ�Ჽ��"; 
	
	r=ranint(1,4);
	if(r==1) cout<<"���ӽ�������������á�";
	if(r==2) cout<<"���ӽ����������һ�㡣";
	if(r==3) cout<<"���캢�����������½���";
	
	r=ranint(1,4);
	if(r==1) cout<<"�������ܲ�ʱ�����";
	if(r==2) cout<<"����Ӧ�ü�ǿ������";
	if(r==3) cout<<"����Ӧ����ס������";
	 
}
int main()
{
	time_t t=time(0); 
    char time_out[64]; 
    if(!count)
    {
    	strftime(time_out,sizeof(time_out),"%m.%d %a",localtime(&t)); 
    	cout<<time_out<<endl;
	}
	else printf("���ҵĵ�%d��\n",count);
	
	srand((unsigned)time(NULL));
	
	printf("\n����:\n\t30s:\n\t\t");
	for(int i=1;i<=5;i++)
		printf("%d\t",ranint(98,109));
	
	printf("\n\t60s:\n\t\t");
	for(int i=1;i<=3;i++)
		printf("%d\t",ranint(185,195));
	
	printf("\n\t90s:\n\t\t");
	for(int i=1;i<=3;i++)
		printf("%d\t",ranint(265,280));
	
		
	printf("\n���Գ�:\n\t40��x3��\n\t15+15x3��");
	
	printf("\n�ܲ�:\n\t3'%d''\n",rand()%(21)+30);
	printf("С��:\n\t");
	prsn(); 
	
	printf("\n�ҳ�����:\n\t");
	pare(); 
	
	printf("\n\n�������������һ��\n");
	printf("\nby Youthح��ѩ\n");
	getchar();
	count++;
	system("cls");
	main();
}
