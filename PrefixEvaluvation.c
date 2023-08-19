/*
 Muhammed Muhnis T K
 C-Program to Evaluvate a Prefix Expression
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
int eval_pr();
int display();
int read();
int main()
{
	read();
	printf("\nThe Entered Prefix Expression is : ");
	display();
	printf("\n");
	eval_pr();
	return 0;
}
int read()
{
	printf("Enter the Prefix Expression Separating Each Token by Single Space : ");
	gets(ch);
	i=strlen(ch);
	for(;i>=0;++k)
	{
		if(isdigit(ch[i]))
		{
			for(m=0;ch[i]!=' ';--i,++m)
			{
				po[k].ch[m]=ch[i];
			}			
			l=0;
		}
		else if(ch[i]=='*'||ch[i]=='+'||ch[i]=='-'||ch[i]=='/'||ch[i]=='^')
		{
			po[k].ch[0]=ch[i];
			l=0;
			--i;			
		}
		else 
		{
			++l;
			--i;
			--k;
		}
	}
	return 0;
}	
int display()
{
	for(int j=k-1;j>=0;--j)
	{
		printf(" %s",po[j].ch);
	}
	return 0;
}	