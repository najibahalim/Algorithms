#include<stdio.h>
int w[100][100],c[100][100],r[100][100];
int tree[100]={0};
int p[100]={0},q[100]={0};
int n;
void obst()
{
	int i,j,m,k;
	for(i=0;i<=n-1;i++)
	{
		w[i][i]=q[i];
		c[i][i]=0;
		r[i][i]=0;
		
		w[i][i+1]=q[i]+q[i+1]+p[i+1];
		c[i][i+1]=q[i]+q[i+1]+p[i+1];
		r[i][i+1]=i+1;
	}
	w[n][n]=q[n];
	c[n][n]=0;
	r[n][n]=0;
	
	for(m=2;m<=n;m++)
	{
		for(i=0;i<=n-m;i++)
		{
			j=i+m;
			w[i][j]=w[i][j-1]+q[j]+p[j];
			k=find(i,j);
			c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
			r[i][j]=k;
		}
	}
}

int find(int i,int j)
{
	int m,l,min=9999;
	for(m=r[i][j-1];m<=r[i+1][j];m++)
	{
		if(c[i][m-1]+c[m][j]<min)
		{
			min=c[i][m-1]+c[m][j];
			l=m;
		}
	}
	return l;
}

void buildTree(int i,int j,int cr)
{
	int m;
	tree[cr]=r[i][j];
	m=r[i][j];
	if(i<m-1)
	buildTree(i,m-1,2*cr+1);
	if(m<j)
	buildTree(m,j,2*cr+2);
}
void main()
{
	int i,j;
	printf("Enter no of nodes ");
	scanf("%d",&n);
	printf("Enter successful probabilities\n");
	for(i=1;i<=n;i++)
	scanf("%d",&p[i]);
	printf("Enter Unsuccessful Probabilities\n");
	for(i=0;i<=n;i++)
	scanf("%d",&q[i]);
	obst();
	printf("CALCULATION TABLE\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			printf("%d %d %d\n",w[j][i+j],c[j][i+j],r[j][i+j]);
		}
		printf("\n");
	}
	buildTree(0,n,0);
	printf("\n Optimal Binary Search Tree :");
	for(i=0;i<=2*n+1;i++)
	printf("%d ",tree[i]);
}
