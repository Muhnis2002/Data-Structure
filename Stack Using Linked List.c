/*
 Muhammed Muhnis T K
 C-Program to Implement Stack Using Linked List
 JEC21CS083
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int dt;
	struct node *ln;
};
struct node *top=NULL,*ptr,*new;
int push(int it);
int pop();
int display();
int main()
{
	int o;
	printf("___Stack Operations___\n1.Push\n2.Pop\n3.Display\n4.Terminate Program");
	op:
	printf("\n\nEnter the Option Number : ");
	scanf("%d",&o);
	if(o==1)
	{
		printf("Enter the Element to be Pushed : ");
		scanf("%d",&o);
		push(o);
		goto op;
	}
	else if(o==2)
	{
		pop();
		goto op;
	}
	else if(o==3)
	{
		display();
		goto op;
	}
	else if(o==4)
		printf("Program Terminated");
	else
	{
		printf("Wrong Input");
		goto op;
	}
	return 0;
}