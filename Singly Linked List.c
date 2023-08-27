/*Muhammed Muhnis T K
 C-Program to Implement Singly Linked List
 JEC21CS083*/
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct node
{
	int dt;             // Data of the node
	struct node *ln;   // Pointer to the next node
};

// Declare global pointers for head, current node, new node, and temporary node
struct node *head, *ptr, *new, *temp;

// Function prototypes for various operations
int display();
int insert_fr(int it);
int insert_end(int o);
int insert_key(int k, int o);
int delete_fr();
int delete_end();
int delete_key(int o);
int search(int o);

int main()
{
	// Display the menu for various operations
	printf("\n\n____SINGLY LINKED LIST OPERATIONS____\n");
	printf("1.Insert at Front\n");
	printf("2.Insert at End\n");
	printf("3.Insert after a Specified Node\n");
	printf("4.Delete from Front\n");
	printf("5.Delete From End\n");
	printf("6.Delete a Specified Node\n");
	printf("7.Search for an Element in the List\n");
	printf("8.Display\n");
    printf("9.Terminate Program\n");
	int o, k;
op:
	printf("\n\nEnter the Option Number : ");
	scanf("%d", &o);

	// Perform the selected operation based on user input
	if (o == 1)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d", &o);
		insert_fr(o);
		printf("%d is Inserted at Front", o);
		goto op;
	}
	else if (o == 2)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d", &o);
		insert_end(o);
		printf("%d is Inserted at End", o);
		goto op;
	}
	else if (o == 3)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d", &o);
		printf("Enter the Key after the Element is to be Inserted : ");
		scanf("%d", &k);
		insert_key(k, o);
		goto op;
	}
	else if (o == 4)
	{
		delete_fr();
		goto op;
	}
	else if (o == 5)
	{
		delete_end();
		goto op;
	}
	else if (o == 6)
	{
		printf("Enter Element to be Deleted : ");
		scanf("%d", &o);
		delete_key(o);
		goto op;
	}
	else if (o == 7)
	{
		printf("Enter the Element to be Searched : ");
		scanf("%d", &o);
		search(o);
		goto op;
	}
	else if (o == 8)
	{
		display();
		goto op;
	}
	else if (o == 9)
	{
		printf("Program Terminated");
	}
	else
	{
		printf("!!Wrong Input!!");
		goto op;
	}
	return 0;
}

// Function to insert a node at the front of the linked list
int insert_fr(int it)
{
	new = (struct node *)malloc(sizeof(struct node));
	new->ln = head;
	new->dt = it;
	head = new;
	return 0;
}

// Function to insert a node at the end of the linked list
int insert_end(int it)
{
	new = (struct node *)malloc(sizeof(struct node));
	new->dt = it;
	new->ln = NULL;
	if (head == NULL)
	{
		head = new;
	}
	else
	{
		ptr = head;
		while (ptr->ln != NULL)
		{
			ptr = ptr->ln;
		}
	}
	ptr->ln = new;
	return 0;
}

// Function to insert a node after a specified key node in the linked list
int insert_key(int k, int x)
{
	if (head == NULL)
	{
		printf("Search Failed, Insertion is not possible ");
	}
	else
	{
		ptr = head;
		while ((ptr->dt != k) && (ptr->ln != NULL))
		{
			ptr = ptr->ln;
		}
		if (ptr->dt != k)
		{
			printf("Search Failed, Insertion is not possible ");
		}
		else
		{
			new = (struct node *)malloc(sizeof(struct node));
			new->dt = x;
			new->ln = ptr->ln;
			ptr->ln = new;
			printf("%d is Inserted after %d ", x, k);
		}
	}
	return 0;
}

// Function to delete a node from the front of the linked list
int delete_fr()
{
	if (head == NULL)
	{
		printf("List is Empty");
	}
	else
	{
		temp = head;
		head = head->ln;
		printf("%d is Deleted", temp->dt);
		free(temp);
	}
	return 0;
}

// Function to delete a node from the end of the linked list
int delete_end()
{
	struct node *prev;
	struct node *curr;
	if (head == NULL)
	{
		printf("List is Empty");
	}
	else if (head->ln == NULL)
	{
		temp = head;
		head = NULL;
		printf("%d is Deleted", temp->dt);
		free(temp);
	}
	else
	{
		prev = head;
		curr = head->ln;
		while (curr->ln != NULL)
		{
			prev = curr;
			curr = curr->ln;
		}
		prev->ln = NULL;
		printf("%d is Deleted", curr->dt);
		free(curr);
	}
	return 0;
}

