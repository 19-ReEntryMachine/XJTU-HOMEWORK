#include<stdio.h>
#include<string.h>

int main()                                            //��������ʼ 
{
	char num[20],numrev[20];                          //�������飬���ַ����������ʽ�洢���֣� 
	int i;                                            //�����������������ڿ���ѭ���� 
	printf("Please input the integer:");              //�������֣� 
	gets(num);
	numrev[strlen(num)]=0;                            //���췴ת��������������ĺ���λ�������ֹ���� 
	for(i=0;i<strlen(num);i++)                        //ʹ��ԭ����һλ��Ϊ��ת�������һλ��ԭ���ڶ�λ��Ϊ��ת���ĵ����ڶ�λ���Դ����ƣ� 
	{
		numrev[i]=num[strlen(num)-i-1];
	}
	if(strcmp(num,numrev)==0)                         //�ȽϷ�תǰ�����ַ����Ƿ���ڲ��죻 
	{
		printf("This integer is reversable.");        //����תǰ�����ַ�����ͬ����Ƹ������ǶԳƵģ������֮Ϊ���ԳƵģ� 
	}
	else
	{
		printf("This integer is irreversable.");
	}
	return 0;                                         //���������� 
}
