#include<stdio.h>
#include<string.h>
//1ָ��ʤ����0ָ��û��ʤ��֮�� 
void PutInPiece(char player,int x,int y,char checkerboard[][20])     //������������������ 
{
	if(checkerboard[x][y]=='-')                                      //����λ��Ϊ�գ�����ҵĴ�����洢����Ӧλ�õĴ洢��Ԫ 
	{
		checkerboard[x][y]=player;
	}
	else printf("WRONG PLACE!");                                     //����λ���Ѿ���������ҵı�ǣ�����ֹ���ý��̲���ʾ 
}
int CheckingVictory(char player,char checkerboard[][20])             //����������ʤ���ж� 
{
	int i,j,k;                                                       //��������������ǰ��������ȷ��λ�ã���һ�������ж��������� 
	for(i=1;i<=19;i++)                                               //�����������ϵ�ÿ���㣻ע�⣺���ڱ��������Ͻǿ�ʼ�������ж�ʱ���ؿ�������������������� 
	{
		for(j=1;j<=19;j++)
		{
			if(checkerboard[i][j]==player)                           //�ҵ�����ҷ��õ�һ�����Ӻ�ʼ�ж����� 
			{
				if(checkerboard[i][j+1]==player&&j<=15)              //�ж��Ƿ��ܹ���������������-�������������������������������ӣ����һ��Լ���������ڷ�ֹ���ù����з���Խ�� 
				{
					for(k=2;k<=5;k++)                                //���������������ӣ���鿴�·��Ƿ������������ӣ�������ֱ����ֹ���̣�������ֱ���ж�ʤ�� 
					{
						if(checkerboard[i][j+k]!=player)
						{
							break;
						}
					}
					if(k==5)
					{
						return 1;
					}
				}
				if(checkerboard[i+1][j]==player&&i<=15)              //�ж��Ƿ��ܹ��ں�����������-�����������ں������������������ӣ����һ��Լ���������ڷ�ֹ���ù����з���Խ��
				{
					for(k=2;k<=5;k++)                                //���������������ӣ���鿴�ҷ��Ƿ������������ӣ�������ֱ����ֹ���̣�������ֱ���ж�ʤ��
					{
						if(checkerboard[i+k][j]!=player)
						{
							break;
						}
					}
					if(k==5)
					{
						return 1;
					}
				}
				if(checkerboard[i+1][j+1]==player&&i<=15&&j<=15)     //�ж��Ƿ��ܹ�����б����������-��������������б�����������������ӣ����һ��Լ���������ڷ�ֹ���ù����з���Խ�� 
				{
					for(k=2;k<=5;k++)                                //���������������ӣ���鿴���·��Ƿ������������ӣ�������ֱ����ֹ���̣�������ֱ���ж�ʤ�� 
					{
						if(checkerboard[i+k][j+k]!=player)
						{
							break;
						}
					}
					if(k==5)
					{
						return 1;
					}
				}
				if(checkerboard[i-1][j+1]==player&&i>=5&&i<=15)      //�ж��Ƿ��ܹ�����б����������-��������������б�����������������ӣ����һ��Լ���������ڷ�ֹ���ù����з���Խ�� 
				{
					for(k=2;k<=5;k++)                                //���������������ӣ���鿴���·��Ƿ������������ӣ�������ֱ����ֹ���̣�������ֱ���ж�ʤ��
					{
						if(checkerboard[i+k][j+k]!=player)
						{
							break;
						}
					}
					if(k==5)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;                                                        //�������������̺�û���ҵ�����ɹ����������ӣ������0�Ա�ʾ���޷��ж��� 
}
void PrintBoard(char checkerboard[][20])                             //����������������� 
{
	int i,j;                                                         //���������������ڿ���ѭ�� 
	for(j=0;j<=19;j++)                                               //�����������е�ȫ��Ԫ�������ע�⻻�� 
	{
		for(i=0;i<=19;i++)
		{
			printf("%c",checkerboard[i][j]);
		}
		printf("\n");
	}
}

int main()                                                           //��������ʼ 
{
	char checkerboard[20][20];                                       //�����������飬������ұ�ʶ�� 
	char black='A',white='B';
	int i,j,x,y;                                                     //�������ͱ�����ǰ�������ڿ���ѭ�����ж�ʤ����������������ʱ�������λ�� 
	checkerboard[0][0]=' ';                                          //��������ԭ�� 
	for(i=1;i<=19;i++)                                               //�������̺��� 
	{
		checkerboard[i][0]='0'+(i-1)%10;
	}
	for(i=1;i<=19;i++)                                               //������������ 
	{
		checkerboard[0][i]='0'+(i-1)%10;
	}
	for(i=1;i<=19;i++)                                               //�ÿձ�ʶ����-����������ϵ������ռ� 
	{
		for(j=1;j<=19;j++)
		{
			checkerboard[i][j]='-';
		}
	}
	PrintBoard(checkerboard);                                        //������̣���Ϸ��ʼ 
	do{
		printf("Black:");                                            //�ڷ����ߣ�������ʾ����Ҫ�µ����ӵ�λ�� 
		scanf("%d %d",&x,&y);
		PutInPiece(black,x,y,checkerboard);                          //�����ӷ������������У����ж��Ƿ�����ʤ����������������ֱ����ֹѭ�� 
		PrintBoard(checkerboard);
		i=CheckingVictory(black,checkerboard);
		if(i==1)
		{
			break;
		}
		printf("White:");                                            //�׷����ߣ�������ʾ����Ҫ�µ����ӵ�λ��
		scanf("%d %d",&x,&y);
		PutInPiece(white,x,y,checkerboard);                          //�����ӷ������������У����ж��Ƿ�����ʤ������
		PrintBoard(checkerboard);
		j=CheckingVictory(white,checkerboard);
	}while(i==0&&j==0);                                              //���׷�����ʤ�������������ֹ 
	if(i==1)                                                         //���ʤ����Ϣ������������Ϸ������ 
	{
		printf("Black Win!!");
	}
	else printf("White Win!!");
}
