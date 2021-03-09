#include<stdio.h> 
#define MAX 500000
int isprime[MAX];
void PrimeTable(int M)
{
	int i,j;
	for(i=2;i<=M;i++)                      //判定预备：将所有的介于2和输入之间的数字对应的数组元素全部赋为1 
	isprime[i]=1;
	for(i=2;i<=M;i++)                      //判定开始：遍历数组中所有有定义的单元 
	{
		if(isprime[i]) 
		{
			for(j=i+i;j<=M;j+=i)           //若一个数字为质数（即数字对应的数组单元值为1），则令该数字的所有倍数对应的数组单元全部赋0，指代这些数字的合数身份 
			isprime[j]=0;
		}
	}
}

int main()
{
	int i,m;
	printf("请输入m(1<m<500000):");
	scanf("%d",&m);
	printf("2到%d的整数中质数有：\n",m);
	PrimeTable(m);
	for(i=2;i<=m;i++)                      //循环输出：凡是判定为质数（即，数组中对应数不为0） 的数字，全部输出并制表 
	{
		if(isprime[i])
		printf("%d\t",i);
	}
	return 0;
}
