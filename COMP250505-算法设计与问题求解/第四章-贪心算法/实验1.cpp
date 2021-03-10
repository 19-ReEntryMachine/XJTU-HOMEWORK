#include<stdio.h>

int main()                                                        //主函数开始 
{
	double payment,change;                                        //声明变量：应付款、找零 
	int notes,i;                                                  //声明变量：钞票数 
	printf("请输入应付钱数：");                                   //输入应付钱数 
	scanf("%lf",&payment);
	change=((int)payment/100+1.0)*100.0-payment;                  //假设付款人只能给出百元大钞，计算找零 
	//printf("%lf\n",change);(这一行用于检测程序输出是否正常)
	double value[7]={50.0,20.0,10.0,5.0,1.0,0.5,0.1};             //定义实数序列：钞票面额 
	notes=0;                                                      //暂时还没有找零 
	for(i=0;i<7;i++)                                              //贪心算法：从最大面额的钞票开始，能找多少找多少，直到最小面额的钞票为止 
	{
		notes=notes+(int)(change/value[i]);
		change=change-(int)(change/value[i])*value[i];
	}
	printf("找回的钞票总数为：%d",notes);                         //输出找零数，主函数结束。
	return 0; 
 } 
