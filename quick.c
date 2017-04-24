#include<stdio.h>
 int a[20],n;
 
 void quicksort(int low,int high)
 {
 	if(low<high)
 	{
 		int j=partition(low,high);
 		quicksort(low,j-1);
 		quicksort(j+1,high);
	}
 }
 
 int partition(int low,int high)
 {
 	int i=low,j=high,pivot=a[low];
 	int temp;
 	while(i<j)
 	{
 		while(a[i]<=pivot && i<high)
 		{
 			i++;
		}
		
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
 }
 void main()
 {
 	int i;
 	printf("Enter the size of array ");
 	scanf("%d",&n);
 	printf("Enter the elements of the array\n");
 	for(i=0;i<n;i++)
 	scanf("%d",&a[i]);
 	quicksort(0,n-1);
 	printf("The sorted array is:\n");
 	for(i=0;i<n;i++)
 	printf("%d\t",a[i]);
 }
