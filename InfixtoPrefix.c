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