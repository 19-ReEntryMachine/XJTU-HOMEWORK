#include<stdio.h>
const int maxsize=100;                                   //构建结构体变量：学生数据单元；
struct stu
{
	int id;
	char name[20];
};
struct SeqList                                           //构建线性表并定义其最大表长  
{
	struct stu data[100]; 
	int length;
};
void InsertInOrder(struct SeqList *L,struct stu info)    //声明函数：元素插入 
{
	int j;                                               //声明计数变量，用于控制循环 
	if(L->length==maxsize)                               //若表满，则终止进程并提示 
	{
		printf("NO PLACE TO STORE."); 
	}
	else if(L->length==0)                                //若表空，则直接填上第一个元素并使表长自增 
	{
		L->data[0]=info;
		L->length++;
	}
	else
	{
		for(j=L->length;;j--)                            //其他情形下，则执行循环进程： 
		{
			if(j==0)                                     //若循环进行到了线性表表头，则可知该学生学号为最小，将元素直接填入表头 
			{
				L->data[j]=info;
				break;
			}
			if(info.id>L->data[j-1].id)                  //若找到了一个学号恰好小于该元素的元素，则将待插入元素放在这个元素后面，同时终止循环； 
			{
				L->data[j]=info;
				break;
			}
			else                                         //其他情形下，让学号大的学生信息向后平移一个存储单元 
			{
				L->data[j]=L->data[j-1];
			}
		}
		L->length++;                                     //表长自增 
	}
}
void DeleteInID(struct SeqList *L,int id)                //声明函数：元素删除 
{
	int j,i=0;                                           //声明计数变量，用于控制循环 
	for(j=0;j<L->length;j++)                             //从第一个元素起，到最后一个元素为止，查找学生； 
	{
		if(id==L->data[j].id)                            //如果找到了对应学号的学生，则将其后全部学生的信息全部向前平移一个存储单元，并使变量I自增以指示“确实删掉了一个” 
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
	if(i!=0)                                             //如果我们确实删掉了一个元素，则令表长自减并提示；否则则提示找不到对应学生 
	{
		L->length--;
	}
}
void Display(struct SeqList *L)                          //声明函数：线性表输出 
{
	int j;                                               //声明计数变量，用于控制循环  
	for(j=0;j<L->length;j++)                             //从第一个元素起，到最后一个元素为止，按照格式输出全部元素 
	{
		printf("The element in place %d is %d %s.\n",j+1,L->data[j].id,L->data[j].name);
	}
}

int main()                                               //主函数开始 
{
	int i;                                               //声明计数变量，用于控制循环 
	struct SeqList L;                                    //声明线性表并置空表 
	L.length=0;
	struct stu stuinfo;                                  //声明结构体用于暂时存放待输入元素 
	printf("给出三个待输入信息：");                      //按照提示输入学生信息并将其依次放入线性表中 
	for(i=0;i<3;i++)
	{
		scanf("%d ",&stuinfo.id);
		gets(stuinfo.name);
		InsertInOrder(&L,stuinfo);
	}
	Display(&L);                                         //输出表，用于检测 
	printf("给出待删除的信息：");                        //按照提示输入学生学号并将其依次放入线性表中 
	scanf("%d",&stuinfo.id);
	DeleteInID(&L,stuinfo.id);                           //删掉学号对应的学生信息，并输出表 
	Display(&L);
	printf("给出一个待插入信息：");                      //再插入一个学生信息，按照提示输入学生信息并将其放入线性表中，最终输出表，主函数结束 
	scanf("%d ",&stuinfo.id);
	gets(stuinfo.name);
	InsertInOrder(&L,stuinfo);
	Display(&L);
	return 0;
}
