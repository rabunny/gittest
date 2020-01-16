#include<stdio.h>
#define M 100
//快速排序 
void S(int a[],int l,int r)//交换 
{
	int t;
	t=a[l];
	a[l]=a[r];
	a[r]=t;
}

int P(int a[],int l,int r)//排序 
{
	int x=a[l];
	while(l<r)
	{
		while(l<r&&a[r]>=x)
			r--;
		S(a,l,r);
		while(l<r&&a[l]<=x)
			l++;
		S(a,l,r); 
	}
	return l; 
} 

void Qui(int a[],int l,int r)//递归调用 
{
	if(l<r)
	{
		int x=P(a,l,r);
		Qui(a,l,x-1);
		Qui(a,x+1,r);
	}
}

//二分搜索：循环 
int  BSearch(int a[],int x,int n)
{
	int left=0,right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(x==a[mid])
		{
			printf("要查找的%d在第%d个位置。",x,mid+1);
			return mid;
		}	
		else if(x<a[mid])
			right = mid-1;
		else 
			left = mid+1;
	}
	printf("没有这个数!");
	return -1;
}

//二分搜索：递归
int BSearch_digui(int a[],int left,int right,int x)
{
	if(left>right)
		printf("没有这个数！");
	else
	{
		int mid = (left+right)/2;
		if(x==a[mid])
			printf("要查找的%d在第%d个位置。",x,mid+1);
		else if(x<a[mid])
			return BSearch_digui(a,left,mid-1,x);
		else
			return BSearch_digui(a,mid+1,right,x);
	}
	
} 

int main()
{
	int a[M],x,i,j,n,k;
	
	printf("请输入要操作的元素个数：");
	scanf("%d",&n);
	printf("请输入%d个整数：",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("\n----------------");
	printf("快速排序");
	printf("----------------\n");
	printf("\n排序后的数列为：");
	Qui(a,0,n-1);
	for(j=0;j<n;j++)
		printf("%-4d",a[j]);	
		
	printf("\n\n----------------");
	printf("循环二分搜索");
	printf("----------------\n"); 
	printf("\n已排好的数列为：");
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
			
	printf("\n请输入要查找的数：");
	scanf("%d",&x); 
	BSearch(a,x,n);
	
	int left=0,right=n-1;
	printf("\n\n----------------");
	printf("递归二分搜索");
	printf("----------------\n\n");
	printf("已排好的数列为：");
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
	printf("\n请输入要查找的数：");
	scanf("%d",&x); 
	BSearch_digui(a,left,right,x);
	
	printf("\n\n----------------");
	printf("输出k个最小的数");
	printf("----------------\n\n");
	printf("请输入要输出的k个最小的数（k<=%d)：",n);
	scanf("%d",&k); 
	printf("最小的%d个数为：",k);
	Qui(a,0,n-1);
	for(j=0;j<k;j++)
		printf("%-4d",a[j]);
}
