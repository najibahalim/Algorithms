#include<stdio.h>
int w[100],x[100];
int n,m;
void sos(int s,int k,int r)
{
	int i;
	x[k]=1;
	if(s+w[k]==m)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
		printf("\n");
	}
	else if(s+w[k]+w[k+1]<=m)
		sos(s+w[k],k+1,r-w[k]);
	if((s+r-w[k]>=m) && (s+w[k+1]<=m))
	{
		x[k]=0;
		sos(s,k+1,r-w[k]);
	}
}
void main()
{
	int i,j=0;
	printf("Enter the no of elements in the set ");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		j=j+w[i];
	}
	printf("Enter required sum ");
	scanf("%d",&m);
	sos(0,1,j);
}
