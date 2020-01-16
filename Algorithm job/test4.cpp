#include<stdio.h>
#include<stdlib.h>
int V[100][100];//前i个物品装入容量为j的背包中获得的最大价值

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
//包的容量比该商品体积小，装不下，此时的价值与前i-1个的价值是一样的
				V[i][j]=V[i-1][j];
            else 
//还有足够的容量可以装该商品，但装了也不一定达到当前最优价值，所以在装与不装之间选择最优的一个
                V[i][j]=max(V[i-1][j],V[i-1][j-weight[i-1]]+value[i-1]);		
		}
	}
        return V[n][C];
        
}

//判断哪些物品被选中
void Judge(int C,int n,int weight[])
{			
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));
    for(int i=n;i>=1;i--)
	{
	    if(V[i][j]>V[i-1][j])
		{  //如果装了就标记，然后减去相应容量 
				state[i]=1;
				j=j-weight[i-1];
	    }
	    else
	        state[i]=0;
    }
    printf("\n选中的物品是:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
        	printf("%d ",i);
}
 
int main()
{
	printf("\n----------------");
	printf("01背包问题的动态规划");
	printf("----------------\n\n");
    int n;//物品数量 
    int Capacity;//背包最大容量
    
    printf("请输入背包的最大容量:");
    scanf("%d",&Capacity);
    
    printf("输入物品数:");
    scanf("%d",&n);
    
    int *weight=(int *)malloc(n*sizeof(int));//物品的重量
    int *value=(int *)malloc(n*sizeof(int)); //物品的价值
    
    int k=1;
    printf("\n请分别输入物品的重量:\n");
    for(int i=0;i<n;i++)
 	{
	 	printf("第%d个物品的重量：",k++); 
        scanf("%d",&weight[i]);
 	} 
 
 	int j=1;
    printf("\n请分别输入物品的价值:\n");
    for(int i=0;i<n;i++)
    {
    	printf("第%d个物品的价值：",j++);
    	scanf("%d",&value[i]);	
    }
 
    int s=KnapSack(n,weight,value,Capacity);  //获得的最大价值
    
    Judge(Capacity,n,weight);  //判断那些物品被选择 
 
    printf("\n最大物品价值为: ");
    printf("%d\n",s);
   
    return 0;
}

