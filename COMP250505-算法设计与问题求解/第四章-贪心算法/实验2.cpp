#include<stdio.h>
struct Node                                                //����ṹ����������㣬������ֹʱ���������� 
{
	int start;
	int end;
};

int main()                                                //��������ʼ 
{
	int n,i,j;                                            //����ṹ�����飬���ڴ�Ż��Ϣ��������Ʊ����ͼ������������������Կ���ѭ����ǰһ������ͳ�ƻ���� 
	struct Node arr[1000]; 
	printf("����������ŵĻ������");                   //������ʾ�������� 
	scanf("%d",&n);
	printf("����������Ż����ֹʱ�䣺\n");             //������ʾ�����������ֹʱ�䲢�����ڴ��� 
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].start,&arr[i].end);
	}
	for(i=0;i<n-1;i++)                                    //���ս���ʱ���Ⱥ���ڻ���������Ƚ�������ǰ�� 
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].end>arr[j].end)
			{
				struct Node arrangement;
				arrangement=arr[i];
				arr[i]=arr[j];
				arr[j]=arrangement;
			}
		}
	}
	int time=arr[0].end,activnum=1;                       //Ĭ���Ȱ������������һ�����������һ����������ͳ�ƿɰ��Ż��Ŀ 
	for(i=1;i<n;i++)                                      //̰���㷨���ӵ�һ�����ʼ����һ����ʼʱ���������ġ���������Ļ�������ţ��Դ�������� 
	{
		if(arr[i].start>time)
		{
			activnum++;                                   //����һ����������ϣ�������������� 
			time=arr[i].end;
		}
	}
	printf("���ɰ��ŵĻ����Ϊ%d",activnum);          //������������������������
	return 0; 
}
