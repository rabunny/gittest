#include<stdio.h>
#define M 100
//�������� 
void S(int a[],int l,int r)//���� 
{
	int t;
	t=a[l];
	a[l]=a[r];
	a[r]=t;
}

int P(int a[],int l,int r)//���� 
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

void Qui(int a[],int l,int r)//�ݹ���� 
{
	if(l<r)
	{
		int x=P(a,l,r);
		Qui(a,l,x-1);
		Qui(a,x+1,r);
	}
}

//����������ѭ�� 
int  BSearch(int a[],int x,int n)
{
	int left=0,right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(x==a[mid])
		{
			printf("Ҫ���ҵ�%d�ڵ�%d��λ�á�",x,mid+1);
			return mid;
		}	
		else if(x<a[mid])
			right = mid-1;
		else 
			left = mid+1;
	}
	printf("û�������!");
	return -1;
}

//�����������ݹ�
int BSearch_digui(int a[],int left,int right,int x)
{
	if(left>right)
		printf("û���������");
	else
	{
		int mid = (left+right)/2;
		if(x==a[mid])
			printf("Ҫ���ҵ�%d�ڵ�%d��λ�á�",x,mid+1);
		else if(x<a[mid])
			return BSearch_digui(a,left,mid-1,x);
		else
			return BSearch_digui(a,mid+1,right,x);
	}
	
} 

int main()
{
	int a[M],x,i,j,n,k;
	
	printf("������Ҫ������Ԫ�ظ�����");
	scanf("%d",&n);
	printf("������%d��������",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("\n----------------");
	printf("��������");
	printf("----------------\n");
	printf("\n����������Ϊ��");
	Qui(a,0,n-1);
	for(j=0;j<n;j++)
		printf("%-4d",a[j]);	
		
	printf("\n\n----------------");
	printf("ѭ����������");
	printf("----------------\n"); 
	printf("\n���źõ�����Ϊ��");
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
			
	printf("\n������Ҫ���ҵ�����");
	scanf("%d",&x); 
	BSearch(a,x,n);
	
	int left=0,right=n-1;
	printf("\n\n----------------");
	printf("�ݹ��������");
	printf("----------------\n\n");
	printf("���źõ�����Ϊ��");
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
	printf("\n������Ҫ���ҵ�����");
	scanf("%d",&x); 
	BSearch_digui(a,left,right,x);
	
	printf("\n\n----------------");
	printf("���k����С����");
	printf("----------------\n\n");
	printf("������Ҫ�����k����С������k<=%d)��",n);
	scanf("%d",&k); 
	printf("��С��%d����Ϊ��",k);
	Qui(a,0,n-1);
	for(j=0;j<k;j++)
		printf("%-4d",a[j]);
}
