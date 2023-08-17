/*
  Muhammed Muhnis T K
  C-program to Implement Stack Using Array
  JEC21CS083
*/

#include <stdio.h>

// Declare global variables
int a[50], l, f, top, e;

// Function prototypes
int push(int el);
int display();
int pop();

int main() {
    printf("Enter the Number of Elements to be Pushed to the Stack(Maximum Size=50): ");
    scanf("%d", &l);

    top = -1;

    if (l > 50) {
        printf("\nMaximum size of the Stack is 50, Only 50 Elements can be Entered\n\n");
    }

    // Loop to push elements into the stack
    for (int i = 0; i < l; ++i) {
        if (top < 49) {
            printf("Enter the %d th Element to be Pushed to the Stack :", i + 1);
            scanf("%d", &e);
            push(e);
        } else {
            break;
        }
    }

label1:
    printf("\n");
    printf("STACK OPERATIONS\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.Terminate Program\n");
    printf("Enter the Choice Number : ");
    scanf("%d", &f);

    do {
        if (f == 1) {
            printf("Enter the Element to be Pushed to the Stack : ");
            scanf("%d", &e);
            push(e);
            printf("%d is Pushed to the Stack as %d th Location Element\n", e, top + 1);
            goto label1;
        } else if (f == 2) {
            pop();
            goto label1;
        } else if (f == 3) {
            display();
            goto label1;
        } else if (f == 4) {
            break;
        } else {
            printf("Wrong Input");
            goto label1;
        }
    } while (f > 0 && f < 5);

    return 0;
}

// Display function to print the elements in the stack
int display() {
    printf("The Elements in the Stack are :\n");
    for (int i = top; i >= 0; --i) {
        printf("          |  %d  |\n", a[i]);
        printf("          |_____|\n");
    }
    printf("\n");
    return 0;
}

// Push function to add an element to the stack
int push(int el) {
    if (top < 49) {
        ++top;
        a[top] = el;
    } else {
        printf("Stack is Full");
        return 0;
    }
    return 0;
}

// Pop function to remove an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        f = a[top];
        --top;
        printf("%d is Popped from the Stack\n", f);
    }
    return 0;
}

/*
OUTPUT:
Enter the Number of Elements to be Pushed to the Stack(Maximum Size=50): 5
Enter the 1 th Element to be Pushed to the Stack : 10
Enter the 2 th Element to be Pushed to the Stack : 20
Enter the 3 th Element to be Pushed to the Stack : 30
Enter the 4 th Element to be Pushed to the Stack : 40
Enter the 5 th Element to be Pushed to the Stack : 50

STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.Terminate Program
Enter the Choice Number : 3
The Elements in the Stack are :
          |  50  |
          |_____|
          |  40  |
          |_____|
          |  30  |
          |_____|
          |  20  |
          |_____|
          |  10  |
          |_____|
          
STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.Terminate Program
Enter the Choice Number : 1
Enter the Element to be Pushed to the Stack : 25
25 is Pushed to the Stack as 6 th Location Element

The Elements in the Stack are :
          | 25 |
          |____|
          | 50 |
          |____|
          | 40 |
          |____|
          | 30 |
          |____|
          | 20 |
          |____|
          | 10 |
          |____|
          
STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.Terminate Program
Enter the Choice Number : 2
25 is Popped from the Stack

The Elements in the Stack are :
          | 50 |
          |____|
          | 40 |
          |____|
          | 30 |
          |____|
          | 20 |
          |____|
          | 10 |
          |____|
          
STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.Terminate Program
Enter the Choice Number : 4


*/