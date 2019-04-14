#include<cstdio>
#include<iostream>
using namespace std;
struct stu
{
	char name[25];
	char job;
	char city;
	int sch;
	int cla;
	int art;
}a[105],maxs;
int main()
{
	int n,max=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%s%d%d%s%s%d",&a[i].name,&a[i].sch,&a[i].cla,&a[i].job,&a[i].city,&a[i].art); 
	for(int i=1;i<=n;i++)
	{
		int count=0;
		if(a[i].sch>80&&a[i].art>=1) count+=8000;
		if(a[i].sch>85&&a[i].cla>80) count+=4000;
		if(a[i].sch>90) count+=2000;
		if(a[i].sch>85&&a[i].city=='Y') count+=1000;
		if(a[i].cla>80&&a[i].job=='Y') count+=850;
		sum+=count;
		if(count>max)
		{
			maxs=a[i];
			max=count;
		}
	}
	cout<<maxs.name<<endl<<max<<endl<<sum<<endl;
	return 0;
}

