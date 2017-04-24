#include<stdio.h>
#include<string.h>
char x[100],y[100];
char b[100][100];
int c[100][100];
int m,n;
void lcs()
{
	int i,j; 
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='D';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='U';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='L';
			}
		}	
	}	
}

void printLCS(int i,int j)
{
	if(i==0 || j==0)
	{
		return;
	}
	if(b[i][j]=='D')
	{
		printLCS(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='U')
	{
		printLCS(i-1,j);
	}
	else
	{
		printLCS(i,j-1);
	}
}

void main()
{
	int i,j;
	printf("Enter Text 1 ");
	scanf("%s",x);
	printf("Enter Text 2 ");
	scanf("%s",y);
	lcs();
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		printf("%c %d  ",b[i][j],c[i][j]);
		printf("\n");	
	}
	printLCS(m,n);
}
