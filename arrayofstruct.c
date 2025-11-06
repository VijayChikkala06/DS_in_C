#include<stdio.h>
#include<string.h>
struct student{
	int rno;
	char name[30];
	float avg;
};
int main(){
	struct student s1[100];
	int n,i;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the roll no name and average of %d student: \n",i+1);
		scanf("%d%s%f",&s1[i].rno,&s1[i].name,&s1[i].avg);
	}
	for(i=0;i<n;i++){
		printf("%d\t%s\t%f\n",s1[i].rno,s1[i].name,s1[i].avg);
	}
	
}