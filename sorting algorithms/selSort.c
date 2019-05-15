#include<stdio.h>


void selectionSort(int a[], int n){

    //reduce the sorting space by 1 element
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[min])
                min = j;
        //swap
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
            
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]); 
    selectionSort(a, n); 
    printf("Sorted array: \n"); 
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}
