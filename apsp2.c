#include<stdio.h>
int n;
int a[100][100],c[100][100];
void apsp()
{
	int i,j,k;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	a[i][j]=c[i][j];
	
	
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}

int min(int x,int y)
{
	if(x<y)
	return x;
	else
	return y;
}

void main()
{
	int i,j;
	printf("Enter no of nodes ");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&c[i][j]);
	
	apsp();
	printf("All Pair Shortest Path Matrix is:\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	printf("%d ",a[i][j]);
	printf("\n");
	}
}
