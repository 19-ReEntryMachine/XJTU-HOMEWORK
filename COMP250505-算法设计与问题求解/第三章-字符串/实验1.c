#include<stdio.h> 
#include<string.h>
void TrimLeft(char* string)                //�����������ո�ɾ�� 
{
	int i;                                 //������������������ѭ������ 
	for(i=strlen(string)-1;;i--)           //���ַ������һ���ַ���ʼ��ɾȥȫ���ո�ֱ������һ���ǿո��ַ��� 
	{
		if(string[i]==' ')
		{
			string[i]=0;
		}
		else break;
	}
	int k=0;                              //�����������������ڼ���ǰ���ո����� 
	for(i=0;;i++)                         //�ӵ�һ���ַ���ʼ��������ͷ�ո���Ŀ��ֱ������һ���ǿո��ַ��� 
	{
		if(string[i]==' ')
		{
			k++;
		}
		else break;
	}
	for(i=0;;i++)                         //���ո����ַ�����������ǰ�ƣ�ƽ�ƿռ���ո�����ͬ�����ַ�����ֹ����ֹͣ�� 
	{
		if(string[i+k-1]==0)
		{
			break;
		}
		string[i]=string[i+k];
	}
}

int main()                                //��������ʼ�� 
{
	char string[80];                      //�����������ַ����� 
	printf("Please input the string:");
	gets(string);
	TrimLeft(string);                     //ɾȥ����ո������Ӧ�ַ��������������� 
	printf("%s",string);
	return 0;
} 
