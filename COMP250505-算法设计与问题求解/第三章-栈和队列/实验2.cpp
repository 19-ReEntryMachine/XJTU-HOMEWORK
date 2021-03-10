#include<stdio.h>
#include<iostream>
int MAX=100;                                              //定义队列最大长度 
struct SqQueue                                            //定义结构体：队列 
{
	char alphabets[100]; 
	int rear;                                             //定义队头指针和队尾指针 
	int front;
};

struct SqQueue* CreateQueue()                             //定义函数：创建队列 
{
	struct SqQueue *Q=new SqQueue;                        //为队列安排内存空间并将队头、队尾指针置空，返回地址 
	Q->rear=0;
	Q->front=0;
	return Q;
}

void EnQueue(struct SqQueue *Q,char c)                    //声明函数：入队 
{
	if((Q->rear+1)%MAX==Q->front%MAX)                     //若队满（队头和队尾指针取余后仅仅差1）则输出提示并禁止输入。 
	{
		printf("QUEUE FULL,CAN'T GET IN");
	}
	else                                                  //若队不满，则将元素安排入队列中，队尾指针自增。 
	{
		Q->rear++;
		Q->alphabets[(Q->rear-1)%MAX]=c;
	}
}

char DeQueue(struct SqQueue *Q)                           //声明函数：出队 
{
	if((Q->front)%MAX==(Q->rear)%MAX)
	{
		printf("QUEUE EMPTY,CAN'T PUT OUT");              //若队空（队头和队尾指针取余后相等）则输出提示并禁止输出。
		return 0;
	}
	else                                                  //若队不空，则将队头元素弹出，队头指针自增。
	{
		Q->front++;
		return Q->alphabets[(Q->front-1)%MAX];
	}
}

int main()                                                //主函数开始 
{
	struct SqQueue *queue;	
	queue = new SqQueue;                                  //创建队列
    queue->rear=queue->front=0;
	EnQueue(queue, 'A');
	EnQueue(queue, 'B');
	EnQueue(queue, 'C');                                  //一个元素出队,并显示
	printf("出队：%c\n", (char)DeQueue(queue));           //再入队3个后打印队列
	EnQueue(queue, 'D');
	EnQueue(queue, 'E');
	EnQueue(queue, 'F');                                  //所有元素依次出队直到队空，同时输出这些元素 
	while (queue->front != queue->rear)
		printf("出队：%c\n", (char)DeQueue(queue));
	return 0;                                             //主函数结束 
}

