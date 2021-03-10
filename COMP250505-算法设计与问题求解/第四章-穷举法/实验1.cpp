#include<stdio.h>
int MAX=90;                                  //定义背包容量 
struct iteminfo                              //定义结构体：物品，包含其编号、质量、价值、价值比 
{
	int order;
	int mass;
	int value;
	double vpm;
};
struct packageinfo                           //定义结构体：背包，包含其总质量和其中物体的编号 
{
	int mass;
	int item[20];
};

int main()                                   //主函数开始； 
{
	int n,i,j;                               //声明变量：物品组、背包、物品总数、循环控制变量 
	struct iteminfo items[20];
	struct packageinfo package;
	package.mass=0;                          //初始化背包质量 
	printf("请输入物品个数:\n");             //输出提示，将物品个数填入存储空间中 
	scanf("%d",&n);
	for(i=0;i<n;i++)                         //初始化背包空间：里面什么物品都没有（都标记为0） 
	{
		package.item[i]=0;
	}
	printf("请输入各物品的价值:\n");         //输出提示，将物品价值、物品质量填入存储物品信息的结构体数组中，为物品编号 
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].value);
	}
	printf("请输入各物品的重量:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].mass);
		items[i].vpm=(double)items[i].value/(double)items[i].mass;
		items[i].order=i;
	}
	for(i=0;i<n-1;i++)                       //根据价值比为物品排序，从高到低 
	{
		for(j=i+1;j<n;j++)
		{
			if(items[i].vpm<items[j].vpm)
			{
				struct iteminfo item=items[i];
				items[i]=items[j];
				items[j]=item;
			}
		}
	}
	for(i=0;i<n;i++)                         //从价值最高的物品开始，将其逐个填入背包直至填满 
	{
		if(package.mass+items[i].mass<=MAX)  
		{
			package.mass=package.mass+items[i].mass;
			package.item[items[i].order]=1;  //将背包结构体中该物品在数组中对应的位置填入1，表示该物品已经放入 
		}
		else break;                          //若背包已填满则不再执行填充 
	}
	printf("物品建议取法:(0--不装，1--装)\n");
	for(i=0;i<n;i++)                         //根据题设格式输出结论，主函数结束 
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",package.item[i]);
	}
	return 0;
} 
