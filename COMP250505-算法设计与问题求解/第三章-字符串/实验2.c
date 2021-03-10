#include<stdio.h> 
#include<string.h> 
int ConvertToInt(char* string)                 //声明函数：数字的字符串-整数转换 
{
	int k=0,i;                                 //声明变量：k作为最终计算得到的整数，i作为辅助计数变量用于控制循环； 
	for(i=0;;i++)
	{
		if(string[i]==0)                       //终止条件：读取到字符串终止符 
		{
			break;
		}
		k=k*10+string[i]-'0';                  //施行进位和补位操作：*10使得已输入的数字进位，+string[i]-'0'将下一位数字输入到进位后的最后一位中 
	}
	return k;                                  //返回转换得到的整数； 
}

int main()                                     //主函数开始 
{
	char str[20];                              //声明数组、整数：前一个用于存放待输入的字符串，后一个用于存放转换得到的整数 
	int num;
	printf("Please input the Integer:");       //按照提示输入数字字符串 
	gets(str);
	num=ConvertToInt(str);                     //对字符串实行转换，输出转换结果，主函数结束 
	printf("The integer is:%d",num);
	return 0;
}
