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
	if(r==1) cout<<"跳绳较往日有所下降。";
	if(r==2) cout<<"跳绳较往日有所提高。";
	if(r==3) cout<<"跳绳稳定。";
	if(r==4) cout<<"跳绳时略显累。";

	r=ranint(1,4);
	if(r==1) cout<<"俯卧撑较累。";
	if(r==2) cout<<"俯卧撑做到30个时力气明显不足。";
	if(r==3) cout<<"手臂得到了充分的锻炼。";

	r=ranint(1,5);
	if(r==1) cout<<"早晨跑步有点头晕。";
	if(r==2) cout<<"跑步勉强达标。";
	if(r==3) cout<<"冲刺时有点力不从心。";
	if(r==4) cout<<"今天匀速跑步。"; 
	
		
}
void pare()
{
	int r=ranint(1,4);
	if(r==1) cout<<"陪孩子练了跳绳。";
	if(r==2) cout<<"陪孩子练了俯卧撑。";
	if(r==3) cout<<"陪孩子跑了一会步。"; 
	
	r=ranint(1,4);
	if(r==1) cout<<"孩子今天总体表现良好。";
	if(r==2) cout<<"孩子今天总体表现一般。";
	if(r==3) cout<<"今天孩子体力有所下降。";
	
	r=ranint(1,4);
	if(r==1) cout<<"今天起床跑步时间较晚。";
	if(r==2) cout<<"明日应该加强锻炼。";
	if(r==3) cout<<"明日应该稳住跳绳。";
	 
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
	else printf("开挂的第%d天\n",count);
	
	srand((unsigned)time(NULL));
	
	printf("\n跳绳:\n\t30s:\n\t\t");
	for(int i=1;i<=5;i++)
		printf("%d\t",ranint(98,109));
	
	printf("\n\t60s:\n\t\t");
	for(int i=1;i<=3;i++)
		printf("%d\t",ranint(185,195));
	
	printf("\n\t90s:\n\t\t");
	for(int i=1;i<=3;i++)
		printf("%d\t",ranint(265,280));
	
		
	printf("\n俯卧撑:\n\t40个x3组\n\t15+15x3组");
	
	printf("\n跑步:\n\t3'%d''\n",rand()%(21)+30);
	printf("小结:\n\t");
	prsn(); 
	
	printf("\n家长评语:\n\t");
	pare(); 
	
	printf("\n\n按任意键进入下一天\n");
	printf("\nby Youth丨吹雪\n");
	getchar();
	count++;
	system("cls");
	main();
}
