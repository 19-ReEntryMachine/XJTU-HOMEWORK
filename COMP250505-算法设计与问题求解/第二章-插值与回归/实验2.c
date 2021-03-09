#include<stdio.h>
#include<math.h>
float Function(float x)                                                       //声明函数，这一函数用于计算方程左侧表达式的真值 
{
	//（程序浮标，用于检测程序的运行情况：printf("f(%f)=%f\n",x,5*sin(x)-x/2-1); ） 
	return 5*sin(x)-x/2-1;
}

int main()                                                                    //主函数开始 
{
	float fa,fb,mid,epsilon,solution=0;                                       //声明变量：区间两端，区间终点，求根精度，解的结论（我们给解赋了一个初值0，它并不是一个实际的可行解，但是这个0以后会用到） 
	printf("Please give us the left and right range of the root solving:");   //按照提示输入区间端点； 
	scanf("%f %f",&fa,&fb);
	if(fa>fb)                                                                 //若输入的区间端点并不是左小右大，程序会自动给他调个个，以防后面出错 
	{
		int k=fb;
		fb=fa;
		fa=k;
	}
	if(Function(fa)*Function(fb)>0)                                           //若方程左侧表达式在区间端点处的真值同号，则未必能解除数值解，此时程序自动终止； 
	{
		printf("ERROR RANGE,PROGRAM ENDING");
	}
	else if((Function(fa)==0)||(Function(fb)==0))                             //若方程左侧表达式在区间某个端点处取到了0，则将那个区间端点的位置赋给解变量 
	{
		solution=Function(fa)==0?fa:fb;                                       //采用了相对简洁的问号表达式； 
	}
	else
	{
		printf("Please give us accuracy of the root solving:");               //在一般情况下，则需要先按照提示输入精度要求； 
	    scanf("%f",&epsilon);
	    do{
	    	mid=(fa+fb)/2;                                                    //计算区间中点处函数表达式真值； 
	    	if(Function(mid)*Function(fa)<0)                                  //如果区间中点处和区间左端点处函数表达式值异号，则将区间中点值赋给区间右端点变量； 
	    	{
	    		fb=mid;
			}
			else if(Function(mid)==0)                                         //如果函数表达式恰好在中点处取到0，循环停止，并将中点位置赋给解变量； 
			{
				break;
			}
			else                                                              //如果区间中点处和区间右端点处函数表达式值异号，则将区间中点值赋给区间左端点变量； 
			{
				fa=mid;
			}
			//（程序浮标，用于检测程序的运行情况：printf("%f\n",fabs(fa-mid));） 
		}while(fabs(fa-fb)>=epsilon);                                         //在区间长度小于精度要求时，循环终止，并将区间中点赋给解变量 
		solution=mid;
	}
	if(solution!=0)                                                           //只要方程区间内有解（也就是说，解变量不是初始的0），那么就输出这个解； 
	{
		printf("The solution of the equation'5sin(x)-0.5x-1=0'is:%f",solution);
	}
	return 0;                                                                 //主函数结束 
} 
