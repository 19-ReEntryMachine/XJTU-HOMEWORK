#include<stdio.h>
const int maxsize=100;
struct SeqList                                                       //�������Ա�ṹ������ 
{
	int data[100];
	int length;
};
void Insert(struct SeqList *L,int i,int x)                           //��������������Ԫ�� 
{
	int j;                                                           //�����������������ڿ���ѭ�� 
	if(i>L->length+1||L->length==maxsize||i<0)                       //����������ڶ�Ӧλ���޷���ȡԪ��,�������̲���ʾ 
	{
		printf("ERROR PLACE,CAN'T INSERT IN.\n");
	}
	else
	{
		for(j=L->length-1;j>=i-1;j--)                                //�����Դ��Ԫ�أ������λ�ü�����ȫ��Ԫ�����ƽ��һ���洢��Ԫ�� 
		{
			L->data[j+1]=L->data[j];
		}
		L->data[i-1]=x;                                              //�ճ�����λ��������ָ��Ԫ�أ������� 
		L->length++;
	}
}
void Delete(struct SeqList *L,int i)                                 //����������ɾ��Ԫ�� 
{
	int j;                                                           //�����������������ڿ���ѭ�� 
	if(i>L->length||L->length==0||i<=0)                              //�����ж�Ӧλ��û��Ԫ�ػ��߱���û�ж�Ӧλ�ã��������̲���ʾ 
	{
		printf("ERROR PLACE,CAN'T DELETE.\n");
	}
	else
	{
		for(j=i;j<=L->length;j++)                                    //����λ����Ԫ�أ������Ԫ�غ��ȫ��Ԫ����ǰƽ��1���洢��Ԫ 
		{
			L->data[j-1]=L->data[j];
		}
		L->data[L->length-1]=0;                                      //Ĩ�����Ա�����һ��Ԫ�أ����Լ� 
		L->length--;
	}
}
int Find(struct SeqList *L,int x)                                    //�������������Ա���� 
{
	int j;                                                           //�����������������ڿ���ѭ�� 
	for(j=0;j<L->length;j++)                                         //�ӵ�һ��Ԫ�ؿ�ʼ��˳���ң�����ҵ�ĳ��Ԫ����֮��ͬ�򷵻����±��ַ 
	{
		if(L->data[j]==x)
		{
			return j+1;
		}
	}
	return -1;                                                       //��δ�ҵ�������-1 
}
void Display(struct SeqList *L)                                      //�������������Ա���� 
{
	int j;                                                           //�������������ڿ���ѭ�� 
	for(j=0;j<L->length;j++)                                         //�ӵ�һ��Ԫ�ؿ�ʼֱ�����Ա�ĩβ���ո�ʽ���Ԫ�� 
	{
		printf("The element in place %d is %d.\n",j+1,L->data[j]);
	}
}

int main()                                                           //��������ʼ 
{
	struct SeqList L;                                                //�������Ա����ÿձ� 
	L.length=0;
	int s,t,i,id;                                                    //�����������ֱ����ڴ洢������Ԫ�ؼ���λ�ã�����ѭ����������ɾ��Ԫ�أ� 
	printf("������������Ĵ�����������");                            //������ʾ����˳������Ԫ�أ�ͬʱ���䰴˳��������Ա��У� 
	for(i=0;i<3;i++)
	{
		scanf("%d",&s);
		Insert(&L,i+1,s);
	}
	Display(&L);                                                     //��������ڼ��� 
	printf("������ɾ����������");                                    //������ʾ�������ɾ��Ԫ�أ���Ѱ����λ�� 
	scanf("%d",&id);
	if(Find(&L,id)!=-1)                                              //�����ҵ���Ԫ�أ�����ɾ�� 
	{
		Delete(&L,Find(&L,id));
    }
	Display(&L);                                                     //��������ڼ��� 
	printf("����һ��������������Ͳ����λ�ã�");                    //������ʾ����ָ��λ��������һ��Ԫ�أ����������Ա��У� 
	scanf("%d %d",&s,&t); 
	Insert(&L,t,s);
	Display(&L);                                                      //��������������� 
	return 0;
}
