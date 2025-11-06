#include<stdio.h>
#include<string.h>
struct student{
	char name[30];
struct date{
	int dd;
	int mm;
	int yy;
}dob;
	float avg;
};

int main(){
	struct student s2;
	printf("Memory created is : %d",sizeof(s2));
	strcpy(s2.name, "Varun");
	s2.dob.dd=22;
	s2.dob.mm=8;
	s2.dob.yy=2025;
	s2.avg=99.99;
	printf("\n%s\t%d/%d/%d\t%.2f",s2.name,s2.dob.dd,s2.dob.mm,s2.dob.yy,s2.avg);
}
