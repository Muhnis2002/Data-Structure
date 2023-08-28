/*
 Muhammed Muhnis T K
 C-Program to Implement Stack Using Linked List
 JEC21CS083
*/

#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct node
{
	int dt;              // Data of the node
	struct node *ln;    // Pointer to the next node in the stack
};

// Initialize the top of the stack as NULL
struct node *top=NULL, *ptr, *new;

// Function prototypes for stack operations
int push(int it);       // Pushes an element onto the stack
int pop();              // Pops an element from the stack
int display();          // Displays the elements in the stack

int main()
{
	int o;

	printf("___Stack Operations___\n1.Push\n2.Pop\n3.Display\n4.Terminate Program");
	op:
	printf("\n\nEnter the Option Number : ");
	scanf("%d",&o);

	// Perform stack operation based on user's choice
	if(o==1)
	{
		printf("Enter the Element to be Pushed : ");
		scanf("%d",&o);
		push(o);
		goto op;  // Go back to the main menu
	}
	else if(o==2)
	{
		pop();
		goto op;  // Go back to the main menu
	}
	else if(o==3)
	{
		display();
		goto op;  // Go back to the main menu
	}
	else if(o==4)
		printf("Program Terminated");
	else
	{
		printf("Wrong Input");
		goto op;  // Go back to the main menu
	}
	return 0;
}

// Function to push an element onto the stack
int push(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->dt=it;
	new->ln=top;
	top=new;
	printf("%d is Pushed to the Stack Top",it);
	return 0;	
}

// Function to pop an element from the stack
int pop()
{
	if(top==NULL)
		printf("Stack is Empty");
	else
	{
		ptr=top;
		printf("%d is Popped from Stack",top->dt);
		top=top->ln;
		free(ptr);  // Free the memory of the popped node
	}
	return 0;
}

// Function to display elements in the stack
int display()
{
	if(top==NULL)
		printf("Stack is Empty");
	else
	{
	    printf("The Elements in the Stack are :\n");
	    ptr=top;
	    for(;ptr->ln!=NULL;ptr=ptr->ln)
		    printf("          |  %d  |\n          |_____|\n",ptr->dt);
	    printf("          |  %d  |\n          |_____|",ptr->dt);
    }
	return 0;
}

/*
OUTPUT:
___Stack Operations___
1.Push
2.Pop
3.Display
4.Terminate Program

Enter the Option Number : 1
Enter the Element to be Pushed : 3
3 is Pushed to the Stack Top

Enter the Option Number : 1
Enter the Element to be Pushed : 5
5 is Pushed to the Stack Top

Enter the Option Number : 1
Enter the Element to be Pushed : 8
8 is Pushed to the Stack Top

Enter the Option Number : 1
Enter the Element to be Pushed : 1
1 is Pushed to the Stack Top

Enter the Option Number : 3
The Elements in the Stack are :
          |  1  |
          |_____|
          |  8  |
          |_____|
          |  5  |
          |_____|
          |  3  |
          |_____|

Enter the Option Number : 2
1 is Poped from Stack

Enter the Option Number : 3
The Elements in the Stack are :
          |  8  |
          |_____|
          |  5  |
          |_____|
          |  3  |
          |_____|

Enter the Option Number : 2
8 is Poped from Stack

Enter the Option Number : 3
The Elements in the Stack are :
          |  5  |
          |_____|
          |  3  |
          |_____|

Enter the Option Number : 1
Enter the Element to be Pushed : 7
7 is Pushed to the Stack Top

Enter the Option Number : 3
The Elements in the Stack are :
          |  7  |
          |_____|
          |  5  |
          |_____|
          |  3  |
          |_____|

Enter the Option Number : 1
Enter the Element to be Pushed : 9
9 is Pushed to the Stack Top

Enter the Option Number : 3
The Elements in the Stack are :
          |  9  |
          |_____|
          |  7  |
          |_____|
          |  5  |
          |_____|
          |  3  |
          |_____|

Enter the Option Number : 4
Program Terminated

------------------
*/
