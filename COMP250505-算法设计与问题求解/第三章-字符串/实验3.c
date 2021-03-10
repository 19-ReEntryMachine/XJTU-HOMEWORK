#include<stdio.h>
#include<string.h>

int main()                                            //主函数开始 
{
	char num[20],numrev[20];                          //声明数组，以字符串数组的形式存储数字； 
	int i;                                            //声明计数变量，用于控制循环； 
	printf("Please input the integer:");              //输入数字； 
	gets(num);
	numrev[strlen(num)]=0;                            //构造反转数，首先在数组的合适位置添加终止符； 
	for(i=0;i<strlen(num);i++)                        //使得原数第一位成为反转数的最后一位，原数第二位成为反转数的倒数第二位，以此类推； 
	{
		numrev[i]=num[strlen(num)-i-1];
	}
	if(strcmp(num,numrev)==0)                         //比较反转前后两字符串是否存在差异； 
	{
		printf("This integer is reversable.");        //若反转前后两字符串相同，则称该数字是对称的，否则称之为不对称的； 
	}
	else
	{
		printf("This integer is irreversable.");
	}
	return 0;                                         //主函数结束 
}
