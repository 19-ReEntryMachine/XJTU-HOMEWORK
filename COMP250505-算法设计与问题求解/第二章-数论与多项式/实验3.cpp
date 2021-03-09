#include<stdio.h> 

int main()                                //主函数开始 
{
	int n;                                //声明变量：质数列举的上限 
	printf("Please input the integer:");  //给出提示，输入变量 
	scanf("%d",&n);
	int nums[n+1];                        //声明数组，用以判定质数 
	for(int i=2;i<=n;i++)                 //初始化数组：从第二个存储单元之后的所有存储单元，使之存储的数值与下标算符相等（我们不引入0和1，因为它们会引起代数上的麻烦） 
	{
		nums[i]=i;
	}
	for(int i=2;i<=n;i++)                 //筛：从2开始到n所有的自然数都拿来跑一次 
	{
		if(!nums[i]==0)                   //如果一个数还没有被筛掉（对应存储单元里面不是0），那它就是质数，就可以拿来筛（当然，起始的数字2是最小的质数） 
		{
			for(int j=i+1;j<=n;j++)       //筛去这个质数的全部倍数，具体方法为将该数对应的存储单元内部赋值为0 
			{
				if((nums[j]%i==0)&&(!nums[j]==0))
				{
					nums[j]=0;
				}
			}
		}
	}
	printf("These are the prime numbers prior to it:\n"); 
	for(int i=2;i<=n;i++)                 //输出所有的质数（也就是对应存储单元不是0的数）并制表，主函数结束 
	{
		if(!nums[i]==0)
		{
			printf("%d\t",i);
		}
	}
	return 0;
}
