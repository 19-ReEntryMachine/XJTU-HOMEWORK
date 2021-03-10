#include<stdio.h>
struct Sqstack                                  //定义结构体：栈，包含栈内元素和栈长两个数据 
{
	int data[100];
	int top;
};
void Push(struct Sqstack *stack,int x)          //声明函数：入栈 
{
	if(stack->top==99)                          //栈满，输出提示并禁止输入。 
	{
		printf("ERROR,CAN'T PUT IT IN");
	}
	else                                        //栈不满，则栈长自增，栈顶指针处填入新元素 
	{
		stack->top++;
		stack->data[stack->top]=x;
	}
}
int Pop(struct Sqstack *stack)                  //声明函数：出栈 
{
	if(stack->top==-1)                          //若栈空，输出提示并禁止输出 
	{
		printf("ERROR,CAN'T PUT IT IN");
		return 0;
	}
	else                                        //若栈不空，调出栈顶元素并使栈长自减。 
	{
		stack->top--;
		return stack->data[stack->top+1];
	}
}


int main()                                      //主函数开始 
{
	struct Sqstack stack;                       //定义栈和栈指针 
	struct Sqstack *pstack;
	pstack=&stack; 
	pstack->top=-1;                             //置空栈 
	char note;                                  //定义字符，并输入第一个字符。 
	scanf("%c",&note);
	while(note!='#')                            //若上一个输入的字符不是终止符，则一直持续循环： 
	{
		if(note>='0'&&note<='9')                //若输入的元素是数字，将数字压入栈 
		{
			Push(pstack,(int)(note-'0'));
		}
		else if(note=='+')                      //若读取的元素是算符+，将栈顶两个数字弹出并执行加和操作 
		{
			int i,j;
			i=Pop(pstack);
			j=Pop(pstack);
			Push(pstack,i+j);                   //将加和运算结果压入栈 
		}
		else if(note=='*')                      //若读取的元素是算符*，将栈顶两个数字弹出并执行乘积操作 
		{ 
			int i,j;
			i=Pop(pstack);
			j=Pop(pstack);
			Push(pstack,i*j);                   //将乘积运算结果压入栈 
		}
		scanf("%c",&note);                      //继续读取下一个位点的字符 
	}
	printf("Result=%d",Pop(pstack));            //将栈中剩余的最后一个元素弹出并输出，主函数结束。 
 } 
