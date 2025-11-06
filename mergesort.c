#include <stdio.h>
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left +right)/ 2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1]; 
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    // Copy merged elements back to original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}
// Main function
int main() {
    int a[25],i,n; 
    printf("enter n value :");
    scanf("%d",&n);
    printf("enter %d elements:\n",n);
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    mergeSort(a, 0, n - 1);
    printf("Sorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
    return 0;
}