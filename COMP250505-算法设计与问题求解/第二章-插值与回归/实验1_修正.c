#include<stdio.h>
double DifferenceQuotient(double *x,double *y,int k)            //�������������ڼ������ 
{
	double df=0;                                                //��������������ֵ�������������� 
	int i,j;
	for(i=0;i<=k;i++)                                           //����k�ײ��̵ĺ�ʽ�ܹ���k+1����ѭ����Ҫִ��k+1�� 
	{
		double dfj=1.0;                                         //�����������ʽ���ض���ķ�ĸ��ע���۳˹�������Ҫ�޳����Լ����Լ��������� 
		for(j=0;j<=k;j++)
		{
			if(i!=j)
			{
				dfj=dfj*(x[i]-x[j]);
			}
		} 
		df=df+y[i]/dfj;                                         //������̵��ض�һ�������ӵ�����ֵ�� 
	}
	return df;                                                  //���ز��̽�� 
}
double NewtonDifference(double *x,double *y,double xx, int n)//�������������ڼ����ض��㴦��ţ�ٲ�ֵ��� 
{
	double result=y[0];                                      //�������������ڴ���������м�������Ԥ�ȴ����ֵ���ĺ���ֵ 
	int i;                                                   //���Ǹ����������� 
	double diff=1.0;                                         //�������Ӧ������˵����� 
	for(i=1;i<n;i++)                                         //���в��̵����ܹ���n-1�����ܹ���Ҫ��n-1����� 
	{
		diff=diff*(xx-x[i-1]);                               //�������Ӧ������˵����� 
		result=result+DifferenceQuotient(x,y,i)*diff;        //�������������˲��ӵ����յĽ���� 
	}
	return result;                                           //���ز�ֵ��� 
}

int main()                                                         //��������ʼ 
{
	int n;                                                         //�����������������һ�������ڴ洢��ֵ�������漰���ĵ�ĸ��� 
	printf("Please tell us the number of the dots:");
	scanf("%d",&n);
	double x[n],y[n];                                              //�������飬���ڴ洢��ֵ�漰�ĵ������ 
	int i;                                                         //���������������� 
	for(i=0;i<n;i++)                                               //������ʾ����n��������� 
	{
		printf("Please input the points' x lable and y lable:"); 
		scanf("%lf %lf",&x[i],&y[i]);
	}
	double x0;                                                      //�����������������һ�������ڴ洢������ĵ�ĺ����� 
	printf("Please input the point's x lable which would be calculated:");
	scanf("%lf",&x0);
	printf("The result is:%f",NewtonDifference(x,y,x0,n));           //����õ㾭�ɲ�ֵԭ������������꣬������������ 
	return 0;
}
