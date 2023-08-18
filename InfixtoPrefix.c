/*
 Muhammed Muhnis T K
 C-Program to Convert Infix to Postifix Expression
 JEC21CS083
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char in[30],s[15],p[30];
int top=-1;
int precedence(char c);
void in_to_pr();
int main()
{
	
	printf("Enter the Infix Expression :");
	gets(in);
	in_to_pr();
	return 0;
}
int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-': return 1;						
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
	return 0;
}
void in_to_pr()
{
	int i=strlen(in),j=0;
	char x,y;
	while(i>=0)
	{
		if((isalpha(in[i]))||(isdigit(in[i])))
			p[j++]=in[i];
		else if(in[i]==')')
		    s[++top]=in[i];
		else if(in[i]=='(')
		{
			while(s[top]!=')')
			{
				p[j++]=s[top--];
			}
			top--;
		}
		else
		{ 
			x=in[i],y=s[top];
		    if((y==')')||(top==-1)||(precedence(y)<=precedence(x)))
		    {
				s[++top]=x;
			}
			else
			{
				while((top!=-1)&&(y!=')')&&(precedence(x)<precedence(y)))
			    {
				    p[j++]=s[top--];
				    y=s[top];
			    }
			    s[++top]=x;
			}
		}
		--i;
	}
	while(top!=-1)
	{
		p[j++]=s[top--];
	}
	p[j]='\0';
	strrev(p);
	printf("The Prefix Expression is : %s ",p);
}