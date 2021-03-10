#include<stdio.h>
int DynamicProg(int n,int *a)                   //函数声明：动态规划求解最大连续部分和 
{
	int summax[n],i,max=0;                      //声明变量：存放前n个数中最大连续部分和的数组，循环控制变量，最大连续部分和 
	summax[0]=a[0];                             //初始化数组首元素：第一个数的最大连续部分和必是其自身或者0 
	for(i=1;i<n;i++)                            //计算序列逐渐增长时的最大连续部分和： 
	{
		if(a[i]>0&&summax[i-1]>0)               //若前一次运算结果与下一项相加能够获得更大的连续部分和，则将这个新的连续部分和存入数组中 
		{
			summax[i]=summax[i-1]+a[i];
		}
		else summax[i]=a[i];                    //若不能，连续求和序列中断，新元素本身则作为最大连续部分和 
		if(summax[i]>max)                       //若两种方法计算得到的最大连续部分和比已存储的最大连续部分和大，则新的最值将覆盖旧值 
		{
			max=summax[i];
		} 
	}
	return max;                                 //返回最大值 
}

int main()                                      //主函数开始 
{
	int n,num[1000],i,summax;                   //声明变量：序列长度、序列、循环控制变量、最大连续部分和 
	printf("请输入指定序列长度：\n");           //输出提示，按照提示依次输入序列长度、序列 
	scanf("%d",&n);
	printf("请输入指定序列：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	summax=DynamicProg(n,num);                  //调用动态规划算法，计算最大连续部分和 
	printf("连续子序列和最大值为：%d",summax);  //输出结论，主函数结束
	return 0; 
}
