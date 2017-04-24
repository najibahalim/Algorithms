#include<stdio.h>
#include<string.h>
#include<math.h>
char text[100],pattern[100];
void rabinKarpMatcher(int d,int q)
{
	int m,n,i,s,h,p,t;
	n=strlen(text);
	m=strlen(pattern);
	h=pow(d,m-1);
	h=h % q;
	p=0;
	t=0;
	i,s;
	//printf("m=%d\tn=%d\th=%d\tq=%d\n",m,n,h,q);
	for(i=0;i<m;i++)//Preprocessing
	{
		p=(d*p+pattern[i])%q;
		t=(d*t+text[i])%q;
		//printf("i=%d\tp=%d\tt=%d\n",i,p,t);
	}
	for(s=0;s<=(n-m);s++)
	{
		//printf("s=%d\t",s);
		if(p==t)
		{
			for (i = 0; i < m; i++)
			{
				if (text[i+s] != pattern[i])
					break;
			}
			if (i==m)
			
				printf("Pattern occours with shift %d\n",s);
		}
		
		if(s<(n-m))
		{
			t=(d*(t-text[s]*h)+text[s+m]);
			t=t % q;
			if (t < 0)
			t = (t + q);
		}
		//printf("t=%d\n",t);
		
		
	}

}

void main()
{
	int x;
	printf("Enter the text ");
	scanf("%s",text);	
	printf("Enter the Pattern ");
	scanf("%s",pattern);
	rabinKarpMatcher(10,3);
}

