#include<stdio.h>
#include<math.h>
float Function(float x)                                                       //������������һ�������ڼ��㷽�������ʽ����ֵ 
{
	//�����򸡱꣬���ڼ���������������printf("f(%f)=%f\n",x,5*sin(x)-x/2-1); �� 
	return 5*sin(x)-x/2-1;
}

int main()                                                                    //��������ʼ 
{
	float fa,fb,mid,epsilon,solution=0;                                       //�����������������ˣ������յ㣬������ȣ���Ľ��ۣ����Ǹ��⸳��һ����ֵ0����������һ��ʵ�ʵĿ��н⣬�������0�Ժ���õ��� 
	printf("Please give us the left and right range of the root solving:");   //������ʾ��������˵㣻 
	scanf("%f %f",&fa,&fb);
	if(fa>fb)                                                                 //�����������˵㲢������С�Ҵ󣬳�����Զ��������������Է�������� 
	{
		int k=fb;
		fb=fa;
		fa=k;
	}
	if(Function(fa)*Function(fb)>0)                                           //�����������ʽ������˵㴦����ֵͬ�ţ���δ���ܽ����ֵ�⣬��ʱ�����Զ���ֹ�� 
	{
		printf("ERROR RANGE,PROGRAM ENDING");
	}
	else if((Function(fa)==0)||(Function(fb)==0))                             //�����������ʽ������ĳ���˵㴦ȡ����0�����Ǹ�����˵��λ�ø�������� 
	{
		solution=Function(fa)==0?fa:fb;                                       //��������Լ����ʺű��ʽ�� 
	}
	else
	{
		printf("Please give us accuracy of the root solving:");               //��һ������£�����Ҫ�Ȱ�����ʾ���뾫��Ҫ�� 
	    scanf("%f",&epsilon);
	    do{
	    	mid=(fa+fb)/2;                                                    //���������е㴦�������ʽ��ֵ�� 
	    	if(Function(mid)*Function(fa)<0)                                  //��������е㴦��������˵㴦�������ʽֵ��ţ��������е�ֵ���������Ҷ˵������ 
	    	{
	    		fb=mid;
			}
			else if(Function(mid)==0)                                         //����������ʽǡ�����е㴦ȡ��0��ѭ��ֹͣ�������е�λ�ø���������� 
			{
				break;
			}
			else                                                              //��������е㴦�������Ҷ˵㴦�������ʽֵ��ţ��������е�ֵ����������˵������ 
			{
				fa=mid;
			}
			//�����򸡱꣬���ڼ���������������printf("%f\n",fabs(fa-mid));�� 
		}while(fabs(fa-fb)>=epsilon);                                         //�����䳤��С�ھ���Ҫ��ʱ��ѭ����ֹ�����������е㸳������� 
		solution=mid;
	}
	if(solution!=0)                                                           //ֻҪ�����������н⣨Ҳ����˵����������ǳ�ʼ��0������ô���������⣻ 
	{
		printf("The solution of the equation'5sin(x)-0.5x-1=0'is:%f",solution);
	}
	return 0;                                                                 //���������� 
} 
