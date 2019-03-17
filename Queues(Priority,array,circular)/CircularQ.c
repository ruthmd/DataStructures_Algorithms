#include<stdio.h>
#include<stdlib.h>	
void enq (int*,int, int*,int*,int);
int deq(int*, int*,int*,int);
void disp(int*,int,int,int);
void main()
{
	int arr[100], front=-1, rear=-1,choice,x, n;
	printf("Enter size: ");
	scanf("%d",&n);
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Exit\n");
	while(1)
	{
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to be added: ");
				scanf("%d", &x);
				enq(arr,x,&rear, &front,n);
				disp(arr,front,rear,n);
				break;
			case 2: x=deq(arr,&front, &rear,n);
				if (x!= -1)
				{
					disp(arr,front,rear,n);
					printf("Element deleted is %d\n",x);
				}
				else printf("Nothing to Delete\n");
				break;
			case 3: exit(0);
		}
	}
}

void enq (int* arr,int x, int* rear, int *front,int n)
{
	if ((*rear== (n-1) && (*front) == 0) || ((*front) == (*rear) +1 ))
		printf("Overflow. Queue is full\n");
	else
	{	
		if (*front == -1 && *rear == -1)
			*front= *rear= 0;
		else if (*rear == n-1)
			*rear = 0;
		else
			(*rear)++;
		arr[*rear] = x;
	}
}

int deq (int* arr, int* front,int* rear,int n)
{
	int x;
	if (*front == -1)
		{
			printf("Underflow. Queue is empty\n");
			return -1;
		}
	else
	{	if (*front == *rear)
			{
				x=arr[*front];
				*front = *rear = -1;
				return x;
			}
		else
		{
			x=arr[*front];
			if (*front == n-1)
				*front= 0;
			else
				(*front)++;
			return x;
		}
	}
}


void disp(int* arr, int front, int rear,int n)
{
	if (front !=-1 && rear!= -1)
	{
	printf("FRONT -> ");
	if (front<= rear)	
		for (int i = front; i<=rear; i++)
			printf("%d -> ",arr[i]);
	else 
		{
		for (int i = front; i<= n-1; i++)
			printf("%d -> ",arr[i]);
		for (int i = 0; i<=rear; i++)
			printf("%d -> ",arr[i]);	
	
		}
	printf("<- REAR\n");
	}
}
		
