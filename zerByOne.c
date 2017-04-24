#include<stdio.h>
int b[100][100],w[100],p[100],n,m;
void zeroByOneKnapsack()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		b[i][0]=0;
	}
	for(i=0;i<=m;i++)
	{
		b[0][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(w[i]<=j)
			{
				if(p[i]+b[i-1][j-w[i]]>b[i-1][j])
				{
					b[i][j]=p[i]+b[i-1][j-w[i]];	
				}
				else
				{
					b[i][j]=b[i-1][j];
				}
			}
			else
				b[i][j]=b[i-1][j];
		}
	}
}

void findItem()
{
	int profit,i,k;
	i=n;
	k=m;
	profit=0;
	while(i>0 && k>0)
	{
		if(b[i][k]==b[i-1][k])
			i--;
		else
		{
			printf("Mark %dth item on sack\n",i);
			k=k-w[i];
			profit+=p[i];
		}
	}
	printf("Total profit=%d",profit);
	
}

void main()
{
	int i,j;
	printf("Enter no of items ");
	scanf("%d",&n);
	printf("Enter max capacity ");
	scanf("%d",&m);
	printf("Enter weights and profits\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&p[i]);
	}
	zeroByOneKnapsack();
	findItem();
	
}
