#include<stdio.h>

int main()                                                         //��������ʼ 
{
	float x[4],y[4][4],x0,y0=0;                                    //�������飬���ڴ������ĵ��xy�����Լ�ȫ�����̣��������������ڴ洢������ĵ��x����ͼ��������y���� 
	int i,j;                                                       //���������������� 
	for(i=0;i<4;i++)                                               //������ʾ�����ĸ�������� 
	{
		printf("Please input the points' x lable and y lable:"); 
		scanf("%f %f",&x[i],&y[i][0]);
	}
	for(i=1;i<=3;i++)                                              //���ղ�ּ���ԭ������������ڵ�ȫ����� 
	{
		for(j=i;j<=3;j++)
		{
			y[j][i]=(y[j][i-1]-y[j-1][i-1]);
		}
	}
	printf("PLEASE INPUT THE NUMBER WHICH WOULD BE CALCULATED:");  //���������ĵ��x���� 
	scanf("%f",&x0);
	y0=y[0][0];                                                    //����ţ�ٲ�ֵԭ�򣬸����Ѿ�������Ĳ�ּ���y���� 
	for(i=1;i<=3;i++)
	{
		float t=(x0-x[0])/(x[1]-x[0]),x1=1; 
		for(j=1;j<=i;j++)
		{
			x1=x1*(t-j+1)/j;
		}
		y0=y0+y[i][i]*x1;
		//��һ������������������е�ָ�꣺printf("��һ�ײ�����ֵΪ%f\n",y[i][i]); 
	}
	printf("The approximation of the tan%f is:%f",x0,y0);          //�����ţ�ٲ�ֵ��������ĵ�����꣬���������� 
	return 0;
} 
