#include<stdio.h>
int maxgold[100][10001];                                    //声明全局变量（二维数组）：用于储存在所有情形下可能获得的最大收益 
int golddigging[100];                                       //声明全局变量：用于储存最佳决策下的收益策略 
int DynamicProg(int n,int maxinv,int *invest,int *benefit)  //声明函数：动态规划，用于计算最大收益 
{
	int i,j;                                                //声明变量，用于控制循环 
	for(i=0;i<=maxinv;i++)                                  //根据已知信息对第一行赋初值
	{
		if(i<invest[0])
		{
			maxgold[0][i]=0;                                //即对于第一座金矿，在投入人力数不足限额的情形下得不到收益 
		}
		else maxgold[0][i]=benefit[0];                      //在投入人力数充足的情形下得到全部收益  
	}
	for(i=1;i<n;i++)                                        //计算逐渐增多投入生产的金矿数的情形下的收益 
	{
		for(j=0;j<=maxinv;j++)                              //遍历所有可能的投入人数，计算投入不同人数时的最大收益 
		{
			if(j<invest[i])                                 //若提供的人力资源数不足以开挖新的金矿，则它的最大收益与不开挖此金矿时的最大收益一致 
			{
				maxgold[i][j]=maxgold[i-1][j];
			}
			else                                            //否则，则将投入相同人力资源而不开挖此金矿时的收益与“在投入的人力资源中安排一部分人开挖此金矿而其他人按照最大收益模式开采其他金矿”的收益相比并计算二者中的最大值，其最大值作为此时的最大收益 
			{
				maxgold[i][j]=maxgold[i-1][j]>=(maxgold[i-1][j-invest[i]]+benefit[i])?maxgold[i-1][j]:(maxgold[i-1][j-invest[i]]+benefit[i]);
			}
		}
	}
	int t=maxinv;                                           //声明参量，用于倒推最优开采策略 
	for(i=n-1;i>=0;i--)
	{
		if(i==0)                                            //在倒推到最后一座金矿时，若剩余人力资源所对应的最大收益数等于0则意味着该矿未被开采，赋0 
		{
			if(maxgold[i][t]==0)
			{
				golddigging[i]=0;
			}
			else golddigging[i]=1;                          //否则，则意味着该矿被开采，赋1  
		}
		else if(maxgold[i][t]==maxgold[i-1][t])             //若在投入对应人力资源时，考虑此矿和不考虑此矿时的最大收益相同，则意味着该矿未被开采 
		{
			golddigging[i]=0;
		}
		else                                                //否则，该矿则被开采；同时向后倒推，找出该情形对应的前一个形态，同时将人力资源重置为该形态对应的人力资源数 
		{
			golddigging[i]=1;
			t=t-invest[i];
		}
	}
	return maxgold[n-1][maxinv];                            //返回计算得到的最大收益——在开掘全部金矿、投入全部人力情形下的最大收益 
}

int main()                                                  //主函数开始 
{
	int hr[100],gd[100],n,hit,i,benefit;                    //声明变量：需要投入的人力资源数、可以获得的最大收益数、金矿总数、人力资源总数、循环控制变量、收益 
	printf("请输入金矿总数：");                             //根据提示依次输入金矿总数、工人总数、各矿需要的工人数、各矿的最大收益并存入内存中 
	scanf("%d",&n);
	printf("请输入工人总数：");
	scanf("%d",&hit);
	printf("请输入各矿需要的工人数目：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&hr[i]);
	} 
	printf("请输入各矿的总产出：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&gd[i]);
	} 
	benefit=DynamicProg(n,hit,hr,gd);                       //调用动态规划，计算最大收益 
	printf("可挖出的金的最大数额为%d.\n",benefit);          //输出最大收益 
	printf("金矿建议挖法:(0--不装，1--装)\n");              //输出提示 
	for(i=0;i<n;i++)                                        //输出结论：第一行指示金矿对应编码，第二行指示决策，1表示挖，0表示不挖 
	{
		printf("x[%d]  ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d     ",golddigging[i]);
	}
	return 0;                                               //主函数结束 
 } 
