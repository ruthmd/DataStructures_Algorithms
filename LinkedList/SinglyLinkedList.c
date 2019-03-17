#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
};

void insert_front(struct node **, int);
void insert_rear(struct node **, int);
void insert_loc(struct node **, int,int);
void del(struct node **, int);
void del_pos(struct node **, int);
void disp(struct node **);
void reverse(struct node **);

void main()
{
	int choice, x=0, l=0 ,cont;
	struct node *first= NULL;
	
		printf("1. Insert from front\n");
		printf("2. Insert from rear\n");
		printf("3. Insert in given location\n");
		printf("4. Delete using element\n");
		printf("5. Delete using position\n");
		printf("6. Reverse\n");
		printf("7. Exit\n");
		 do
		{
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1: printf("Enter input: ");
					scanf("%d", &x);
					insert_front(&first,x);
					disp(&first);
					break;
			case 2: printf("Enter input: ");
					scanf("%d", &x);
					insert_rear(&first,x);
					disp(&first);
					break;
			case 3: printf("Enter input value: ");
					scanf("%d", &x);
					printf("\nEnter input location: ");
					scanf("%d", &l);
					insert_loc(&first,x,l);
					disp(&first);
					break;
			case 4: printf("Enter input: ");
					scanf("%d", &x);
					del(&first,x);
					disp(&first);
					break;
			case 5: printf("Enter input location: ");
					scanf("%d", &l);
					del_pos(&first,l);
					disp(&first);
					break;
			case 6: reverse(&first);
					disp(&first);
					break;
			case 7: exit(0);
		}
		printf("\nContinue? Press 1: ");
		scanf("%d",&cont);
		
	}while (cont == 1);
}

void disp(struct node **p)
{
	struct node *temp;
	temp = *p;
	while (temp != NULL)
	{
		printf("%d -> ", temp-> data);
		temp = temp -> next;
	}
}

void insert_front( struct node **p, int x)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> next = NULL;
	if (*p == NULL)
		{
			*p = temp;
		}
	else 
	{
		temp -> next = *p;
		*p = temp;
	}
}

void insert_rear (struct node **p, int x)
{
	struct node *temp, *temp2;
	temp = (struct node*)malloc(sizeof(struct node));
	temp2 = *p;
	temp -> data = x;
	temp -> next = NULL;
	if (*p == NULL)
		{
			*p = temp;
		}
	else 
	{
		while( temp2-> next != NULL )
			temp2 = temp2-> next;
			temp2 -> next = temp;
	}
}

void insert_loc( struct node **p, int x, int k)
{
	
	struct node *temp,*q1 ,*q2;
	q1= *p;
	q2 = NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(*p==NULL)
		*p=temp;
	else if(k==1)
	{
		temp->next=*p;
		*p=temp;
	}
	else
	{
		int count=1;
		while(count<k)
		{
			q2=q1;
			q1 = q1 -> next;
			count++;
		}
		q2->next=temp;
		temp->next=q1;
	}
}

void del( struct node **p, int x)
{
	struct node *q, *prev;
	q = *p;
	prev = NULL;
	while ((q -> next != NULL) && (q-> data != x))
		{
			prev = q;
			q = q-> next;
		}
	if (prev == NULL)
		*p = q-> next;
	else
		prev -> next = q-> next;
	free(q);
}

void del_pos( struct node **p, int l)
{
	struct node *q, *prev;
	int i;
	q = *p;
	prev = NULL;
	for ( i=1;((q!= NULL) && (i<l));i++)
		{
			prev = q;
			q = q-> next;
		}
	if (prev == NULL)
		*p = q-> next;
	else if (q!= NULL)
		prev -> next = q-> next;
	else printf("\nINVALID LOCATION");
	free(q);
}

void reverse(struct node **p)
{
	struct node *q, *prev, *temp;
	prev = NULL;
    q = *p;
	while(q!= NULL)
	{
		temp = q-> next;
		q-> next = prev;
		prev = q;
		q = temp;
	}
	*p = prev;
}
