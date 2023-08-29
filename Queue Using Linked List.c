/*
 Muhammed Muhnis T K
 C-program to Implement Queue Using Linked List
 JEC21CS083
*/

#include<stdio.h>
#include<stdlib.h>

// Define the structure for each node in the linked list
struct node
{
	int dt;              // Data of the node
	struct node *ln;    // Pointer to the next node
};

// Global pointers for the front and rear of the queue
struct node *fr, *re, *new, *tem;

// Function prototypes
int enqueue(int it);    // Function to enqueue an element
int dequeue();          // Function to dequeue an element
int display();          // Function to display the queue
int main();             // Main function

int main()
{
	int o;
	printf("___QUEUE OPERATIONS___");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Terminate Program");
op:
	printf("\nEnter the Option Number  : ");
	scanf("%d", &o);
	if (o == 1)
	{
		printf("Enter the Element to be Enqueued : ");
		scanf("%d", &o);
		enqueue(o);
		goto op;
	}
	else if (o == 2)
	{
		dequeue();
		goto op;
	}
	else if (o == 3)
	{
		display();
		goto op;
	}
	else if (o == 4)
		printf("Program Terminated");
	else
	{
		printf("Wrong Input\n");
		goto op;
	}
	return 0;
}

// Function to enqueue an element
int enqueue(int it)
{
	new = (struct node *)malloc(sizeof(struct node));
	new->dt = it;
	new->ln = NULL;
	if (fr == NULL)
		fr = re = new;
	else
	{
		re->ln = new;
		re = new;
	}
	printf("%d is Enqueued\n", it);
	return 0;
}

// Function to dequeue an element
int dequeue()
{
	if (fr == NULL)
		printf("Queue is Empty\n");
	else if (fr == re)
	{
		tem = fr;
		fr = re = NULL;
		printf("%d is Dequeued\n", tem->dt);
		free(tem);
	}
	else
	{
		tem = fr;
		fr = fr->ln;
		printf("%d is Dequeued\n", tem->dt);
		free(tem);
	}
	return 0;
}

// Function to display the queue
int display()
{
	if ((fr == NULL) && (re == NULL))
		printf("!!Queue is Empty!!\n");
	else
	{
		for (tem = fr; tem->ln != NULL; tem = tem->ln)
			printf("______");
		printf("______\n");
		for (tem = fr; tem->ln != NULL; tem = tem->ln)
			printf("     |");
		printf("     |\n");
		for (tem = fr; tem->ln != NULL; tem = tem->ln)
			printf("  %d  |", tem->dt);
		printf("  %d  |\n", tem->dt);
		for (tem = fr; tem->ln != NULL; tem = tem->ln)
			printf("_____|");
		printf("_____|\n");
	}
	return 0;
}
