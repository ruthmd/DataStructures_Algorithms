#include<stdio.h>
int eval(char*);
void push(int *, int, int *);
int pop( int *, int *);
int operator(char);
void main()
{
	char post[100];
	int res;
	printf("Enter postfix expression to evaluate: ");
	scanf("%s", post);
	res = eval(post);
	printf("Answer is: %d\n", res);
}

int eval(char * post)
{
	int op1,op2,ans,s[10],i=0, top=-1;
	char ch;
	while(post[i]!= '\0')
	{
		ch = post[i];
		if(operator(ch))
		{
			op1=pop(s,&top);
			op2=pop(s,&top);
			switch(ch)
			{
				case '+': ans = op1+op2;
					  break;
				
				case '-': ans = op1-op2;
					  break;
				
				case '*': ans = op1*op2;
					  break;
				
				case '/': ans = op1/op2;
					  break;
			}
			push(s,ans,&top);	
		}
		else
			push(s,ch-'0',&top);
		i++;
	}
	ans = pop(s,&top);
	return ans;
}

int operator(char ch)
{
	if (ch== '+' || ch== '-' || ch== '*' || ch== '/' )
		return 1;
	return 0;
}

void push( int*s, int x, int *t)
{
	++*t;
	s[*t] = x;
}

int pop( int*s, int *t)
{
	char x;
	x = s[*t];
	--*t;
	return x;
}


