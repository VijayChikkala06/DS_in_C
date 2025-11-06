#include<stdio.h>
#include<string.h>
struct date
{
	int dd;
	int mm;
	int yy;
};
struct student
{
	int rno;
	char name[30];
	struct date dob;
	float avg;
};
int main()
{
	struct student s;
	scanf("%s",s.name);
	s.dob.dd=22;
	s.dob.mm=8;
	s.dob.yy=2007;
	printf("%s\t%d/0%d/%d",s.name,s.dob.dd,s.dob.mm,s.dob.yy);
return 0;	
}