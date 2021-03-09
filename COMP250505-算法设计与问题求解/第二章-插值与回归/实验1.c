#include<stdio.h>

int main()                                                         //主函数开始 
{
	float x[4],y[4][4],x0,y0=0;                                    //声明数组，用于存放输入的点的xy坐标以及全部差商；声明变量，用于存储待计算的点的x坐标和计算出来的y坐标 
	int i,j;                                                       //声明辅助计数变量 
	for(i=0;i<4;i++)                                               //按照提示输入四个点的坐标 
	{
		printf("Please input the points' x lable and y lable:"); 
		scanf("%f %f",&x[i],&y[i][0]);
	}
	for(i=1;i<=3;i++)                                              //按照差分计算原则计算三阶以内的全部差分 
	{
		for(j=i;j<=3;j++)
		{
			y[j][i]=(y[j][i-1]-y[j-1][i-1]);
		}
	}
	printf("PLEASE INPUT THE NUMBER WHICH WOULD BE CALCULATED:");  //输入待计算的点的x坐标 
	scanf("%f",&x0);
	y0=y[0][0];                                                    //按照牛顿插值原则，根据已经计算出的差分计算y坐标 
	for(i=1;i<=3;i++)
	{
		float t=(x0-x[0])/(x[1]-x[0]),x1=1; 
		for(j=1;j<=i;j++)
		{
			x1=x1*(t-j+1)/j;
		}
		y0=y0+y[i][i]*x1;
		//这一句是用来检验程序运行的指标：printf("这一阶差商数值为%f\n",y[i][i]); 
	}
	printf("The approximation of the tan%f is:%f",x0,y0);          //输出以牛顿插值法计算出的点的坐标，主函数结束 
	return 0;
} 
