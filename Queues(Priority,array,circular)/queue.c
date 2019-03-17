#include<stdio.h>
#include<stdlib.h>	
int front1(int*,int);
void enq (int*,int, int*,int*,int);
int deq(int*, int*,int*);
void disp(int*,int,int);
void main()
{
	int arr[100], front=-1, rear=-1,choice,x, n;
	printf("Enter size: ");
	scanf("%d",&n);
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Front\n");
	printf("4. Exit\n");
	while(1)
	{
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to be added: ");
				scanf("%d", &x);
				enq(arr,x,&rear, &front,n);
				disp(arr,front,rear);
				break;
			case 2: x=deq(arr,&front, &rear);
				if (x!= -1)
				{
					disp(arr,front,rear);
					printf("Element deleted is %d\n",x);
				}
				else printf("Nothing to Delete\n");
				break;
			case 3: x=front1(arr,front);
				if (x!= -1)
				{
					printf("Element in front is %d\n",x);
				}
				else printf("Nothing to Show\n");
				break;
			case 4: exit(0);
		}
	}
}

void enq (int* arr,int x, int* rear, int *front,int n)
{
	if (*rear== n-1)
		printf("Overflow. Queue is full\n");
	else
	{	
		if (*front == -1)
			*front= 0;
		(*rear)++;
		arr[*rear] = x;
	}
}

int deq (int* arr, int* front,int* rear)
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
			(*front)++;
			return x;
		}
	}
}

int front1(int* arr, int front)
{
	int x;
	if (front == -1)
		{
			printf("Underflow. Queue is empty\n");
			return -1;
		}
	else
	{
		x=arr[front];
		return x;
		
	}
}

void disp(int* arr, int front, int rear)
{
	if (front !=-1 && rear!= -1)
	{	
	printf("FRONT -> ");
	for (int i = front; i<=rear; i++)
		printf("%d -> ",arr[i]);
	printf("<- REAR\n");
	}
}
		
