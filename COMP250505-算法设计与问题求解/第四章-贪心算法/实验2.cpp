#include<stdio.h>
struct Node                                                //定义结构体变量：活动结点，包含起止时间两个变量 
{
	int start;
	int end;
};

int main()                                                //主函数开始 
{
	int n,i,j;                                            //定义结构体数组，用于存放活动信息；定义控制变量和计数变量，后两个用以控制循环，前一个用于统计活动总数 
	struct Node arr[1000]; 
	printf("请输入待安排的活动数量：");                   //按照提示输入活动总数 
	scanf("%d",&n);
	printf("请输入待安排活动的起止时间：\n");             //按照提示逐个输入活动的起止时间并存入内存中 
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].start,&arr[i].end);
	}
	for(i=0;i<n-1;i++)                                    //依照结束时间先后对于活动进行排序，先结束的在前面 
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].end>arr[j].end)
			{
				struct Node arrangement;
				arrangement=arr[i];
				arr[i]=arr[j];
				arr[j]=arrangement;
			}
		}
	}
	int time=arr[0].end,activnum=1;                       //默认先安排最早结束的一个活动，并声明一个变量用于统计可安排活动数目 
	for(i=1;i<n;i++)                                      //贪心算法：从第一个活动开始，下一个开始时间可以容许的、最早结束的活动将被安排，以此逐个类推 
	{
		if(arr[i].start>time)
		{
			activnum++;                                   //凡有一个活动被安排上，活动计数变量自增 
			time=arr[i].end;
		}
	}
	printf("最多可安排的活动数量为%d",activnum);          //输出活动安排数量，主函数结束
	return 0; 
}
