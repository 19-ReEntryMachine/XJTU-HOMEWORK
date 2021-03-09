#include<stdio.h> 
#define MAX 500000
int isprime[MAX];
void PrimeTable(int M)
{
	int i,j;
	for(i=2;i<=M;i++)                      //�ж�Ԥ���������еĽ���2������֮������ֶ�Ӧ������Ԫ��ȫ����Ϊ1 
	isprime[i]=1;
	for(i=2;i<=M;i++)                      //�ж���ʼ�����������������ж���ĵ�Ԫ 
	{
		if(isprime[i]) 
		{
			for(j=i+i;j<=M;j+=i)           //��һ������Ϊ�����������ֶ�Ӧ�����鵥ԪֵΪ1������������ֵ����б�����Ӧ�����鵥Ԫȫ����0��ָ����Щ���ֵĺ������ 
			isprime[j]=0;
		}
	}
}

int main()
{
	int i,m;
	printf("������m(1<m<500000):");
	scanf("%d",&m);
	printf("2��%d�������������У�\n",m);
	PrimeTable(m);
	for(i=2;i<=m;i++)                      //ѭ������������ж�Ϊ���������������ж�Ӧ����Ϊ0�� �����֣�ȫ��������Ʊ� 
	{
		if(isprime[i])
		printf("%d\t",i);
	}
	return 0;
}
