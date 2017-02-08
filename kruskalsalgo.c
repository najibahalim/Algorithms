#include<stdio.h>

int cost[100][100],n; //cost matrix for storing the graph,n=no of nodes
int t[100][2]; //t is the solution vector
int k,l;
int conn[100]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void minEdge(); //to select minimum edge from the graph



int kruskals_algo(){
 int mincost=0,num=0,i;
 for(i=0;i<n-1;i++){
  minEdge();
  if(formsCycle(i-1)==1){
   cost[k][l]=99;
   cost[l][k]=99;
   i--;
   continue;
  }
  else
   mincost=mincost+cost[k][l];
  if(cost[i][k]>=99)
   num++;
  if(cost[i][l]>=99)
   num++;
  t[i][0]=k;
  t[i][1]=l;
  conn[l]=k;
  cost[k][l]=99;
  cost[l][k]=99;
  if(num>=n){//to check for isolated nodes
   if(allConnected())
    return mincost;
  }
 }
 return mincost;
}

void minEdge(){
 int i,j;
 int min=98;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   if(cost[i][j]<min){
    min=cost[i][j];
    k=i;
    l=j;
   }
}

int formsCycle(int x)
{
	int i=l,j=k;
	while(conn[i]!=-1){
		if(conn[i]==k)
		return 1;
		i=conn[i];
	}
	while(conn[j]!=-1){
		j=conn[j];
	}
	if(i==j)
		return 1;
	return 0;
	
}
int allConnected(){
 int i,j;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   if(cost[i][j]<99)
    return 0;
 return 1;
}

void main(){
  int i,j,p=0;
  printf("Enter the no of nodes ");
  scanf("%d",&n);
  printf("Enter the Adjecency represenation of the graph\n");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++){
    scanf("%d",&cost[i][j]);
	}
  p=kruskals_algo();
  printf("\nSolution Vector \n");
  for(i=0;i<n-1;i++)
   printf("%d--%d\n",t[i][0]+1,t[i][1]+1);
  printf("\nMinCost=%d",p);
 }