// Function to delete a node with a specified key from the linked list
int delete_key(int k)
{
	if (head == NULL)
	{
		printf("List is Empty");
	}
	else if (head->dt == k)
	{
		temp = head;
		head = head->ln;
		free(temp);
	}
	else
	{
		struct node *prev;
		struct node *curr;
		prev = head;
		curr = head;
		while ((curr->dt != k) && (curr->ln != NULL))
		{
			prev = curr;
			curr = curr->ln;
		}
		if (curr->dt != k)
		{
			printf("Search Key not found ");
		}
		else
		{
			prev->ln = curr->ln;
			printf("%d is Deleted", curr->dt);
			free(curr);
		}
	}
	return 0;
}

// Function to Search an Element in  the linked list
int search(int k)
{
	if(head==NULL)
	{
		printf("List is Empty ");
	}
	else
	{
		ptr=head;
		while((ptr->dt!=k)&&(ptr->ln!=NULL))
		{
			ptr=ptr->ln;
		}
		if(ptr->dt==k)
		{
			printf("Search Data is Found");
		}
		else
		{
			printf("Search Data not Found");
		}
	}
	return 0;
}

// Function to display the linked list
int display()
{
	if (head == NULL)
	{
		printf("List is Empty");
	}
	else
	{
		printf("       ");
		for (ptr = head; ptr->ln != NULL; ptr = ptr->ln)
		{
			printf("|---|   ");
		}
		printf("|---|  \n");
		printf("HEAD");
		ptr = head;
		while (ptr->ln != NULL)
		{
			printf("-->| %d |", ptr->dt);
			ptr = ptr->ln;
		}
		printf("-->| %d |-->NULL\n       ", ptr->dt);
		ptr = head;
		while (ptr->ln != NULL)
		{
			printf("|---|   ");
			ptr = ptr->ln;
		}
		printf("|---|");
	}
	return 0;
}

/*
OUTPUT:
____SINGLY LINKED LIST OPERATIONS____
1.Insert at Front
2.Insert at End
3.Insert after a Specified Node
4.Delete from Front
5.Delete From End
6.Delete a Specified Node
7.Search for an Element in the List
8.Display


Enter the Option Number : 1
Enter the Element to be Inserted : 3
3 is Inserted at Front

Enter the Option Number : 1
Enter the Element to be Inserted : 3
3 is Inserted at Front

Enter the Option Number : 2
Enter the Element to be Inserted : 4
4 is Inserted at End

Enter the Option Number : 2
Enter the Element to be Inserted : 8
8 is Inserted at End

Enter the Option Number : 3
Enter the Element to be Inserted : 5
Enter the Key after the Element is to be Inserted : 3
5 is Inserted after 3

Enter the Option Number : 8
       |---|   |---|   |---|   |---|   |---|
HEAD-->| 3 |-->| 5 |-->| 3 |-->| 4 |-->| 8 |-->NULL
       |---|   |---|   |---|   |---|   |---|

Enter the Option Number : 7
Enter the Element to be Searched : 10
Search Data not Found

Enter the Option Number : 3
Enter the Element to be Inserted : 4
Enter the Key after the Element is to be Inserted : 7
Search Failed, Insertion is not possible

Enter the Option Number : 3
Enter the Element to be Inserted : 7
Enter the Key after the Element is to be Inserted : 5
7 is Inserted after 5

Enter the Option Number : 7
Enter the Element to be Searched : 0
Search Data not Found

Enter the Option Number : 7
Enter the Element to be Searched : 5
Search Data is Found

Enter the Option Number : 8
       |---|   |---|   |---|   |---|   |---|   |---|
HEAD-->| 3 |-->| 5 |-->| 7 |-->| 3 |-->| 4 |-->| 8 |-->NULL
       |---|   |---|   |---|   |---|   |---|   |---|

Enter the Option Number : 4
3 is Deleted

Enter the Option Number : 5
8 is Deleted

Enter the Option Number : 6
Enter Element to be Deleted : 4
4 is Deleted

Enter the Option Number : 6
Enter Element to be Deleted : 0
Search Key not found

Enter the Option Number : 8
       |---|   |---|   |---|
HEAD-->| 5 |-->| 7 |-->| 3 |-->NULL
       |---|   |---|   |---|

Enter the Option Number : 9
Program Terminated
*/
