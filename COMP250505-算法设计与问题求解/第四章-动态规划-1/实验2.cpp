#include<stdio.h>
struct itemstruct                                                         //�����ṹ�壬���ڴ洢��Ʒ��Ϣ�����������ͼ�ֵ���� 
{
	int mass;
	int value;
};
int DynamicProg(struct itemstruct *iteminfo,int n,int mass,int *items)    //������̬�滮���������ڼ����ڱ����ռ����޵������µ�����ѡ����� 
{
	int i,j;                                                              //����ѭ�����Ʊ��� 
	int maxval[n][mass+1];                                                //������ά���飬���ڴ��������������¿��ܻ�õ��������  
	for(i=0;i<=mass;i++)                                                  //������֪��Ϣ�Ե�һ�и���ֵ 
	{
		if(i<iteminfo[0].mass)
		{
			maxval[0][i]=0;                                               //�����ڵ�һ����Ʒ����Ͷ��ռ��������޶�������²���ѡ��װ�룬��Ӧ��ֵʧЧ 
		}
		else maxval[0][i]=iteminfo[0].value;                              //��Ͷ��ռ����������������Ʒ��ֵ��Ч 
	}
	for(i=1;i<n;i++)                                                      //�������������뿼�ǵ���Ʒ��ʱ������
	{
		for(j=0;j<=mass;j++)                                              //�������п��ܵ�Ͷ��ռ���������Ͷ�벻ͬ�ռ���������
		{
			if(j<iteminfo[i].mass)                                        //���ṩ�Ŀռ䲻���Է�����Ʒ����������������벻������Ʒʱ���������һ�� 
			{
				maxval[i][j]=maxval[i-1][j];
				//printf("%d %d %d\n",i,j,maxval[i][j]);
			}
			else                                                          //������Ͷ����ͬ�ռ����װ�����Ʒʱ�������롰��Ͷ��Ŀռ��а���һ���ֿռ�װ�����Ʒ�������˰����������ģʽװ��������Ʒ����������Ȳ���������е����ֵ�������ֵ��Ϊ��ʱ��������� 
			{
				maxval[i][j]=maxval[i-1][j]>=(maxval[i-1][j-iteminfo[i].mass]+iteminfo[i].value)?maxval[i-1][j]:(maxval[i-1][j-iteminfo[i].mass]+iteminfo[i].value);
				//printf("%d %d %d\n",i,j,maxval[i][j]);
			}
		}
	}
	int t=mass;                                                           //�������������ڵ������ſ��ɲ��� 
	for(i=n-1;i>=0;i--)
	{
		if(i==0)                                                          //�ڵ��Ƶ����һ�����ʱ����ʣ��ռ�����Ӧ������ֵ������0����ζ�Ÿ���Ʒδ��װ�룬��0  
		{
			if(maxval[i][t]==0)
			{
				items[i]=0;
			}
			else items[i]=1;                                              //��������ζ�Ÿ���Ʒ��װ�룬��1 
		}
		else if(maxval[i][t]==maxval[i-1][t])                             //����Ͷ���Ӧ�˿ռ�ʱ�����Ǵ���Ʒ�Ͳ����Ǵ���Ʒʱ�����������ͬ������ζ�Ÿ���Ʒδ��װ�� 
		{
			items[i]=0;
		}
		else                                                              //���򣬸���Ʒ��װ�룻ͬʱ����ƣ��ҳ������ζ�Ӧ��ǰһ����̬��ͬʱ���ռ�����Ϊ����̬��Ӧ�Ŀռ� 
		{
			items[i]=1;
			t=t-iteminfo[i].mass; 
		}
		//printf("%d %d %d\n",i,t,items[i]);
	}
	return maxval[n-1][mass];                                             //���ؼ���õ���������桪���ڿ���ȫ����Ʒ��Ͷ��ȫ���ռ��µ��������
}

int main()                                                                //��������ʼ 
{
	int n,i,packagemass,packagevalue,items[20];                           //������������Ʒ������ѭ�����Ʊ����������ռ䡢�����ɳ�װ������ֵ����Ʒ��װ����� 
	struct itemstruct iteminfo[20];                                       //������������Ʒ��Ϣ 
	printf("��������Ʒ������");                                           //������ʾ����������Ʒ�����������ռ䡢����Ʒ������������Ʒ�ļ�ֵ�������ڴ��� 
	scanf("%d",&n);
	printf("�����뱳�������ɵ����������");
	scanf("%d",&packagemass);
	printf("���������Ʒ������");
	for(i=0;i<n;i++)
	{
		scanf("%d",&iteminfo[i].mass);
	}
	printf("���������Ʒ��ֵ��");
	for(i=0;i<n;i++)
	{
		scanf("%d",&iteminfo[i].value);
	}
	packagevalue=DynamicProg(iteminfo,n,packagemass,items);               //���ö�̬�滮�������������  
	printf("��װ�����Ʒ����ֵΪ%d.\n",packagevalue);                   //����������  
	printf("��Ʒ����ȡ��:(0--��װ��1--װ)\n");                            //�����ʾ 
	for(i=0;i<n;i++)                                                      //������ۣ���һ��ָʾ����Ӧ���룬�ڶ���ָʾ���ߣ�1��ʾ�ڣ�0��ʾ����  
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",items[i]);
	}
	return 0;                                                             //���������� 
 }  
