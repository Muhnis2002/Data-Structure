/*
 Muhammed Muhnis T K
 C-program to Implement Queue Using Linked List
 JEC21CS083
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int dt;
	struct node *ln;
};
struct node *fr,*re,*new,*tem;
int enqueue(int it);
int dequeue();
int display();
int main()
{
	int o;
	printf("___QUEUE OPERATIONS___");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Terminate Program");
	op:
	printf("\nEnter the Option Number  : ");
	scanf("%d",&o);
	if(o==1)
	{
		printf("Enter the Element to be Enqueued : ");
		scanf("%d",&o);
		enqueue(o);
		goto op;
	}
	else if(o==2)
	{
		dequeue();
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
		printf("Wrong Input\n");
		goto op;
	}
	return 0;
}
int enqueue(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->dt=it;
	new->ln=NULL;
	if(fr==NULL)
		fr=re=new;
	else
	{
		re->ln=new;
		re=new;
	}
	printf("%d is Enqueued\n",it);
	return 0;
}