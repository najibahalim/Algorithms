//Fractional Knapsack Problem is a Greedy Algorithm which 
//helps in selecting specific items from a collection of items
//(the items can be fractioned)
//having specific weights and profits associated with them
//Under constraints of a sack capacity 
//Such that the profit is maximum

#include<stdio.h>
int n,m;
double w[100],p[100];//arrays that will store weights and profits of items 
double x[100];//Array that will store solution 

//Before calling this function the elements must be sorted on the basis of 
//decreasing profit by ratio
double fractional_knapsack(){
	double profit;//for calculating max profit
	int u,i;//u will keep track of capacity, i is a counter
	
	//Initilizing the soln vector to 0
	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	u=m;
	profit=0;
	//Collecting whatever is possible until capacity allows
	for(i=0;i<n;i++){
		if(w[i]>u)
			break;
		x[i]=1;
		profit+=p[i];
		u-=w[i];
	}
	
	//Taking Fractions of the remaining elements
	if(i<=n){
		x[i]=(double)u/w[i];
		profit+=(x[i]*p[i]);
	}
	return profit;
}


//Function that Sorts on the basis of Profit by Ratio
//(Using Insertion Sort)

void sortProfitByRatio(){
	double profit_ratio_array[100]={0.0};
	int i,j,temp,temp1,temp2;
	for(i=0;i<n;i++){
		profit_ratio_array[i]=p[i]/w[i];
	}
	for(i=1;i<n;i++){
		temp=profit_ratio_array[i];
		temp1=w[i];
		temp2=p[i];
		
		for(j=i-1;j>=0;j--){
			if(profit_ratio_array[j]<temp){
				profit_ratio_array[j+1]=profit_ratio_array[j];
				w[j+1]=w[j];
				p[j+1]=p[j];
			}
			else
				break;
		}
		profit_ratio_array[j+1]=temp;
		w[j+1]=temp1;
		p[j+1]=temp2;
		
	}
}


void main(){
	int i;
	double pr;
	printf("Enter the no of elements ");
	scanf("%d",&n);
	printf("Enter the capacity ");
	scanf("%d",&m);
	printf("Enter the weights and corresponding profits of the elements \n");
	for(i=0;i<n;i++)
		scanf("%lf %lf",&w[i],&p[i]);
	sortProfitByRatio();
	printf("After Sorting \n");
	for(i=0;i<n;i++)
		printf("%lf %lf \n",w[i],p[i]);
	pr=fractional_knapsack();
	printf("Total profit is %lf\n",pr);
	printf("Solution Vector\n");
	for(i=0;i<n;i++)
		printf("Item wt: %lf Quantity Taken: %lf\n",w[i],x[i]);
}
