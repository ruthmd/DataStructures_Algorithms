#include<stdio.h>
void push(char *, char, int *);
char pop( char *, int *);
int check(char *);
void main()
{
	char expr[100];
	int res;
	printf("Enter expression to check: ");
	scanf("%s", expr);
	res = check(expr);
	if (res == 0)
		printf("NOT CORRECT\n");
	else
		printf("CORRECT\n");
}

int check(char * ex)
{
	int i=0, top = -1,x;
	char s[10],t;
	while (ex[i] != '\0')
	{
		t=ex[i];
		if (t == '(' || t == '{' || t == '[' )
			push(s,t, &top);
		else if (t==')')
		{
			x = pop(s,&top);
			if (x!= '(')
				return 0;
		} 
		else if (t==']')
		{
			x = pop(s,&top);
			if (x!= '[')
				return 0;
		} 
		else if (t=='}')
		{
			x = pop(s,&top);
			if (x!= '{')
				return 0;
		}
		i++; 
	}
	if (top != -1)
		return 0;
	else return 1;
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

