#include<stdio.h>
struct Sqstack                                  //����ṹ�壺ջ������ջ��Ԫ�غ�ջ���������� 
{
	int data[100];
	int top;
};
void Push(struct Sqstack *stack,int x)          //������������ջ 
{
	if(stack->top==99)                          //ջ���������ʾ����ֹ���롣 
	{
		printf("ERROR,CAN'T PUT IT IN");
	}
	else                                        //ջ��������ջ��������ջ��ָ�봦������Ԫ�� 
	{
		stack->top++;
		stack->data[stack->top]=x;
	}
}
int Pop(struct Sqstack *stack)                  //������������ջ 
{
	if(stack->top==-1)                          //��ջ�գ������ʾ����ֹ��� 
	{
		printf("ERROR,CAN'T PUT IT IN");
		return 0;
	}
	else                                        //��ջ���գ�����ջ��Ԫ�ز�ʹջ���Լ��� 
	{
		stack->top--;
		return stack->data[stack->top+1];
	}
}


int main()                                      //��������ʼ 
{
	struct Sqstack stack;                       //����ջ��ջָ�� 
	struct Sqstack *pstack;
	pstack=&stack; 
	pstack->top=-1;                             //�ÿ�ջ 
	char note;                                  //�����ַ����������һ���ַ��� 
	scanf("%c",&note);
	while(note!='#')                            //����һ��������ַ�������ֹ������һֱ����ѭ���� 
	{
		if(note>='0'&&note<='9')                //�������Ԫ�������֣�������ѹ��ջ 
		{
			Push(pstack,(int)(note-'0'));
		}
		else if(note=='+')                      //����ȡ��Ԫ�������+����ջ���������ֵ�����ִ�мӺͲ��� 
		{
			int i,j;
			i=Pop(pstack);
			j=Pop(pstack);
			Push(pstack,i+j);                   //���Ӻ�������ѹ��ջ 
		}
		else if(note=='*')                      //����ȡ��Ԫ�������*����ջ���������ֵ�����ִ�г˻����� 
		{ 
			int i,j;
			i=Pop(pstack);
			j=Pop(pstack);
			Push(pstack,i*j);                   //���˻�������ѹ��ջ 
		}
		scanf("%c",&note);                      //������ȡ��һ��λ����ַ� 
	}
	printf("Result=%d",Pop(pstack));            //��ջ��ʣ������һ��Ԫ�ص���������������������� 
 } 
