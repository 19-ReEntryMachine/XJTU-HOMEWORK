#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void QualityFactor(int n)                  //声明空类型函数：质因数解算 
{
	printf("This natural number has the following prime factors:");
	int nr=n;                              //为解算质因数，必须遍历从2到n之间的全部自然数，因此我们须保持形参不变以作为一个判据，而声明另一个初值与形参相同的整型变量，以进行下一步的操作 
	int i=2;                               //声明辅助变量 
	for(;i<=n;i++)                         //从2起到传入的形参值n为止，逐个检验是否为质因数 
	{
		if(nr%i==0)                        //若形参能够被循环中的某个数整除，则该数必定是传入的形参的质因数 
		{
		printf("%d ",i);                   //输出该质因数，并消去形参中的这一质因子 
		nr=nr/i;
		}
		while(nr%i==0)                     //若在消去这一质因子后该数仍能被这一质因子整除，则继续消去这一质因子，进行除法运算直至不能继续整除为止 
		{
			nr=nr/i;
		}
	}
 }                                         //由于每个合数都能够被表示为若干个比该合数小的质因数的乘积，因此即使传入函数的形参能够被某个合数整除，这一合数因子也会被分解为比他小的质因子而被前面已经判定的质因子消去，这一程序本身结构即决定它本身不可能输出合数 

int main()                                 //主函数开始 
{
	int n;                                 //声明变量：待分解的整数 
	printf("Please input an integer:");    //给出提示，将该整数输入机器 
	scanf("%d",&n);
	QualityFactor(n);                      //调用质因数解算程序 
	return 0;                              //主函数结束 
 } 
