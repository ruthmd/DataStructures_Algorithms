#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * prev;
	struct node * next;
};

void insert_front(struct node **, int);
void insert_rear(struct node **, int);
void insert_loc(struct node **, int,int);
void del(struct node **, int);
void del_pos(struct node **, int);
void disp(struct node **);

void main()
{
	int choice, x=0, l=0 ,cont;
	struct node *first= NULL;
	
		printf("1. Insert from front\n");
		printf("2. Insert from rear\n");
		printf("3. Insert in given location\n");
		printf("4. Delete using element\n");
		printf("5. Delete using position\n");
		printf("6. Exit\n");
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
					printf("Enter input location: ");
					scanf("%d", &l);
					insert_loc(&first,x,l);
					disp(&first);
					break;
			case 4: printf("Enter input: ");
					scanf("%d", &x);
					del(&first,x);
					disp(&first);
					break;
			case 5: printf("Enter deletion location: ");
					scanf("%d", &l);
					del_pos(&first,l);
					disp(&first);
					break;
			case 6: exit(0);
		}
		printf("\nContinue? Press 1: ");
		scanf("%d",&cont);
		
	}while (cont == 1);
}


void disp(struct node **p)
{
	struct node *temp;
	temp = *p;
	if (*p == NULL) 
		printf("EMPTY\n");
	else
	{
		while (temp!= NULL)
		{
			printf("%d <-> ", temp-> data);
			temp = temp -> next;
		}
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
		(*p)-> prev = temp;
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
			temp -> prev = temp2;
	}
}


void del( struct node **p, int x)
{
	struct node *q;
	q = *p;
	while ((q != NULL) && (q-> data != x))
		q = q-> next;
	
	if(q!= NULL)
	{
		if((q->prev == NULL) && (q-> next == NULL))
			*p = NULL;
		
		else if(q-> prev == NULL)
		{
			(*p) -> prev = NULL;
			*p = q-> next;
		}
		
		else if (q-> next == NULL)
			q-> prev-> next = NULL;
			
		else
		{
			q-> prev -> next = q-> next;
			q-> next -> prev = q-> prev;
		}
		
		free(q);
	}
	
	else
		printf("Element not found\n");
}

void del_pos (struct node **p, int loc)
{
	struct node *q;
	int i;
	q = *p;
	if(( loc == 1) && (q-> next == NULL))
		*p = NULL;
	else if (loc == 1)
		{
			*p = q-> next;
			(*p) -> prev = NULL;
		}
	else
	{
		for ( i=1;((q!= NULL) && (i<loc));i++)
			q = q-> next;
		if (i == loc)
		{
			if (q-> next == NULL)
				q-> prev -> next = NULL;
			else
			{
				q-> prev -> next = q-> next;
				q-> next -> prev = q-> prev;
			}
		}
		else printf("Invalid location\n");
	}
	free(q);
}

void insert_loc(struct node **p,int x, int loc)
{
	struct node *q;
	q = *p;
	if (loc == 1)
	{
		insert_front(p,x);
	}
	
	else
	{
		struct node * temp;
		int i;
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = x;
		temp -> next = NULL;
		temp-> prev = NULL;
		for(i=1; (q-> next != NULL) && (i<loc); i++)
			q = q-> next;
		if (i== loc)
		{
			q-> prev -> next = temp;
			temp->prev = q-> prev;
			temp-> next = q;
			q-> prev = temp;
		}
		
		else if (i == loc-1)
		{
			q-> next = temp;
			temp-> prev = q;
		}
		
		else printf("Invalid Position\n");
	}
}
