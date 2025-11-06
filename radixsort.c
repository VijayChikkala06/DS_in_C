#include<stdio.h>
void radix(int a[],int n)
{
	int big,i,d=0,b[10][n],t[10],div=1,pos,j,k,s;
	big=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>big)
		{
			big=a[i];
		}
	}
	while(big>0)
	{
		d++;
		big=big/10;
	}
	
	for(s=0;s<d;s++)
	{
		for(i=0;i<10;i++)
		{
			t[i]=0;
		}
		for(i=0;i<n;i++)
		{
			pos=(a[i]/div)%10;
			b[pos][t[pos]++]=a[i];
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<t[i];j++)
			{
				a[k]=b[i][j];
				k++;
			}
		}
		div=div*10;
	}
}
int main()
{
	int a[20],n,i,j; 
	printf("enter the array size: ");
	scanf("%d",&n);
	printf("enter the values: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radix(a,n);
	printf("sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}