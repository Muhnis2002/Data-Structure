/*
 Muhammed Muhnis T K
 C-Program to Evaluvate the Postifix Expression
 JEC21CS083
*/
#include<stdio.h> 
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct exp
{
	char ch[8];
}po[30];
char str[10],ch[50];
int top=-1,s[15],i,k,l=0,m;
int eval_po();
int read();
int display();
int main()
{
	read();
	printf("\nThe Entered Postfix Expression is : ");
	display();
	printf("\n");
	eval_po();
	return 0;
}
int eval_po()
{
	int p=0,op1,op2,res;
	while(p<=k)
	{
		if(isdigit(po[p].ch[0]))
		{
			s[++top]=atoi(po[p].ch);	
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			switch(po[p].ch[0])
			{
				case '+':
				{
					res=op1+op2;
					break;
				}
				case '-':
				{
					res=op1-op2;
					break;
				}
				case '*':
				{
					res=(op1)*(op2);
					break;
				}
				case '/':
				{
					res=op1/op2;
					break;
				}
				case '^':
				{
					res=pow(op1,op2);
					break;
				}
			}
			s[++top]=res;
		}
		++p;
	}
	printf("\nThe Result of Expression is : %d",s[0]);
	return 0;
}	