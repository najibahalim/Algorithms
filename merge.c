#include<stdio.h>
 int a[20],n;
 
 void part(int low,int high)
 {
 	int mid;
 	if(low<high)
 	{
 		mid=(low+high)/2;
 		part(low,mid);
 		part(mid+1,high);
 		merge(low,mid,high);
	}
 }
 
 void merge(int low,int mid,int high)
 {
 	int i,j,k,b[10];
 	i=low;
 	j=mid+1;
 	k=low;
 	while(i<=mid && j<=high)
 	{
 		if(a[i]<a[j])
 		{
 			b[k]=a[i];
 			i++;
 			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
		
	}
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		k++;
		j++;	
	}
	for(i=low;i<=high;i++)
	{
		a[i]=b[i];
	}
 }
 
 
  void main()
 {
 	int i;
 	printf("Enter the size of array ");
 	scanf("%d",&n);
 	printf("Enter the elements of the array\n");
 	for(i=0;i<n;i++)
 	scanf("%d",&a[i]);
 	part(0,n-1);
 	printf("The sorted array is:\n");
 	for(i=0;i<n;i++)
 	printf("%d\t",a[i]);
 }
