#include<stdio.h>
#include<math.h>
int x[100]={0};
void nQueen(int k,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				for(j=1;j<=n;j++)
				printf("Place Queen %d on Coloumn %d\n",x[j],j);
				printf("\n");
			}
			else
			nQueen(k+1,n);
		}
	}
}

int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return 0;	
	}	
	return 1;
}

void main()
{
	int n;
	printf("Enter the value of n ");
	scanf("%d",&n);
	nQueen(1,n);
}
