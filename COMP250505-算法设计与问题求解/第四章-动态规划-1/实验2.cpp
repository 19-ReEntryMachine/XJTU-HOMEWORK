#include<stdio.h>
struct itemstruct                                                         //声明结构体，用于存储物品信息，包括质量和价值两项 
{
	int mass;
	int value;
};
int DynamicProg(struct itemstruct *iteminfo,int n,int mass,int *items)    //声明动态规划函数，用于计算在背包空间有限的情形下的最优选择策略 
{
	int i,j;                                                              //声明循环控制变量 
	int maxval[n][mass+1];                                                //声明二维数组，用于储存在所有情形下可能获得的最大收益  
	for(i=0;i<=mass;i++)                                                  //根据已知信息对第一行赋初值 
	{
		if(i<iteminfo[0].mass)
		{
			maxval[0][i]=0;                                               //即对于第一件物品，在投入空间数不足限额的情形下不能选择装入，对应价值失效 
		}
		else maxval[0][i]=iteminfo[0].value;                              //在投入空间数充足的情形下物品价值有效 
	}
	for(i=1;i<n;i++)                                                      //计算逐渐增多纳入考虑的物品数时的收益
	{
		for(j=0;j<=mass;j++)                                              //遍历所有可能的投入空间数，计算投入不同空间的最大收益
		{
			if(j<iteminfo[i].mass)                                        //若提供的空间不足以放新物品，则它的最大收益与不放新物品时的最大收益一致 
			{
				maxval[i][j]=maxval[i-1][j];
				//printf("%d %d %d\n",i,j,maxval[i][j]);
			}
			else                                                          //否则，则将投入相同空间而不装入此物品时的收益与“在投入的空间中安排一部分空间装入此物品而其他人按照最大收益模式装入其他物品”的收益相比并计算二者中的最大值，其最大值作为此时的最大收益 
			{
				maxval[i][j]=maxval[i-1][j]>=(maxval[i-1][j-iteminfo[i].mass]+iteminfo[i].value)?maxval[i-1][j]:(maxval[i-1][j-iteminfo[i].mass]+iteminfo[i].value);
				//printf("%d %d %d\n",i,j,maxval[i][j]);
			}
		}
	}
	int t=mass;                                                           //声明参量，用于倒推最优开采策略 
	for(i=n-1;i>=0;i--)
	{
		if(i==0)                                                          //在倒推到最后一座金矿时，若剩余空间所对应的最大价值数等于0则意味着该物品未被装入，赋0  
		{
			if(maxval[i][t]==0)
			{
				items[i]=0;
			}
			else items[i]=1;                                              //否则，则意味着该物品被装入，赋1 
		}
		else if(maxval[i][t]==maxval[i-1][t])                             //若在投入对应人空间时，考虑此物品和不考虑此物品时的最大收益相同，则意味着该物品未被装入 
		{
			items[i]=0;
		}
		else                                                              //否则，该物品则被装入；同时向后倒推，找出该情形对应的前一个形态，同时将空间重置为该形态对应的空间 
		{
			items[i]=1;
			t=t-iteminfo[i].mass; 
		}
		//printf("%d %d %d\n",i,t,items[i]);
	}
	return maxval[n-1][mass];                                             //返回计算得到的最大收益——在考虑全部物品、投入全部空间下的最大收益
}

int main()                                                                //主函数开始 
{
	int n,i,packagemass,packagevalue,items[20];                           //声明变量：物品总数、循环控制变量、背包空间、背包可承装的最大价值、物品的装入策略 
	struct itemstruct iteminfo[20];                                       //声明变量：物品信息 
	printf("请输入物品总数：");                                           //根据提示依次输入物品总数、背包空间、各物品的质量、各物品的价值并存入内存中 
	scanf("%d",&n);
	printf("请输入背包可容纳的最大质量：");
	scanf("%d",&packagemass);
	printf("请输入各物品质量：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&iteminfo[i].mass);
	}
	printf("请输入各物品价值：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&iteminfo[i].value);
	}
	packagevalue=DynamicProg(iteminfo,n,packagemass,items);               //调用动态规划，计算最大收益  
	printf("可装入的物品最大价值为%d.\n",packagevalue);                   //输出最大收益  
	printf("物品建议取法:(0--不装，1--装)\n");                            //输出提示 
	for(i=0;i<n;i++)                                                      //输出结论：第一行指示金矿对应编码，第二行指示决策，1表示挖，0表示不挖  
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",items[i]);
	}
	return 0;                                                             //主函数结束 
 }  
