/*
 Muhammed Muhnis T K
 C-Program to Convert an Infix Expression to Postix Expression
 JEC21CS083
*/
#include<stdio.h>
#include<ctype.h>
char in[30],s[15],p[30];
int top=-1;
int precedence(char c);
void in_to_po();
int main()
{
	
	printf("Enter the Infix Expression :");
	gets(in);
	in_to_po();
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
void in_to_po()
{
	int i=0, j=0;
	char x,y;
	while(in[i]!='\0')
	{
		if((isalpha(in[i]))||(isdigit(in[i])))            
			p[j++]=in[i];
		else if(in[i]=='(')
		    s[++top]=in[i];
		else if(in[i]==')')
		{
			while(s[top]!='(')
			{
				p[j++]=s[top--];
			}
			top--;
		}
		else
		{
			x=in[i],y=s[top];
		    if((y=='(')||(top==-1)||(precedence(x)>precedence(y)))
		    {
				s[++top]=x;
			}
			else
			{
				while((top!=-1)&&(y!='(')&&(precedence(x)<=precedence(y)))
			    {
				    p[j++]=s[top--];
				    y=s[top];
			    }
			    s[++top]=x;
			}
		}
		++i;
	}
	while(top!=-1)
	{
		p[j++]=s[top--];
	}
	p[j]='\0';
	printf("The Postifix Expression is %s ",p);
}