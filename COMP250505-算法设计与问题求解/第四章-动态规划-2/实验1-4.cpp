#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()                                  //主函数开始
{
	srand((unsigned int)time(NULL));        //定义种子，用于生成随机序列 
	int n=10000,num[10000],i,j,max,summax=0;//声明变量，用于生成随机的整数序列和计算最大连续部分和
	for(i=0;i<n;i++)                        //生成随机序列 
	{
		num[i]=rand()%100-50;
	}
	for(i=0;i<n;i++)                        //从第一个元素作为起始，计算“从第i给元素起始的连续序列部分和”
	{
		max=0;                              //每次计算之前重置连续部分和为初始值0 
		for(j=i;j<n;j++)                    //计算从第i个元素起始的全部连续序列部分和（遍历，只经过不储存）
		{
			max=max+num[j];                 //逐项相加 
			if(max>=summax)                 //每加一项，就将加和结果与目前已获得的最大连续部分和相比较，若较大则用新值覆盖旧值 
			{
				summax=max;
			}
		}
	}                                       //输出计算得到的最大连续部分和，主函数结束 
	printf("连续子序列和最大值为：%d",summax);
	return 0; 
 } 
