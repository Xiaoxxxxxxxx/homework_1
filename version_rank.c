#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
	int n,i,m,k=0;
	int (*rank)[size];
	int (*temp)[size];
	//int rank[n][size]={0};
	scanf("%d",&n);
	rank=(int (*)[10])malloc(n*10*sizeof(int));
	temp=(int (*)[10])malloc(n*10*sizeof(int));
	//ptd=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(k=0;k<size;k++)
		rank[i][k]=-1;
	}
	for(i=0,k=0;i<n;)
	{
		scanf("%d",&rank[i][k]);
		if(getchar()=='.')
		{
		k++;
		continue;
	    }
	    else
	    {
	    k=0;
	    i++;
	    }
	}
for(i=0,k=0;i<n;i++)
{
  for(m=i+1;m<n;)
	{   
	    if(rank[i][k]>rank[m][k])
	    {
	    	for(k=0;k<10;k++)
		    { 
	    	temp[i][k]=rank[i][k];
	    	rank[i][k]=rank[m][k];
	    	rank[m][k]=temp[i][k];
	        }
	        k=0;
	        m++;
	        continue;
		}
		else if(rank[i][k]==rank[m][k])
		{
			k++;
			continue;
		}
		else if(rank[i][k]<rank[m][k])
		{
			k=0;
			m++;
			continue;
		}
	}
}
for(i=0;i<n;i++)
{
	int count=0;
	for(k=0;k<10;k++)
	{
		if(rank[i][k]!=-1)
		count++;
	}
	for(k=0;k<10;k++)
	{   
	    m=k+1;
	    if(rank[i][k]!=-1)
		printf("%d",rank[i][k]);
		count--;
		if(rank[i][m]!=-1&&count>0)
		printf(".");
	}
	printf("\n");
	count=0;
}
	
	free(rank);
	free(temp);
	
	return 0;
}
