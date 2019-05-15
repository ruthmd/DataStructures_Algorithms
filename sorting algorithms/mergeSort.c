#include<stdio.h>
#include<stdlib.h>


int merge(int *a,int l,int mid,int r){

	int *b= (int*)malloc(sizeof(int)*(r+1));
	int i=l, j=mid+1, k=0;
	
	//2 way merge
	while(i<=mid && j<=r){
		if(a[i]>a[j])
			b[k++]=a[j++];
		else
			b[k++]=a[i++];
	}
	// copy the remaining elements
	while(i<=mid)
		b[k++]=a[i++];

	while(j<=r)
		b[k++]=a[j++];

	// copying back the sorted list to a[]
	for(i=r; i >= l; i--)
    		a[i] = b[--k];        
}
	
int mergesort(int *a,int l,int r){
	if(l<r){
		int mid= l+(r-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);	
		merge(a,l,mid,r);
	}
}

int display(int *a,int n){
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

int main(){
	
	int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]); 
	mergesort(a,0,n-1);
	display(a,n);
	return 0;
}
