#include<stdio.h>
double DifferenceQuotient(double *x,double *y,int k)            //声明函数：用于计算差商 
{
	double df=0;                                                //声明变量：差商值，计数辅助变量 
	int i,j;
	for(i=0;i<=k;i++)                                           //计算k阶差商的和式总共有k+1项，因此循环需要执行k+1次 
	{
		double dfj=1.0;                                         //声明并计算和式中特定项的分母：注意累乘过程中需要剔除“自己减自己”的情形 
		for(j=0;j<=k;j++)
		{
			if(i!=j)
			{
				dfj=dfj*(x[i]-x[j]);
			}
		} 
		df=df+y[i]/dfj;                                         //计算差商的特定一项，并将其加到差商值中 
	}
	return df;                                                  //返回差商结果 
}
double NewtonDifference(double *x,double *y,double xx, int n)//声明函数：用于计算特定点处的牛顿插值结果 
{
	double result=y[0];                                      //声明变量，用于储存运算的中间结果，并预先储存插值起点的函数值 
	int i;                                                   //这是辅助计数变量 
	double diff=1.0;                                         //声明与对应差商相乘的因子 
	for(i=1;i<n;i++)                                         //含有差商的项总共有n-1项，因此总共需要有n-1项相加 
	{
		diff=diff*(xx-x[i-1]);                               //计算与对应差商相乘的因子 
		result=result+DifferenceQuotient(x,y,i)*diff;        //将因子与差商相乘并加到最终的结果中 
	}
	return result;                                           //返回插值结果 
}

int main()                                                         //主函数开始 
{
	int n;                                                         //声明并输入变量，这一变量用于存储插值过程中涉及到的点的个数 
	printf("Please tell us the number of the dots:");
	scanf("%d",&n);
	double x[n],y[n];                                              //声明数组，用于存储插值涉及的点的坐标 
	int i;                                                         //声明辅助计数变量 
	for(i=0;i<n;i++)                                               //按照提示输入n个点的坐标 
	{
		printf("Please input the points' x lable and y lable:"); 
		scanf("%lf %lf",&x[i],&y[i]);
	}
	double x0;                                                      //声明并输入变量，这一变量用于存储待计算的点的横坐标 
	printf("Please input the point's x lable which would be calculated:");
	scanf("%lf",&x0);
	printf("The result is:%f",NewtonDifference(x,y,x0,n));           //计算该点经由插值原理算出的纵坐标，主函数结束。 
	return 0;
}
