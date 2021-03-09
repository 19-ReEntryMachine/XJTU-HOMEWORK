#include<stdio.h>
#include<math.h>
float Function(float x)                                                    //�������������ڼ������������˱��ʽ��ֵ 
{
	return exp(x)+x;
}

float Derivative(float x)                                                  //�������������ڼ������������˱��ʽ�ĵ���ֵ�� 
{
	return exp(x)+1;
}

int main()                                                                 //��������ʼ�� 
{
	float x0=0.5,x,epsilon;                                                //������������ʼ����λ�ã��������������ֵ 
	printf("Please give us the accuracy of the solution:");                //������ʾ�����ľ���ֵ 
	scanf("%f",&epsilon);
	do 
	{
		x=x0;                                                              //����һ�εĵ����������������ʼλ�ñ�����
		x0=x0-Function(x)/Derivative(x);                                   //���������ʼλ�ô���������������Ľ��㣬��Ϊ�����Ľ���� 
	}while(fabs(x0-x)>=epsilon);                                           //���������ε�������Ĳ�ֵС�ھ���ʱ����ֹ������ 
	printf("The NUMERAL solution of the equation'exp(x)+x=0'is:%5f",x0);   //������̵Ľ⣬������������ 
	return 0;
}
