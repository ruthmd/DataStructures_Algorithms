#include<stdio.h>
void conv(char *, char*);
int stack_prec(char);
int inp_prec(char);
void push(char *, char, int *);
char pop( char *, int *);
char peep(char *, int);
void main()
{
	char post[100], inf[100];
	printf("Enter Expression to convert: ");
	scanf("%s", inf);
	conv(inf, post);
	printf("Answer is: %s\n", post);
}
void conv(char * inf, char* post)
{
	char s[10], scanned, ch;
	int top = -1;
	int i=0;
	int j=0;
	push(s,'#',&top);
	while(inf[i]!= '\0')
	{
		scanned = inf[i];
		while(stack_prec(peep(s,top)) > inp_prec(scanned))
			post[j++] =pop(s, &top);
		if (stack_prec(peep(s,top))!= inp_prec(scanned))
			push(s,scanned, &top);
		else
			pop(s, &top);
		i++;
	}
	while (peep(s,top)!= '#')
		post[j++] = pop(s,&top);
	post[j] = '\0';
}

int stack_prec(char ch)
{
	switch (ch)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^': return 5;
		case '#': return -1;
		case '(': return 0;
		default: return 8;
	}
}

int inp_prec(char ch)
{
	switch (ch)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^': return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7;
	}
}

void push( char*s, char x, int *t)
{
	++*t;
	s[*t] = x;
}

char pop( char*s, int *t)
{
	char x;
	x = s[*t];
	--*t;
	return x;
}

char peep(char *s, int t)
{
	return s[t];
}

