#include<stdio.h> 
#include<string.h>
void TrimLeft(char* string)                //声明函数：空格删除 
{
	int i;                                 //声明计数变量，用于循环计数 
	for(i=strlen(string)-1;;i--)           //从字符串最后一个字符开始，删去全部空格，直至碰到一个非空格字符； 
	{
		if(string[i]==' ')
		{
			string[i]=0;
		}
		else break;
	}
	int k=0;                              //声明计数变量：用于计算前部空格数量 
	for(i=0;;i++)                         //从第一个字符开始，计量开头空格数目，直至碰到一个非空格字符； 
	{
		if(string[i]==' ')
		{
			k++;
		}
		else break;
	}
	for(i=0;;i++)                         //将空格后的字符串内容整体前移，平移空间与空格数相同，在字符串终止符处停止； 
	{
		if(string[i+k-1]==0)
		{
			break;
		}
		string[i]=string[i+k];
	}
}

int main()                                //主函数开始； 
{
	char string[80];                      //声明并输入字符串； 
	printf("Please input the string:");
	gets(string);
	TrimLeft(string);                     //删去额外空格，输出对应字符串，主函数结束 
	printf("%s",string);
	return 0;
} 
