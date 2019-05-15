#include<stdio.h>

int binarySearchIter(int a[], int key, int len){
    int l = 0;
    int h = len-1;

    while(l<h)
    {
        int mid = l+ (h-l)/2;

        if(a[mid]==key)
            return mid;
        
        if(a[mid]>key)
            h = mid-1; //reduce the search space to a[0...(mid-1)]

        else // check for a[mid] < key
            l = mid+1; //reduce the search space to a[(mid+1)...h]
    }
    return -1;
}

int binarySearchRec(int a[], int l, int h, int key){
    if(l<h){
        int mid = l+ (h-l)/2;

        if(a[mid]==key)
            return mid;
        
        if(a[mid]>key)
            return binarySearchRec(a, 0, mid-1, key);//reduce the search space to a[0...(mid-1)]
        return binarySearchRec(a, mid+1, h, key);//reduce the search space to a[(mid+1)...h]
    }
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10;

    printf("Iterative: %d found at index %d\n", x, binarySearchIter(arr, x, n));

    printf("Recursive: %d found at index %d\n", x, binarySearchRec(arr, 0, n-1, x));
    return 0;
}
