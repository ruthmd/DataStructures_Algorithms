#include<stdio.h>
#include<stdlib.h>

struct arraystack{
	int top;
	int * a;
	int size;
};

void push(struct arraystack *, int);
int pop(struct arraystack * );
void disp(struct arraystack);
int peep(struct arraystack *);

void main(){
	int choice, x ,cont;
	struct arraystack stack;
	
	printf("Enter number of elements: ");
	scanf("%d", &(stack.size));
	
	stack.a = (int*)malloc(sizeof(int)*(stack.size));
	stack.top =0;
	
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peep\n");
		printf("4. Exit\n");
		while (1){
			printf("Enter choice: ");
			scanf("%d", &choice);
			
			switch (choice){
				case 1: printf("Enter a number:");
						scanf("%d", &x);
						push(&stack,x);
						disp(stack);
						break;

				case 2: x = pop(&stack);
						if (x != -1) {
							printf("The element deleted is %d\n", x);
							disp(stack);
						}
						else printf("Nothing to delete\n");
						break;

				case 3: x = peep(&stack);
						if (x != -1)	
							printf("The top element is %d\n" ,x);
						else	
							printf("No element\n");
						break;

				case 4: exit(0);

				default:printf("Invalid Input");
			}
		}
}

void push( struct arraystack * p, int x){
	if(p->top == (p->size))
		printf("\nStack is full!\n");
	else{
		p->a[(p->top)] = x;
		(p->top)++;
	}
}


int pop( struct arraystack * p){
	if(p-> top ==0){
			printf("\nStack is Empty\n");
			return -1;
		}
	else{
		int x;
		x = p->a[((p->top)-1)];
		(p->top)--;
		return x;	
	}
}

int peep( struct arraystack * p){	
	if(p-> top ==0){
		printf("\nStack is Empty\n");
		return -1;
	}
	else{
		int x;
		x = p->a[(p->top)-1];
		return x;	
	}
}

void disp(struct arraystack p){
	if(p.top ==0)
		printf("\nStack is Empty\n");
	else{
		int i;
		printf("\tTOP\n");
		for(i = ((p.top)-1); i>=0; i--)
			printf("%d\n", p.a[i]);
		printf("\tBOTTOM\n");
	}
}
