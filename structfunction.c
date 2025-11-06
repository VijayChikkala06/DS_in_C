#include <stdio.h>


struct student {
    int rno;
    char name[32];
    float avg;
};
void display(struct student s1);
int main() {
    struct student s1;
    
    printf("Enter the student Rno, name, and average: ");
    scanf("%d %s %f", &s1.rno, &s1.name, &s1.avg);
    display(s1);
    return 0;
}

void display(struct student s1) {
    printf("Student Roll No: %d\n", s1.rno);
    printf("Student Name: %s\n", s1.name);
    printf("Student Average: %.2f\n", s1.avg); 
}
