#include<bits/stdc++.h>
using namespace std;
long long f[15][10],power[15]={1};
//f[i][j]��ʾ����iλ�ҵ�iλ��j��windy���ķ����� 
long long count(long long x)
{
	long long cnt=0,ans=0;//cnt��ʾx�м�λ 
	while(power[cnt]<=x) cnt++;
	for(int i=1;i<cnt;i++)
		for(int j=1;j<=9;j++)
			ans+=f[i][j];
	for(int i=1;i<x/power[cnt-1];i++)
		ans+=f[cnt][i];
	
	//��ʼ�������ѵĲ���
	//����˵����75420
	//������������λ��f[4][1~4]�󣬸�λ��ȷ��
	//ͬ��ȷ����754--�󣬲�����windy��������break
	
	//����˼·������
	//12~13����ʵ���Ͻ磬Ϊ������� 
	//��ѭ��ö�ٵڼ�λ����ѭ���ۼ�
	//���ǵ���һλ�޷�ȡ���������������һ 
	int last=x/power[cnt-1];
	x%=power[cnt-1];
	for(int i=cnt-1;i>=1;i--)
	{
		int y=x/power[i-1];
		for(int j=0;j<y;j++)
			if(abs(last-j)>=2)
				ans+=f[i][j];
		if(abs(y-last)<2) break;
		last=y;
		x%=power[i-1];
	} 
	return ans;
} 
void init()
{
	for(int i=0;i<=9;i++) f[1][i]=1;
	for(int i=2;i<=11;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2)
					f[i][j]+=f[i-1][k];
	for(int i=1;i<=12;i++)
		power[i]=10*power[i-1];
}
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	init();
	cout<<count(b+1)-count(a)<<endl;
}
