#include<stdio.h>
#include<math.h>
#define max_size 100
int main()                                         //主函数开始； 
{
	float x[max_size]={165,165,157,170,175,165,155,170},y[max_size]={48,57,50,54,64,61,43,59};
	int count=8;                                   //声明数据组：第六行分别是身高和体重数据，第七行声明的是数据数量； 
	float x_sum=0,y_sum=0;                         //第八行声明的是身高、体重的数据和；第九行声明的是身高、体重的均值 
	float x_avg,y_avg;
	float Lxy=0,Lxx=0,Lyy=0;                       //第十行声明的是三种残差和，第十一行声明的是拟合曲线的截距和斜率 
	float a,b;
	int i;                                         //声明辅助计数变量 
	for(i=0;i<count;i++)                           //对身高和体重两个数组，从第一个数据开始直至最后一个数据，计算所有数据之和 
	{
		x_sum=x[i]+x_sum;
		y_sum=y[i]+y_sum;
	}
	x_avg=x_sum/count;                             //计算身高体重的均值 
	y_avg=y_sum/count;
	for(i=0;i<count;i++)                           //对身高和体重两个数组，从第一个数据开始直至最后一个数据，计算所有数据的三种残差和 
	{
		Lxy=(x[i]-x_avg)*(y[i]-y_avg)+Lxy;         //这一行计算的是身高体重的残差乘积 
		Lxx=(x[i]-x_avg)*(x[i]-x_avg)+Lxx;         //这一行计算的是身高的残差平方和 
		Lyy=(y[i]-y_avg)*(y[i]-y_avg)+Lyy;         //这一行计算的是体重的残差平方和
	}
	b=Lxy/Lxx;                                     //依据最小二乘原则计算拟合曲线的斜率和截距 
	a=y_avg-b*x_avg;
	printf("线性拟合的结果为：");                  //以人能识别的方式输出拟合结果 
	if(fabs(a)==0)
	printf("y=%5.3fx\n",b);
	else if(a>0)
	printf("y=%5.3fx+%5.3f\n",b,a);
	else if(a<0)
	printf("y=%5.3fx%5.3f\n",b,a);
	float y1=a+b*172;                              //计算身高172cm的学生的身高预测值并输出，主函数结束 
	printf("预测172cm的学生体重为：%4.2fkg\n",y1);
	return 0; 
} 
