#include<stdio.h> 
void PrimeJudge(int n)                       //空类型函数声明：质数判断 
{
	int i;                                   //声明辅助变量
	for(i=2;i*i<=n;i++)                      //从质数2开始逐个自然数进行试验，直到指定数的开方为止
	{
		if(n%i==0)                           //只要以上诸数中其中有一个数能够将指定数整除，则该数不是质数，判断并输出为“NO” 
		{
			printf("NO");
			break;                           //找到该数的一个因子之后，该数必不是质数，则循环无必要继续进行，可以直接终止 
		}
	}
	if(i*i>=n)                               //若在整个循环的检验过程中没有找到质因子，则该数是质数，判断并输出为“YES” 
	{
		printf("YES");
	}
}

int main()                                   //主函数开始 
{
	int n;                                   //声明待判断的整数变量 
	printf("Please input an integer:");      //构造提示，并输入变量 
	scanf("%d",&n);
	PrimeJudge(n);                           //调用质数判断函数 
	return 0;                                //主函数结束 
}
