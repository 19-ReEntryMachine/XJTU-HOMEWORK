#include<stdio.h>

int main()                                                        //��������ʼ 
{
	double payment,change;                                        //����������Ӧ������� 
	int notes,i;                                                  //������������Ʊ�� 
	printf("������Ӧ��Ǯ����");                                   //����Ӧ��Ǯ�� 
	scanf("%lf",&payment);
	change=((int)payment/100+1.0)*100.0-payment;                  //���踶����ֻ�ܸ�����Ԫ�󳮣��������� 
	//printf("%lf\n",change);(��һ�����ڼ���������Ƿ�����)
	double value[7]={50.0,20.0,10.0,5.0,1.0,0.5,0.1};             //����ʵ�����У���Ʊ��� 
	notes=0;                                                      //��ʱ��û������ 
	for(i=0;i<7;i++)                                              //̰���㷨����������ĳ�Ʊ��ʼ�����Ҷ����Ҷ��٣�ֱ����С���ĳ�ƱΪֹ 
	{
		notes=notes+(int)(change/value[i]);
		change=change-(int)(change/value[i])*value[i];
	}
	printf("�һصĳ�Ʊ����Ϊ��%d",notes);                         //�����������������������
	return 0; 
 } 
