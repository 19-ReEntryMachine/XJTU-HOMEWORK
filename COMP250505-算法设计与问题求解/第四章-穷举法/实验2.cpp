#include<stdio.h>
int MAX=90;                                  //���屳������ 
struct iteminfo                              //����ṹ�壺��Ʒ��������������ֵ
{
	int mass;
	int value;
};
struct packageinfo                           //����ṹ�壺���������������������ܼ�ֵ����������ı��
{
	int mass;
	int value;
	int items[20];
};
struct packageinfo package;                  //����ȫ�ֱ������������Է�ĳЩ���������������ܴ��� 
int item[20];                                //����ȫ�ֱ�������Ʒ�飬����ָ�������ڿ��������ض���Ʒ��� 
void Selection(struct iteminfo *items,int k,int n)//��������������nΪ��δ���뱳������Ʒ�� 
{
	int i,j;                                 //����ѭ�����Ʊ���  
	if(k==1)                                 //��ֻʣ��һ����û�����룬�����Ǹ���֮��ֱ�ӿ�ʼ�ж��� 
	{
		for(i=0;i<2;i++)                     //�����������Σ�������߲������Ӧ���鸳ֵ��0�ǲ��1���� 
		{
			item[k-1]=i;
			int mass=0,value=0;              //������������Ʒ������������ܼ�ֵ 
			for(j=0;j<n;j++)
			{
				mass=mass+item[j]*items[j].mass;
				value=value+item[j]*items[j].value;
			}
			//for(j=0;j<n;j++)
			//{
				//printf("%d ",item[j]);
			//}
			if(mass<=MAX&&value>=package.value)//����Ʒ��������С�ڱ������ݵ��������������Ʒ��ļ�ֵС�ڵ�ǰ�Ѿ�ȡ�õ���Ʒ���ֵ���ֵ 
			{
				package.value=value;         //������Ʒ�����Ϣ���뱳���ṹ���У������������ͼ�ֵ��������ѭ��������Ʒ�� 
				package.mass=mass;
				//printf("mass:%d value:%d ",package.mass,package.value);
				for(j=0;j<n;j++)
				{
					package.items[j]=item[j];
				}
			}
			//for(j=0;j<n;j++)
			//{
				//printf("%d ",package.items[j]);
			//}
			//printf("\n");
		}
	}
	else                                     //����ʣ�¶����Ʒδȷ��������ȷ����һ����Ʒ�����ֿ��ܣ�Ȼ����ŵ��ú�������������¸����Դ�����ֱ�����һ�� 
	{
		for(i=0;i<2;i++)
		{
			item[k-1]=i;
			Selection(items,k-1,n);
		}
	}
}

 
 int main()                                   //��������ʼ��
 {
 	int n,i;                                  //������������Ʒ�顢��Ʒ������ѭ�����Ʊ���
 	struct iteminfo items[20];
 	printf("��������Ʒ����:\n");              //�����ʾ������Ʒ��������洢�ռ��� 
	scanf("%d",&n);
	for(i=0;i<n;i++)                          //��ʼ�������ռ䣺����ʲô��Ʒ��û�У������Ϊ0�� 
	{
		item[i]=0;
	}
	printf("���������Ʒ�ļ�ֵ:\n");          //�����ʾ������Ʒ��ֵ����Ʒ��������洢��Ʒ��Ϣ�Ľṹ��������
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].value);
	}
	printf("���������Ʒ������:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].mass);
	}
	package.value=0;                          //��ʼ�������ռ䣺û���κ��м�ֵ��Ʒ 
	Selection(items,n,n);                     //���ú���������п���ֵ����õĽ��ۣ� 
	printf("��Ʒ����ȡ��:(0--��װ��1--װ)\n");
	for(i=0;i<n;i++)                          //���������ʽ������ۣ����������� 
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",package.items[i]);
	}
	return 0;
 }
