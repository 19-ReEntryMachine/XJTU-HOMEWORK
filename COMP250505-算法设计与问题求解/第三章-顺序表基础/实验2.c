#include<stdio.h>
const int maxsize=100;                                   //�����ṹ�������ѧ�����ݵ�Ԫ��
struct stu
{
	int id;
	char name[20];
};
struct SeqList                                           //�������Ա�����������  
{
	struct stu data[100]; 
	int length;
};
void InsertInOrder(struct SeqList *L,struct stu info)    //����������Ԫ�ز��� 
{
	int j;                                               //�����������������ڿ���ѭ�� 
	if(L->length==maxsize)                               //������������ֹ���̲���ʾ 
	{
		printf("NO PLACE TO STORE."); 
	}
	else if(L->length==0)                                //����գ���ֱ�����ϵ�һ��Ԫ�ز�ʹ������ 
	{
		L->data[0]=info;
		L->length++;
	}
	else
	{
		for(j=L->length;;j--)                            //���������£���ִ��ѭ�����̣� 
		{
			if(j==0)                                     //��ѭ�����е������Ա��ͷ�����֪��ѧ��ѧ��Ϊ��С����Ԫ��ֱ�������ͷ 
			{
				L->data[j]=info;
				break;
			}
			if(info.id>L->data[j-1].id)                  //���ҵ���һ��ѧ��ǡ��С�ڸ�Ԫ�ص�Ԫ�أ��򽫴�����Ԫ�ط������Ԫ�غ��棬ͬʱ��ֹѭ���� 
			{
				L->data[j]=info;
				break;
			}
			else                                         //���������£���ѧ�Ŵ��ѧ����Ϣ���ƽ��һ���洢��Ԫ 
			{
				L->data[j]=L->data[j-1];
			}
		}
		L->length++;                                     //������ 
	}
}
void DeleteInID(struct SeqList *L,int id)                //����������Ԫ��ɾ�� 
{
	int j,i=0;                                           //�����������������ڿ���ѭ�� 
	for(j=0;j<L->length;j++)                             //�ӵ�һ��Ԫ���𣬵����һ��Ԫ��Ϊֹ������ѧ���� 
	{
		if(id==L->data[j].id)                            //����ҵ��˶�Ӧѧ�ŵ�ѧ���������ȫ��ѧ������Ϣȫ����ǰƽ��һ���洢��Ԫ����ʹ����I������ָʾ��ȷʵɾ����һ���� 
		{
			int k=j;
			for(;k<L->length-1;k++)
			{
				L->data[k]=L->data[k+1];
				i++;
			}
		}
	}
	printf("%s",i==0?"NO SUCH STUDENT.\n":"INFO IS DELETED.\n");
	if(i!=0)                                             //�������ȷʵɾ����һ��Ԫ�أ�������Լ�����ʾ����������ʾ�Ҳ�����Ӧѧ�� 
	{
		L->length--;
	}
}
void Display(struct SeqList *L)                          //�������������Ա���� 
{
	int j;                                               //�����������������ڿ���ѭ��  
	for(j=0;j<L->length;j++)                             //�ӵ�һ��Ԫ���𣬵����һ��Ԫ��Ϊֹ�����ո�ʽ���ȫ��Ԫ�� 
	{
		printf("The element in place %d is %d %s.\n",j+1,L->data[j].id,L->data[j].name);
	}
}

int main()                                               //��������ʼ 
{
	int i;                                               //�����������������ڿ���ѭ�� 
	struct SeqList L;                                    //�������Ա��ÿձ� 
	L.length=0;
	struct stu stuinfo;                                  //�����ṹ��������ʱ��Ŵ�����Ԫ�� 
	printf("����������������Ϣ��");                      //������ʾ����ѧ����Ϣ���������η������Ա��� 
	for(i=0;i<3;i++)
	{
		scanf("%d ",&stuinfo.id);
		gets(stuinfo.name);
		InsertInOrder(&L,stuinfo);
	}
	Display(&L);                                         //��������ڼ�� 
	printf("������ɾ������Ϣ��");                        //������ʾ����ѧ��ѧ�Ų��������η������Ա��� 
	scanf("%d",&stuinfo.id);
	DeleteInID(&L,stuinfo.id);                           //ɾ��ѧ�Ŷ�Ӧ��ѧ����Ϣ��������� 
	Display(&L);
	printf("����һ����������Ϣ��");                      //�ٲ���һ��ѧ����Ϣ��������ʾ����ѧ����Ϣ������������Ա��У�������������������� 
	scanf("%d ",&stuinfo.id);
	gets(stuinfo.name);
	InsertInOrder(&L,stuinfo);
	Display(&L);
	return 0;
}
