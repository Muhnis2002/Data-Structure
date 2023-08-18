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