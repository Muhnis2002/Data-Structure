/* Muhammed Muhnis T K
   C-Program to Implement Priority Queue
   JEC21CS083 */

#include <stdio.h>

struct pr_queue {
    int it; // Item value
    int pr; // Priority value
} a[20]; // Array to store the priority queue elements

int loc, fr = -1, re = -1, n, i; // loc: location of insertion in enqueue, fr: front index, re: rear index

// Function prototypes
int enqueue(int it, int pr);
int dequeue();
int display();

int main() {
    int el, prio;

    // Input the number of elements to be enqueued
    printf("Enter the Number of Elements to be Enqueued in the Priority Queue : ");
    scanf("%d", &n);

    // Enqueue elements based on user input
    for (int ir = 0; ir < n; ++ir) {
        printf("\nEnter the Element to be Enqueued : ");
        scanf("%d", &el);
        printf("Enter the Priority of Element : ");
        scanf("%d", &prio);
        enqueue(el, prio); // Enqueue the element with its priority
    }

    int o;
    printf("\n\n______Priority Queue Operations______\n");
    printf("1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.Display Operation\n");
    printf("4.Terminate Program");
    
    op:
    printf("\nEnter the Option Number : ");
    scanf("%d", &o);

    if (o == 1) {
        if ((fr == 0) && (re == n - 1)) {
            printf("Priority Queue is Full\n");
        } else {
            printf("Enter the Item to be Enqueued : ");
            scanf("%d", &el);
            printf("Enter the Priority of the Element to be Enqueued : ");
            scanf("%d", &prio);
            enqueue(el, prio); // Enqueue an item with a given priority
        }
        goto op;
    } else if (o == 2) {
        dequeue(); // Dequeue an item
        goto op;
    } else if(o == 3) {
		display();
		goto op;
	} else if (o == 4) {
        printf("Program Terminated");
    } else {
        printf("!!!Wrong Input!!!");
        goto op;
    }

    return 0;
}

// Enqueue an element with a given priority
int enqueue(int it, int pr) {
    if ((fr == 0) && (re == n - 1)) {
        printf("Priority Queue is Full\n");
    } else if (fr == -1) {
        fr = re = 0;
        a[fr].it = it;
        a[fr].pr = pr;
    } else if (re == n - 1) {
        for (i = fr; i <= re; ++i) {
            a[i - 1] = a[i];
        }
        --fr, --re;
        for (i = re; i >= fr; --i) {
            if (a[i].pr < pr) {
                break;
            }
        }
        loc = i + 1;
        for (i = re; i >= loc; --i) {
            a[i + 1] = a[i];
        }
        ++re;
        a[loc].it = it;
        a[loc].pr = pr;
    } else {
        for (i = re; i >= fr; --i) {
            if (a[i].pr < pr) {
                break;
            }
        }
        loc = i + 1;
        for (i = re; i >= loc; --i) {
            a[i + 1] = a[i];
        }
        ++re;
        a[loc].it = it;
        a[loc].pr = pr;
    }
    return 0;
}

// Dequeue an element
int dequeue() {
    if (fr == -1) {
        printf("Priority Queue is Empty\n");
    } else if (fr == re) {
        printf("Dequeued Item is %d\n", a[fr].it);
        fr = re = -1;
    } else {
        printf("Dequeued item is %d\n", a[fr].it);
        ++fr;
    }
    return 0;
}

// Display the priority queue
int display() {
    // Display the contents of the priority queue visually
    // (Note: The actual display logic is present in this function, but it's not being called in the provided code)
    if((fr==-1)&&(re==-1))
	{
		printf("!!Queue is Empty!!\n");
	}
	else
	{
		for(i=0;i<n;++i)
		{
			printf("______");
		}
		printf("\n");
		for(i=0;i<n;++i)
		{
			printf("     |");
		}
		printf("\n");
		for(i=0;i<fr;++i)
		{
			printf("     |");
		}
		for(i=fr;i<=re;++i)
		{
			printf("  %d  |",a[i].it);
		}
		for(i=re;i<n-1;++i)
		{
			printf("     |");
		}
		printf("\n");
		for(i=0;i<n;++i)
		{
			printf("_____|");			
		}
		printf("\n");
		for(i=0;i<fr;++i)
		{
			printf("     |");
		}
		for(i=fr;i<=re;++i)
		{
			printf("  %d  |",a[i].pr);
		}
		for(i=re;i<n-1;++i)
		{
			printf("     |");
		}
		printf("\n");
		for(i=0;i<n;++i)
		{
			printf("-----|");			
		}	
		printf("\n");	
	}
    return 0;
}
