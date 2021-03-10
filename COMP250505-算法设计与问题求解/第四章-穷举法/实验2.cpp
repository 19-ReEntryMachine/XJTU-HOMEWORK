#include<stdio.h>
int MAX=90;                                  //定义背包容量 
struct iteminfo                              //定义结构体：物品，包含质量、价值
{
	int mass;
	int value;
};
struct packageinfo                           //定义结构体：背包，包含其总质量、总价值和其中物体的编号
{
	int mass;
	int value;
	int items[20];
};
struct packageinfo package;                  //声明全局变量：背包，以防某些函数内运算结果不能带出 
int item[20];                                //声明全局变量：物品组，用于指征背包内可能填充的特定物品组合 
void Selection(struct iteminfo *items,int k,int n)//声明遍历函数，n为尚未填入背包的物品数 
{
	int i,j;                                 //声明循环控制变量  
	if(k==1)                                 //若只剩下一个空没有填入，填入那个空之后直接开始判定： 
	{
		for(i=0;i<2;i++)                     //遍历两种情形，填入或者不填，给对应数组赋值，0是不填，1是填 
		{
			item[k-1]=i;
			int mass=0,value=0;              //声明变量：物品组的总质量、总价值 
			for(j=0;j<n;j++)
			{
				mass=mass+item[j]*items[j].mass;
				value=value+item[j]*items[j].value;
			}
			//for(j=0;j<n;j++)
			//{
				//printf("%d ",item[j]);
			//}
			if(mass<=MAX&&value>=package.value)//若物品组总质量小于背包可容的最大质量，且物品组的价值小于当前已经取得的物品组价值最大值 
			{
				package.value=value;         //将该物品组的信息填入背包结构体中，先填入质量和价值，再利用循环填入物品组 
				package.mass=mass;
				//printf("mass:%d value:%d ",package.mass,package.value);
				for(j=0;j<n;j++)
				{
					package.items[j]=item[j];
				}
			}
			//for(j=0;j<n;j++)
			//{
				//printf("%d ",package.items[j]);
			//}
			//printf("\n");
		}
	}
	else                                     //若还剩下多个物品未确定，则先确定下一个物品的两种可能，然后接着调用函数自身计算下下个，以此类推直到最后一层 
	{
		for(i=0;i<2;i++)
		{
			item[k-1]=i;
			Selection(items,k-1,n);
		}
	}
}

 
 int main()                                   //主函数开始；
 {
 	int n,i;                                  //声明变量：物品组、物品总数、循环控制变量
 	struct iteminfo items[20];
 	printf("请输入物品个数:\n");              //输出提示，将物品个数填入存储空间中 
	scanf("%d",&n);
	for(i=0;i<n;i++)                          //初始化背包空间：里面什么物品都没有（都标记为0） 
	{
		item[i]=0;
	}
	printf("请输入各物品的价值:\n");          //输出提示，将物品价值、物品质量填入存储物品信息的结构体数组中
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].value);
	}
	printf("请输入各物品的重量:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&items[i].mass);
	}
	package.value=0;                          //初始化背包空间：没有任何有价值物品 
	Selection(items,n,n);                     //调用函数算出所有可能值中最好的结论； 
	printf("物品建议取法:(0--不装，1--装)\n");
	for(i=0;i<n;i++)                          //根据题设格式输出结论，主函数结束 
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",package.items[i]);
	}
	return 0;
 }
