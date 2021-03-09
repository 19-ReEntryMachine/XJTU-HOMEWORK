#include<stdio.h> 

int main()                          //主函数开始 
{
	int m,n;                        //这一模块的作用是声明并输入多项式的诸参数：首先是两个多项式的次数，其次是第一个多项式的系数，最后是第二个多项式的系数；系数的输入是从高次到低次的 
	scanf("%d %d",&m,&n);
	float mc[m+1],nc[n+1];
	for(int i=m;i>=0;i--)
	{
		scanf("%f",&mc[i]);
	}
	for(int i=n;i>=0;i--)
	{
		scanf("%f",&nc[i]);
	}
	float d[m-n+1];                 //声明数组，用以存储多项式除法的运算结果 
	for(int i=m-n;i>=0;i--)         //这一模块的作用是进行除法运算，即循环执行“最高次项系数与最高次项系数相除，分子减去分母与两最高次项系数之比的乘积”直至分子上不具有比分母最高次数更高的项 
	{
		d[i]=mc[n+i]/nc[n];
		for(int j=n;j>=0;j--)
		{
			mc[n+i-j]=mc[n+i-j]-d[i]*nc[n-j];
		}
	}
	for(int i=0;i<=m-n;i++)         //这一模块的作用是输出除法运算结果：第一行输出不带余式的除法结果，第二行输出余式，输出顺序是从高次到低次，中间以空格分隔 
	{
		printf("%02f",d[i]);
		if(i<m-n)
		{
			printf(" ");
		}
	}
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		printf("%02f",mc[i]);
		if(i<n)
		{
			printf(" ");
		}
	}
	return 0;                       //主函数结束 
}
