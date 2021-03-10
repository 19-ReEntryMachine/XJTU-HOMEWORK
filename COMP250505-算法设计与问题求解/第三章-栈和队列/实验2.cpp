#include<stdio.h>
#include<iostream>
int MAX=100;                                              //���������󳤶� 
struct SqQueue                                            //����ṹ�壺���� 
{
	char alphabets[100]; 
	int rear;                                             //�����ͷָ��Ͷ�βָ�� 
	int front;
};

struct SqQueue* CreateQueue()                             //���庯������������ 
{
	struct SqQueue *Q=new SqQueue;                        //Ϊ���а����ڴ�ռ䲢����ͷ����βָ���ÿգ����ص�ַ 
	Q->rear=0;
	Q->front=0;
	return Q;
}

void EnQueue(struct SqQueue *Q,char c)                    //������������� 
{
	if((Q->rear+1)%MAX==Q->front%MAX)                     //����������ͷ�Ͷ�βָ��ȡ��������1���������ʾ����ֹ���롣 
	{
		printf("QUEUE FULL,CAN'T GET IN");
	}
	else                                                  //���Ӳ�������Ԫ�ذ���������У���βָ�������� 
	{
		Q->rear++;
		Q->alphabets[(Q->rear-1)%MAX]=c;
	}
}

char DeQueue(struct SqQueue *Q)                           //�������������� 
{
	if((Q->front)%MAX==(Q->rear)%MAX)
	{
		printf("QUEUE EMPTY,CAN'T PUT OUT");              //���ӿգ���ͷ�Ͷ�βָ��ȡ�����ȣ��������ʾ����ֹ�����
		return 0;
	}
	else                                                  //���Ӳ��գ��򽫶�ͷԪ�ص�������ͷָ��������
	{
		Q->front++;
		return Q->alphabets[(Q->front-1)%MAX];
	}
}

int main()                                                //��������ʼ 
{
	struct SqQueue *queue;	
	queue = new SqQueue;                                  //��������
    queue->rear=queue->front=0;
	EnQueue(queue, 'A');
	EnQueue(queue, 'B');
	EnQueue(queue, 'C');                                  //һ��Ԫ�س���,����ʾ
	printf("���ӣ�%c\n", (char)DeQueue(queue));           //�����3�����ӡ����
	EnQueue(queue, 'D');
	EnQueue(queue, 'E');
	EnQueue(queue, 'F');                                  //����Ԫ�����γ���ֱ���ӿգ�ͬʱ�����ЩԪ�� 
	while (queue->front != queue->rear)
		printf("���ӣ�%c\n", (char)DeQueue(queue));
	return 0;                                             //���������� 
}

