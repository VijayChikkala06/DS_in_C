#include<stdio.h>
struct student
{
	int rno;
	int a,b,c,d;
	float total,avg;
};
int main()
{
	struct student s[100];
	int n,i;
	printf("Enter number of students:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter Roll no and 4 subject marks:\n");
		scanf("%d%d%d%d%d",&s[i].rno,&s[i].a,&s[i].b,&s[i].c,&s[i].d);
		
	}
	printf("\nThe appropriate student details are:\n\n");
	for(i=0;i<n;i++)
	{
		s[i]. total=s[i].a+s[i].b+s[i].c+s[i].d;
		s[i].avg=(float)s[i].total/4;
		printf("student %d tot and avg is:\n",i+1);	
		printf("total=%.2f\naverage=%.2f\n\n",s[i].total,s[i].avg);
		
	}
}

