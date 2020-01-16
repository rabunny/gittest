#include<stdio.h>
#include<stdlib.h>
int V[100][100];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ

int max(int a,int b)
{
   	if(a>=b)
		return a;
   	else 
		return b;
}
 
int KnapSack(int n,int weight[],int value[],int C)
{
		    
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=C;j++)
		{
            if(j<weight[i-1]) 
//���������ȸ���Ʒ���С��װ���£���ʱ�ļ�ֵ��ǰi-1���ļ�ֵ��һ����
				V[i][j]=V[i-1][j];
            else 
//�����㹻����������װ����Ʒ����װ��Ҳ��һ���ﵽ��ǰ���ż�ֵ��������װ�벻װ֮��ѡ�����ŵ�һ��
                V[i][j]=max(V[i-1][j],V[i-1][j-weight[i-1]]+value[i-1]);		
		}
	}
        return V[n][C];
        
}

//�ж���Щ��Ʒ��ѡ��
void Judge(int C,int n,int weight[])
{			
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));
    for(int i=n;i>=1;i--)
	{
	    if(V[i][j]>V[i-1][j])
		{  //���װ�˾ͱ�ǣ�Ȼ���ȥ��Ӧ���� 
				state[i]=1;
				j=j-weight[i-1];
	    }
	    else
	        state[i]=0;
    }
    printf("\nѡ�е���Ʒ��:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
        	printf("%d ",i);
}
 
int main()
{
	printf("\n----------------");
	printf("01��������Ķ�̬�滮");
	printf("----------------\n\n");
    int n;//��Ʒ���� 
    int Capacity;//�����������
    
    printf("�����뱳�����������:");
    scanf("%d",&Capacity);
    
    printf("������Ʒ��:");
    scanf("%d",&n);
    
    int *weight=(int *)malloc(n*sizeof(int));//��Ʒ������
    int *value=(int *)malloc(n*sizeof(int)); //��Ʒ�ļ�ֵ
    
    int k=1;
    printf("\n��ֱ�������Ʒ������:\n");
    for(int i=0;i<n;i++)
 	{
	 	printf("��%d����Ʒ��������",k++); 
        scanf("%d",&weight[i]);
 	} 
 
 	int j=1;
    printf("\n��ֱ�������Ʒ�ļ�ֵ:\n");
    for(int i=0;i<n;i++)
    {
    	printf("��%d����Ʒ�ļ�ֵ��",j++);
    	scanf("%d",&value[i]);	
    }
 
    int s=KnapSack(n,weight,value,Capacity);  //��õ�����ֵ
    
    Judge(Capacity,n,weight);  //�ж���Щ��Ʒ��ѡ�� 
 
    printf("\n�����Ʒ��ֵΪ: ");
    printf("%d\n",s);
   
    return 0;
}

