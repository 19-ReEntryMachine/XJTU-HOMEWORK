#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
struct LNode                                                      //定义结构体：单链表结点，包含学生的三项基本信息和指向下一个结点的指针 
{
	int ID;
	char name[15]; 
	char tel[10];
	struct LNode* next;
};

void InsertInHead(struct LNode* head,int id,char *nm,char *tl)    //定义插入函数，要求将元素插入单链表头部； 
{
	struct LNode *p;                                              //声明新结点并为这一结点分配存储空间 
	p=new LNode;
	p->ID=id;                                                     //将学生信息填入结点内 
	strcpy(p->name,nm);
	strcpy(p->tel,tl);
	p->next=head->next;                                           //使新结点的指针指向原来头结点后的第一个元素 
	head->next=p;                                                 //使头结点的指针指向新结点 
}

void DeleteInID(struct LNode* head,int id)                        //定义删除函数，要求根据学号删除学生信息 
{
	struct LNode *p,*q;                                           //声明指针变量，并让两个指针变量分别指向头结点和头结点的下一个结点 
	p=head->next,q=head; 
	while(p!=NULL)                                                //若第一个指针变量非空，则使第一个指针变量指向下一个结点并检查其ID 
	{
		if(p->ID==id)                                             //若其ID与待删除的ID相符，跳出循环并执行删除操作，否则则令第二个指针也后移 
		{
			break;
		}
		p=p->next;
		q=q->next;
	}
	if(p==NULL)                                                   //若遍历全表仍未找到，则提示删除失败 
	{
		printf("NO SUCH STUDENT.\n");
	}
	else
	{
		q->next=p->next;                                          //执行删除操作时，将待删除结点后一个结点的指针值赋给其前一个结点的指针 
		printf("THE INFO HAS DELETED.\n");
	}
}

void FindInID(struct LNode* head,int id)                          //定义查找函数，要求根据学号查找学生信息 
{
	struct LNode *p;                                              //声明指针变量并使之指向头结点后的第一个元素 
	p=head->next;
	while(p!=NULL)                                                //从链表表头开始用指针遍历，若指针指向的结点的ID是待查的ID，则输出结点内全部信息 
	{
		if(p->ID==id)
		{
			printf("The STUDENT WITH ID %d IS %s,WITH TELE NUM %s.\n",id,p->name,p->tel);
			break;
		}
		p=p->next;                                                //若指针指向的结点的ID不是待查的ID，则令指针指向下一个结点 
	}
	if(p==NULL)                                                   //若直到链表尾端仍未找到对应学生，则提示查找失败 
	{
		printf("NO SUCH STUDENT.");
	}
}

void Display(struct LNode* head)                                  //定义输出函数，要求按照链表存储顺序输出学生信息 
{
	struct LNode *p;                                              //声明指针变量并使之指向头节点的下一个元素 
	p=head->next;
	while(p!=NULL)                                                //执行循环：若结点指针并非指向空地址，则将该指针指向的结构体中的学生信息按顺序输出，同时使指针后移，指向下一个节点 
	{
		printf("The STUDENT WITH ID %d IS %s,WITH TELE NUM %s.\n",p->ID,p->name,p->tel);
		p=p->next;
	}
}

int main()                                                        //主函数开始 
{
	struct LNode *charthead;                                      //定义学生信息链表的头节点并初始化之 
	charthead=new LNode;
	char name[15],tel[10];                                        //声明数组变量和整型变量，用于暂时存放学生信息 
	int id,i;
	printf("按要求依次输入三名学生的学号、姓名、电话号码：\n");   //按照提示输入学生信息并将学生信息存入链表中 
	for(i=0;i<3;i++) 
	{
		scanf("%d %s %s",&id,name,tel);
		InsertInHead(charthead,id,name,tel);
	}
	Display(charthead);                                           //输出学生信息，以供核实 
	printf("按要求依次输入待删除的学生的学号：\n");               //按照提示输入待删除的学生信息
	scanf("%d",&id);
	DeleteInID(charthead,id);                                     //根据输入的学号删除学生信息 
	Display(charthead);                                           //输出学生信息，以供核实
	printf("按要求再输入一名学生的学号、姓名、电话号码：\n");     //按照提示输入学生信息并将学生信息存入链表中 
	scanf("%d %s %s",&id,name,tel);
	InsertInHead(charthead,id,name,tel);
	Display(charthead);                                           //输出学生信息，以供核实 
	printf("按要求输入一名待查找的学生的学号：\n");               //按照提示输入待查找的学生学号并执行查找，主函数结束。 
	scanf("%d",&id);
	FindInID(charthead,id);
}
