#include<stdio.h>
char str[10];                             //����ȫ�ֱ������Է������ڵ�������ֵ��ʧ 
void Output(int position,int length)      //�������������ȫ��ȫ�������� 
{
	if(position==length)                  //���ַ����Ѿ����������������ַ��� 
	{
		printf("%s  ",str);
	}
	else                                  //���ַ���δ�����������������һλδ�������ַ��ռ� 
	{
		int i;
		for(i=0;i<length;i++)             //�������п��ܵ�������� 
		{
			str[position]='A'+i;          //��������ڸô洢�ռ���ַ� 
			Output(position+1,length);    //��������ȷ����һ�������ڼ���ȷ�������п��ܵģ��ַ��ֻ�������� 
		}
	}
}

int main()                                //��������ʼ 
{
	int n;                                //�������еĳ��Ȳ�������ʾ����֮ 
	printf("Input n:");
	scanf("%d",&n);
	Output(0,n);                          //��Դ˳��������ĸ��ȫ�������У����������� 
	return 0;
}
