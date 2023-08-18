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