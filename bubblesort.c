#include <stdio.h>
int main (){
   int num[20];
   int i, j, a, n,k;
   printf("enter number of elements in an array :\n");
   scanf("%d", &n);
   printf("Enter the elements :\n");
   for (i = 0; i < n; ++i)
      scanf("%d", &num[i]);
      
   for (i = 0; i < n; ++i){
      for (j = i + 1; j < n; ++j){
         if (num[i] > num[j]){
            a = num[i];
            num[i] = num[j];
            num[j] = a;
         
      }
      for (k = 0; k < n; ++k){
      printf("%d ", num[i]);
   }
   printf("\n");
}
   }
   
}