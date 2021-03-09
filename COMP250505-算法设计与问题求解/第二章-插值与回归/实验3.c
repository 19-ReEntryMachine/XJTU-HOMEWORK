#include<stdio.h>
#include<math.h>
float Function(float x)                                                    //声明函数，用于计算给定方程左端表达式的值 
{
	return exp(x)+x;
}

float Derivative(float x)                                                  //声明函数，用于计算给定方程左端表达式的导数值； 
{
	return exp(x)+1;
}

int main()                                                                 //主函数开始； 
{
	float x0=0.5,x,epsilon;                                                //声明变量：起始迭代位置，迭代结果，精度值 
	printf("Please give us the accuracy of the solution:");                //按照提示输入解的精度值 
	scanf("%f",&epsilon);
	do 
	{
		x=x0;                                                              //将上一次的迭代结果赋给迭代起始位置变量；
		x0=x0-Function(x)/Derivative(x);                                   //计算迭代起始位置处曲线切线与数轴的交点，作为迭代的结果； 
	}while(fabs(x0-x)>=epsilon);                                           //在相邻两次迭代结果的差值小于精度时，终止迭代； 
	printf("The NUMERAL solution of the equation'exp(x)+x=0'is:%5f",x0);   //输出方程的解，主函数结束； 
	return 0;
}
