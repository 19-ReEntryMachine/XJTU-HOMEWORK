#include<stdio.h>
int MAX=90;                                  //���屳������ 
struct iteminfo                              //����ṹ�壺��Ʒ���������š���������ֵ����ֵ�� 
{
	int order;
	int mass;
	int value;
	double vpm;
};
struct packageinfo                           //����ṹ�壺����������������������������ı�� 
{
	int mass;
	int item[20];
};

int main()                                   //��������ʼ�� 
{
	int n,i,j;                               //������������Ʒ�顢��������Ʒ������ѭ�����Ʊ��� 
	struct iteminfo items[20];
	struct packageinfo package;
	package.mass=0;                          //��ʼ���������� 
	printf("��������Ʒ����:\n");             //�����ʾ������Ʒ��������洢�ռ��� 
	scanf("%d",&n);
	for(i=0;i<n;i++)                         //��ʼ�������ռ䣺����ʲô��Ʒ��û�У������Ϊ0�� 
	{
		package.item[i]=0;
	}
	printf("���������Ʒ�ļ�ֵ:\n");         //�����ʾ������Ʒ��ֵ����Ʒ��������洢��Ʒ��Ϣ�Ľṹ�������У�Ϊ��Ʒ��� 
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].value);
	}
	printf("���������Ʒ������:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].mass);
		items[i].vpm=(double)items[i].value/(double)items[i].mass;
		items[i].order=i;
	}
	for(i=0;i<n-1;i++)                       //���ݼ�ֵ��Ϊ��Ʒ���򣬴Ӹߵ��� 
	{
		for(j=i+1;j<n;j++)
		{
			if(items[i].vpm<items[j].vpm)
			{
				struct iteminfo item=items[i];
				items[i]=items[j];
				items[j]=item;
			}
		}
	}
	for(i=0;i<n;i++)                         //�Ӽ�ֵ��ߵ���Ʒ��ʼ������������뱳��ֱ������ 
	{
		if(package.mass+items[i].mass<=MAX)  
		{
			package.mass=package.mass+items[i].mass;
			package.item[items[i].order]=1;  //�������ṹ���и���Ʒ�������ж�Ӧ��λ������1����ʾ����Ʒ�Ѿ����� 
		}
		else break;                          //����������������ִ����� 
	}
	printf("��Ʒ����ȡ��:(0--��װ��1--װ)\n");
	for(i=0;i<n;i++)                         //���������ʽ������ۣ����������� 
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",package.item[i]);
	}
	return 0;
} 
