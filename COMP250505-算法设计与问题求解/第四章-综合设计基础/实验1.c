#include<stdio.h>
char str[10];                             //声明全局变量，以防函数内的运算数值丢失 
void Output(int position,int length)      //声明函数：输出全部全排列序列 
{
	if(position==length)                  //若字符串已经被填充满，则输出字符串 
	{
		printf("%s  ",str);
	}
	else                                  //若字符串未被填充满，则先填充第一位未被填充的字符空间 
	{
		int i;
		for(i=0;i<length;i++)             //遍历所有可能的填充情形 
		{
			str[position]='A'+i;          //决定填充在该存储空间的字符 
			Output(position+1,length);    //调用自身，确定下一步将用于继续确定（所有可能的）字符抑或输出结论 
		}
	}
}

int main()                                //主函数开始 
{
	int n;                                //声明序列的长度并按照提示输入之 
	printf("Input n:");
	scanf("%d",&n);
	Output(0,n);                          //针对此长度输出字母的全排列序列，主函数结束 
	return 0;
}
