#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
		int rno;
		char name[5];
		double avg;
	}s1;
	
	union employee{
		int empid;
		char empname[12];
		double y;
	}e1;
	
int main(){
	int i;
	struct student *s2 = (struct student*)malloc(sizeof(struct student));
	scanf("%d",s2->rno);
	printf("%d\n",s2->rno);
	
	
	printf("Memory created in structure is:");
	printf("%d",sizeof(s1));
	printf("\nMemory created in union is:");
	printf("%d",sizeof(e1));
	
	e1.empid=1234;
	printf("\n%d",e1.empid);	 
	strcpy(e1.empname,"varun");
	printf("\t%s",e1.empname);	 
	e1.y=97.998;
	printf("\t%lf\n",e1.y);  
	strcpy(s1.name,"varunkumarpolumuri");
	printf("\n%s",s1.name);		 
	return 0;
}