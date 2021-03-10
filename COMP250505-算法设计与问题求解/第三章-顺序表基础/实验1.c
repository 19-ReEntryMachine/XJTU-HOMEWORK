#include<stdio.h>
const int maxsize=100;
struct SeqList                                                       //定义线性表结构及最大表长 
{
	int data[100];
	int length;
};
void Insert(struct SeqList *L,int i,int x)                           //声明函数：插入元素 
{
	int j;                                                           //声明计数变量，用于控制循环 
	if(i>L->length+1||L->length==maxsize||i<0)                       //若表满或表内对应位置无法存取元素,结束进程并提示 
	{
		printf("ERROR PLACE,CAN'T INSERT IN.\n");
	}
	else
	{
		for(j=L->length-1;j>=i-1;j--)                                //若可以存放元素，则令该位置及其后的全部元素向后平移一个存储单元； 
		{
			L->data[j+1]=L->data[j];
		}
		L->data[i-1]=x;                                              //空出来的位置用来放指定元素，表长自增 
		L->length++;
	}
}
void Delete(struct SeqList *L,int i)                                 //声明函数：删除元素 
{
	int j;                                                           //声明计数变量，用于控制循环 
	if(i>L->length||L->length==0||i<=0)                              //若表中对应位置没有元素或者表中没有对应位置，结束进程并提示 
	{
		printf("ERROR PLACE,CAN'T DELETE.\n");
	}
	else
	{
		for(j=i;j<=L->length;j++)                                    //若该位置有元素，则令该元素后的全部元素向前平移1个存储单元 
		{
			L->data[j-1]=L->data[j];
		}
		L->data[L->length-1]=0;                                      //抹掉线性表的最后一个元素，表长自减 
		L->length--;
	}
}
int Find(struct SeqList *L,int x)                                    //声明函数：线性表查找 
{
	int j;                                                           //声明计数变量，用于控制循环 
	for(j=0;j<L->length;j++)                                         //从第一个元素开始按顺序找，如果找到某个元素与之相同则返回其下标地址 
	{
		if(L->data[j]==x)
		{
			return j+1;
		}
	}
	return -1;                                                       //若未找到，返回-1 
}
void Display(struct SeqList *L)                                      //声明函数：线性表输出 
{
	int j;                                                           //声明变量，用于控制循环 
	for(j=0;j<L->length;j++)                                         //从第一个元素开始直至线性表末尾按照格式输出元素 
	{
		printf("The element in place %d is %d.\n",j+1,L->data[j]);
	}
}

int main()                                                           //主函数开始 
{
	struct SeqList L;                                                //声明线性表，并置空表 
	L.length=0;
	int s,t,i,id;                                                    //声明变量，分别用于存储：插入元素及其位置；控制循环变量；待删除元素； 
	printf("给出三个有序的待输入整数：");                            //给出提示，按顺序输入元素，同时将其按顺序插入线性表中； 
	for(i=0;i<3;i++)
	{
		scanf("%d",&s);
		Insert(&L,i+1,s);
	}
	Display(&L);                                                     //输出表，用于检验 
	printf("给出待删除的整数：");                                    //给出提示，输入待删除元素，并寻找其位置 
	scanf("%d",&id);
	if(Find(&L,id)!=-1)                                              //若能找到该元素，则将其删除 
	{
		Delete(&L,Find(&L,id));
    }
	Display(&L);                                                     //输出表，用于检验 
	printf("给出一个待插入的整数和插入的位置：");                    //给出提示，在指定位置再输入一个元素，并插入线性表中； 
	scanf("%d %d",&s,&t); 
	Insert(&L,t,s);
	Display(&L);                                                      //输出表，主函数结束 
	return 0;
}
