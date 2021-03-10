#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
struct LNode                                                      //����ṹ�壺�������㣬����ѧ�������������Ϣ��ָ����һ������ָ�� 
{
	int ID;
	char name[15]; 
	char tel[10];
	struct LNode* next;
};

void InsertInHead(struct LNode* head,int id,char *nm,char *tl)    //������뺯����Ҫ��Ԫ�ز��뵥����ͷ���� 
{
	struct LNode *p;                                              //�����½�㲢Ϊ��һ������洢�ռ� 
	p=new LNode;
	p->ID=id;                                                     //��ѧ����Ϣ�������� 
	strcpy(p->name,nm);
	strcpy(p->tel,tl);
	p->next=head->next;                                           //ʹ�½���ָ��ָ��ԭ��ͷ����ĵ�һ��Ԫ�� 
	head->next=p;                                                 //ʹͷ����ָ��ָ���½�� 
}

void DeleteInID(struct LNode* head,int id)                        //����ɾ��������Ҫ�����ѧ��ɾ��ѧ����Ϣ 
{
	struct LNode *p,*q;                                           //����ָ���������������ָ������ֱ�ָ��ͷ����ͷ������һ����� 
	p=head->next,q=head; 
	while(p!=NULL)                                                //����һ��ָ������ǿգ���ʹ��һ��ָ�����ָ����һ����㲢�����ID 
	{
		if(p->ID==id)                                             //����ID���ɾ����ID���������ѭ����ִ��ɾ����������������ڶ���ָ��Ҳ���� 
		{
			break;
		}
		p=p->next;
		q=q->next;
	}
	if(p==NULL)                                                   //������ȫ����δ�ҵ�������ʾɾ��ʧ�� 
	{
		printf("NO SUCH STUDENT.\n");
	}
	else
	{
		q->next=p->next;                                          //ִ��ɾ������ʱ������ɾ������һ������ָ��ֵ������ǰһ������ָ�� 
		printf("THE INFO HAS DELETED.\n");
	}
}

void FindInID(struct LNode* head,int id)                          //������Һ�����Ҫ�����ѧ�Ų���ѧ����Ϣ 
{
	struct LNode *p;                                              //����ָ�������ʹָ֮��ͷ����ĵ�һ��Ԫ�� 
	p=head->next;
	while(p!=NULL)                                                //�������ͷ��ʼ��ָ���������ָ��ָ��Ľ���ID�Ǵ����ID������������ȫ����Ϣ 
	{
		if(p->ID==id)
		{
			printf("The STUDENT WITH ID %d IS %s,WITH TELE NUM %s.\n",id,p->name,p->tel);
			break;
		}
		p=p->next;                                                //��ָ��ָ��Ľ���ID���Ǵ����ID������ָ��ָ����һ����� 
	}
	if(p==NULL)                                                   //��ֱ������β����δ�ҵ���Ӧѧ��������ʾ����ʧ�� 
	{
		printf("NO SUCH STUDENT.");
	}
}

void Display(struct LNode* head)                                  //�������������Ҫ��������洢˳�����ѧ����Ϣ 
{
	struct LNode *p;                                              //����ָ�������ʹָ֮��ͷ�ڵ����һ��Ԫ�� 
	p=head->next;
	while(p!=NULL)                                                //ִ��ѭ���������ָ�벢��ָ��յ�ַ���򽫸�ָ��ָ��Ľṹ���е�ѧ����Ϣ��˳�������ͬʱʹָ����ƣ�ָ����һ���ڵ� 
	{
		printf("The STUDENT WITH ID %d IS %s,WITH TELE NUM %s.\n",p->ID,p->name,p->tel);
		p=p->next;
	}
}

int main()                                                        //��������ʼ 
{
	struct LNode *charthead;                                      //����ѧ����Ϣ�����ͷ�ڵ㲢��ʼ��֮ 
	charthead=new LNode;
	char name[15],tel[10];                                        //����������������ͱ�����������ʱ���ѧ����Ϣ 
	int id,i;
	printf("��Ҫ��������������ѧ����ѧ�š��������绰���룺\n");   //������ʾ����ѧ����Ϣ����ѧ����Ϣ���������� 
	for(i=0;i<3;i++) 
	{
		scanf("%d %s %s",&id,name,tel);
		InsertInHead(charthead,id,name,tel);
	}
	Display(charthead);                                           //���ѧ����Ϣ���Թ���ʵ 
	printf("��Ҫ�����������ɾ����ѧ����ѧ�ţ�\n");               //������ʾ�����ɾ����ѧ����Ϣ
	scanf("%d",&id);
	DeleteInID(charthead,id);                                     //���������ѧ��ɾ��ѧ����Ϣ 
	Display(charthead);                                           //���ѧ����Ϣ���Թ���ʵ
	printf("��Ҫ��������һ��ѧ����ѧ�š��������绰���룺\n");     //������ʾ����ѧ����Ϣ����ѧ����Ϣ���������� 
	scanf("%d %s %s",&id,name,tel);
	InsertInHead(charthead,id,name,tel);
	Display(charthead);                                           //���ѧ����Ϣ���Թ���ʵ 
	printf("��Ҫ������һ�������ҵ�ѧ����ѧ�ţ�\n");               //������ʾ��������ҵ�ѧ��ѧ�Ų�ִ�в��ң������������� 
	scanf("%d",&id);
	FindInID(charthead,id);
}
