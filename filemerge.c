#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp1,*fp2,*fp3;
	char ch;
	fp1=fopen("file1.txt","r");
	if(fp1==NULL){
		printf("File not created");
		exit(0);
	}
		fp2=fopen("file2.txt","r");
	if(fp2==NULL){
		printf("File not created");
		exit(0);
	}
		fp3=fopen("file3.txt","r");
	if(fp3==NULL){
		printf("File not created");
		exit(0);
	}
	while(!feof(fp1)){
		ch=fgetc(fp1);
		fputc(ch,fp3);
	}
	while(!feof(fp2)){
		ch=fgetc(fp2);
		fputc(ch,fp3);
	}
	printf("File is merged");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
