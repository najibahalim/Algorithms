#include<stdio.h>

int cost[100][100],n;//cost matrix for storing the graph,n=no of nodes
int t[100][2];//t is the solution vector
int near[100];//for determining the nearest nodes in the graph

int prims_Algorithm(int start_node){
	int k=start_node,l=minNode(start_node);
	int i,j;
	int min_cost=cost[k][l];
	t[1][0]=k;
	t[1][1]=l;
	
	//exploring the first 2 nodes and initializing the near array
	for(i=1;i<=n;i++)
		if(cost[i][k]<cost[i][l])
			near[i]=k;
		else
			near[i]=l;
		near[k]=near[l]=0; //A value 0 in near array means the node has been visited
	
	//Exploring the Remaining nodes and constructing the tree 
	for(i=2;i<=n-1;i++){
		j=nextNode();
		t[i][0]=j;
		t[i][1]=near[j];
		min_cost=min_cost+cost[j][near[j]];
		near[j]=0;
		//Updating the near array considering the newly visited node
		for(k=1;k<=n;k++){
			if(near[k]!=0 && cost[k][near[k]]>cost[k][j])
				near[k]=j;
		}
		
	}
	return min_cost;
	
}

//Function to decide the nearest node to a particular node
 int minNode(int s){
 	int i,min=99,j=99;
 	for(i=1;i<=n;i++){
 		if(cost[s][i]<min){
 			j=i;
 			min=cost[s][i];
		 }
	 }
	 return j;
 }
 
 
 //Function to decide the next node to be considered in the tree
 int nextNode(){
 	int i,j,min;
 	min=99;
 	for(i=1;i<=n;i++){
 		if(near[i]!=0 && cost[i][near[i]]<min){
 			min=cost[i][near[i]];
 			j=i;
		 }
	 }
	 return j;
 }
 
 
 void main(){
 	int i,j,s,p;
 	printf("Enter the no of nodes ");
 	scanf("%d",&n);
 	printf("Enter the Adjecency represenation of the graph\n");
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++)
 			scanf("%d",&cost[i][j]);
 	printf("Enter the start node ");
 	scanf("%d",&s);
 	p=prims_Algorithm(s);
 	printf("\nSolution Vector \n");
 	for(i=1;i<=n-1;i++)
 		printf("%d--%d\n",t[i][0],t[i][1]);
 	printf("\nMinCost=%d",p);
 }
