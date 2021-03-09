#include<stdio.h>                                        //������ҵ������ʹ����C++�������еĲ��������������Ҫ����iostreamͷ������std�����ռ� 
#include<iostream>
using namespace std;
int MAX=100;                                             //�������ֵ 

typedef struct                                           //����߽ṹ�壬�����ߵ���㡢�ص㡢Ȩ���Լ����Ƿ��������С�������ڡ� 
{
	int begin;
	int end;
	int weight;
	bool selection;
	//int selection;���������ȫ��C����ʱ����д���� 
}Edge;

void Kruskal(Edge* edge,int n,int m,int* parent)         //��������������ִ��Kruskal�㷨������С������ 
{
	int i,j;                                             //����ѭ�����Ʊ��� 
	for(i=0;i<m-1;i++)                                   //�����㷨����ȫ���߰�Ȩֵ��С�������� 
	{
		for(j=i+1;j<m;j++)                               //�������ѡ�������㷨���������������Ȩ�ر���С�ıߣ���ô�����������߽������� 
		{
			if(edge[i].weight>edge[j].weight)
			{
				Edge k=edge[i];
				edge[i]=edge[j];
				edge[j]=k;
			}
		}
	}
	i=0,j=0;                                             //����ѭ�����Ʊ�������ʼ������С������ 
	while(j<n-1)                                         //����WHILE��䣬j���ڿ�����С�������бߵ����� 
	{
		int p=edge[i].begin,q=edge[i].end;               //����������������������Ѱ��ͬһ�߶�Ӧ���������ɹ����еĸ� 
		while(parent[p]!=-1)                             //Ѱ�ұ����������εĸ�����ͬ�����Ǳ��������Ǳߵ��յ㣩 
		{
			p=parent[p];
		}
		while(parent[q]!=-1)
		{
			q=parent[q];
		}
		if(p!=q)                                         //���ߵ���������в�ͬ�ĸ�����ô����Kruskal�㷨�������߽���������С�������� 
		{
			edge[i].selection=true;
			parent[edge[i].end]=edge[i].begin;           //���ñߵ����㶨��Ϊ�������ӽ�㡱 
			j++;
		}
		i++;                                             //����һ���ߵ������������ʼ����һ���߽������� 
	}
}

int main()                                               //��������ʼ 
{
	int parent[100],n,m,i,j;                             //�����������飬�����������������н��ĸ��ڵ㣻�������ͱ��������ڴ洢ͼ��������Ϣ 
	Edge edges[100];                                     //�����ṹ�����飬��������ͼ��ȫ���ߵ���Ϣ 
	printf("������ͼ�а������ܵ������ܱ���:\n");         //������ʾ����ͼ�а����ıߡ�����Ŀ����������ڴ��У� 
	scanf("%d %d",&n,&m); 
	//cout<<"������ͼ�а������ܵ������ܱ�����"<<endl;
	//cin>>n>>m;
	printf("����������ͼ�а����ıߵ���ʼ���Ȩֵ:\n");   //������ʾ����ͼ��ȫ���ߵľ�����Ϣ����������ڴ��У�
	//cout<<"����������ͼ�а����ıߵ���ʼ���Ȩֵ��"<<endl;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&edges[i].begin,&edges[i].end,&edges[i].weight);
		//cin>>edge[i].begin>>edge[i].end>>edge[i].weight;
		//edge[i].selection=false;
		edges[i].selection=false;                        //��ʼ���ߵ���Ϣ�����б��ھ����㷨����ǰ��δ��ѡ�У����������ж������и��ڵ� 
		parent[i]=-1;
	}
	Kruskal(edges,n,m,parent);                           //����Kruskal�������ҳ���С�������бߵ����� 
	j=1; 
	for(i=0;i<m;i++)                                     //����Ҫ��������������������������� 
	{
		if(edges[i].selection==true)
		{
			printf("��ѡ�еĵ�%d���ߵ���ʼ����%d��%d��Ȩֵ��%d\n",j,edges[i].begin,edges[i].end,edges[i].weight);
			j++;
		}
	}
	return 0; 
}
