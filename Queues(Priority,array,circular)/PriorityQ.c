#include<stdio.h>
#include<stdlib.h>
struct pqarray
{
	int element;
	int priority;
};

void enq (struct pqarray*,int,int, int*,int);
int deq(struct pqarray*, int*);
void disp(struct pqarray*, int);
void main()
{
	int rear=-1,choice,x, n,y;
	struct pqarray arr[100];
	printf("Enter size: ");
	scanf("%d",&n);
	printf("1. Enter into priority queue\n");
	printf("2. Delete lowest priority\n");
	printf("3. Exit\n");
	while(1)
	{
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter value to be added: ");
				scanf("%d", &x);
				printf("Enter priority value to be added: ");
				scanf("%d", &y);
				enq(arr,x,y,&rear,n);
				disp(arr,rear);
				break;
			case 2: x=deq(arr, &rear);
				if (x!= -1)
					disp(arr,rear);
				else printf("Nothing to Delete\n");
				break;
			case 3: exit(0);
			default: printf("Invalid input\n");
		}
	}
}

void enq (struct pqarray * arr,int x, int y, int* rear,int n)
{
	int i=0, loc=0;	
	if (*rear== (n-1) )
		printf("Overflow. Queue is full\n");
	else
	{	
		for (i=0; i<=(*rear) ; i++)
			if (arr[i].priority > y)
				break;
		(*rear)++;
		for (int j=((*rear)-1); j>=i ; j--)
			arr[j+1] = arr[j];
		arr[i].element = x;
		arr[i].priority = y;
			
	}
	
}

void disp(struct pqarray * arr, int rear)
{
	if (rear!= -1)
	{	
	printf("FRONT -> ");
	for (int i = 0; i<=rear; i++)
		printf("%d,%d -> ",arr[i].element, arr[i].priority);
	printf("<- REAR\n");
	}
}

int deq (struct pqarray* arr,int* rear)
{
	int x,y;
	if (*rear == -1)
		{
			printf("Underflow. Queue is empty\n");
			return -1;
		}
	else
	{	
			x=arr[0].element;
			y = arr[0].priority;
			printf("Deleted %d which has priority %d\n", x,y);
			for (int i =1; i<= (*rear); i++)
				arr[i-1] = arr[i];
			(*rear) --;
			return 0;
	}
}
