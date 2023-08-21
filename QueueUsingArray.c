/*Muhammed Muhnis T K
  C-Program to Implement Queue Using Array
  JEC21CS083*/
#include<stdio.h>

// Global variables
int qu[20];     // Array to store the queue elements
int n;          // Maximum number of elements in the queue
int fr = -1, re = -1; // Front and rear pointers for the queue
int i, en;      // Loop variable and variable to store the enqueued element

// Function prototypes
int enqueue(int it);
int display();
int dequeue();

int main()
{
    printf("Enter the Number of Elements to be Entered in the Queue (MAXIMUM SIZE=20): ");
    scanf("%d", &n);

    if (n > 20)
    {
        printf("Only First 20 Elements can be Enqueued to the Queue");
    }

    // Enqueue elements into the queue
    for (i = 0; i < n; ++i)
    {
        printf("Enter the %d th Element to be Enqueued : ", i + 1);
        scanf("%d", &en);
        enqueue(en);
    }

    int o;

op:
    printf("\n_____QUEUE OPERATION_____\n");
    printf("1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.Display\n");
    printf("4.Terminate Program\n");
    printf("Enter the Option Number : ");
    scanf("%d", &o);

    if (o == 1)
    {
        // Enqueue operation
        if (re < n - 1)
        {
            printf("Enter the Element to be Enqueued : ");
            scanf("%d", &en);
            enqueue(en);
            printf("%d is Enqueued\n", en);
        }
        else
        {
            printf("Queue is Full\n");
        }
        goto op; // Jump to the label "op"
    }
    else if (o == 2)
    {
        // Dequeue operation
        dequeue();
        goto op;
    }
    else if (o == 3)
    {
        // Display operation
        display();
        goto op;
    }
    else if (o == 4)
    {
        printf("Program Terminated");
    }
    else
    {
        printf("Wrong Input");
        goto op;
    }

    return 0;
}

// Function to enqueue an element into the queue
int enqueue(int it)
{
    if ((fr == -1) && (re == -1))
    {
        fr = 0;
        re = 0;
        qu[re] = it;
    }
    else if ((fr == 0) && (re == n))
    {
        printf("Queue is Full\n");
    }
    else
    {
        qu[++re] = it;
    }
    return 0;
}

// Function to dequeue an element from the queue
int dequeue()
{
    if ((fr == -1) && (re == -1))
    {
        printf("Queue is Empty\n");
    }
    else if (fr == re)
    {
        printf("%d is Dequeued\n", qu[fr]);
        fr = re = -1;
    }
    else
    {
        printf("%d is Dequeued\n", qu[fr++]);
    }
    return 0;
}

// Function to display the current state of the queue
int display()
{
    if ((fr == -1) && (re == -1))
    {
        printf("!!Queue is Empty!!\n");
    }
    else
    {
        // Display the queue using a graphical representation
        // involving pipe characters and queue elements
        for (i = 0; i < n; ++i)
        {
            printf("______");
        }
        printf("\n");
        // ...
        // (The display function outputs a visual representation of the queue)
        // ...
        printf("\n");
    }
    return 0;
}
/*
Enter the Number of Elements to be Entered in the Queue(MAXIMUM SIZE=20) : 5
Enter the 1 th Element to be Enqueued : 3
Enter the 2 th Element to be Enqueued : 2
Enter the 3 th Element to be Enqueued : 6
Enter the 4 th Element to be Enqueued : 8
Enter the 5 th Element to be Enqueued : 9

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 1
Queue is Full

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 2
3 is Dequeued

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 3
______________________________
     |     |     |     |     |
     |  2  |  6  |  8  |  9  |
_____|_____|_____|_____|_____|

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 1
Queue is Full

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 9
Wrong Input
_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 3
______________________________
     |     |     |     |     |
     |  2  |  6  |  8  |  9  |
_____|_____|_____|_____|_____|

_____QUEUE OPERATION_____
1.Enqueue Operation
2.Dequeue Operation
3.Display
4.Terminate Program
Enter the Option Number : 4
Program Terminated

------------------
(program exited with code: 0)

Press any key to continue . . .
*/

