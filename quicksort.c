 #include<stdio.h>
void QuickSort(int a[],int left,int right)
{
	int i,j,t,pivot;
	if(left<right){
		i=left;
		pivot=left;
		j=right;
		while(i<j){
			while(a[i]<=a[pivot])
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			else{
				t=a[j];
		a[j]=a[pivot];
		a[pivot]=t;
			}
		}
		QuickSort(a,left,j-1);
		QuickSort(a,j+1,right);
	}
}
int main(){
	int arr[25],i,j,n;
	printf("Enter n value :");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
		QuickSort(arr,0,n-1);
		printf("Sorted array is:\n");
		for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
		
	}
}