#include<stdio.h> 
#include<string.h> 
int ConvertToInt(char* string)                 //�������������ֵ��ַ���-����ת�� 
{
	int k=0,i;                                 //����������k��Ϊ���ռ���õ���������i��Ϊ���������������ڿ���ѭ���� 
	for(i=0;;i++)
	{
		if(string[i]==0)                       //��ֹ��������ȡ���ַ�����ֹ�� 
		{
			break;
		}
		k=k*10+string[i]-'0';                  //ʩ�н�λ�Ͳ�λ������*10ʹ������������ֽ�λ��+string[i]-'0'����һλ�������뵽��λ������һλ�� 
	}
	return k;                                  //����ת���õ��������� 
}

int main()                                     //��������ʼ 
{
	char str[20];                              //�������顢������ǰһ�����ڴ�Ŵ�������ַ�������һ�����ڴ��ת���õ������� 
	int num;
	printf("Please input the Integer:");       //������ʾ���������ַ��� 
	gets(str);
	num=ConvertToInt(str);                     //���ַ���ʵ��ת�������ת����������������� 
	printf("The integer is:%d",num);
	return 0;
}
