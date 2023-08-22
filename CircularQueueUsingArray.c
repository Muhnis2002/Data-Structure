/*
 Muhammed Muhnis T K
 C-Program to Implement Circular Queue Using Array
 JEC21CS083
*/
#include<stdio.h>
int qu[20],n,fr=-1,re=-1,i,en; // Declare global variables for queue and indices
int display(); // Function prototype for displaying the queue
int dequeue(); // Function prototype for dequeuing an element
int enqueue(int it); // Function prototype for enqueuing an element
int main()
{
	printf("Enter the Number of Elements to be Entered in the Queue(MAXIMUM SIZE=20) : ");
	scanf("%d",&n); // Read the number of elements to enqueue

	// Check if the number of elements is greater than the maximum size
	if(n>20)
	{
		printf("Only First 20 Elements can be Enqueued to the Queue");
	}

	// Enqueue initial 'n' elements provided by the user
	for(i=0;i<n;++i)
	{
		printf("Enter the %d th Element to be Enqueued : ",i+1);
		scanf("%d",&en);
		enqueue(en); // Call the enqueue function to add element to the queue
	}
	
	int o;
	printf("\n_____CIRCULAR QUEUE OPERATION_____\n");
	printf("1.Enqueue Operation\n");
	printf("2.Dequeue Operation\n");
	printf("3.Display\n");
	printf("4.Terminate Program\n");
	op:
	printf("\nEnter the Option Number : ");
	scanf("%d",&o); // Read user's choice of operation from the menu

	// Branching based on user's choice
	if(o==1)
	{
		// Enqueue operation
		if((re<n-1)||(fr>0))
		{
			printf("Enter the Element to be Enqueued : ");
		    scanf("%d",&en);
		    enqueue(en);
		    printf("%d is Enqueued\n",en);
		}
		else
		{
			printf("Circular Queue is Full\n");
		}			
		goto op;
	}
	else if(o==2)
	{
		dequeue(); // Call the dequeue function to remove element from the queue
		goto op;
	}
	else if(o==3)
	{
		display(); // Call the display function to show the current queue
		goto op;
	}
	else if(o==4)
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

// Enqueue function
int enqueue(int it)
{
	// Check if the queue is full
	if(fr==(re+1)%n)
	{
		printf("Circular Queue is Full\n");
	}
	// Check if the queue is empty
	else if((fr==-1)&&(re==-1))
	{
		fr=0;
		re=0;
		qu[re]=it;
	}
	// Enqueue the element
	else
	{
		re=(re+1)%n;
		qu[re]=it;
	}
	return 0;
}

// Dequeue function
int dequeue()
{
	// Check if the queue is empty
	if((fr==-1)&&(re==-1))
	{
		printf("Circular Queue is Empty\n");
	}
	// Check if there's only one element in the queue
	else if(fr==re)
	{
		printf("%d is Dequeued\n",qu[fr]);
		fr=re=-1;
	}
	else 
	{
		printf("%d is Dequeued\n",qu[fr]);
		fr=(fr+1)%n; // Move the front index forward
	}
	return 0;
}
// Display function
// Display function to show the contents of the circular queue
int display()
{
    if ((fr == -1) && (re == -1))
    {
        printf("!!Queue is Empty!!\n");  // Queue is empty, display a message
    }
    else if (fr <= re)  // Displaying the queue when front index is less than or equal to rear index
    {
        // Display horizontal lines to separate sections
        for (i = 0; i < n; ++i)
        { 
            printf("______");
        }
        printf("\n");

        // Display vertical lines to create the cell boundaries
        for (i = 0; i < n; ++i)
        {
            printf("     |");
        }
        printf("\n");

        // Display empty cells before the front index
        for (i = 0; i < fr; ++i)
        {
            printf("     |");
        }

        // Display elements from front index to rear index
        for (i = fr; i <= re; ++i)
        {
            printf("  %d  |", qu[i]);
        }

        // Display empty cells after the rear index
        for (i = re; i < n - 1; ++i)
        {
            printf("     |");
        }

        printf("\n");

        // Display horizontal lines to separate sections
        for (i = 0; i < n; ++i)
        {
            printf("_____|");			
        }	
        printf("\n");
    }
    else  // Displaying the queue when front index is greater than rear index (wrapped around)
    {
        // Display horizontal lines to separate sections
        for (i = 0; i < n; ++i)
        { 
            printf("______");
        }
        printf("\n");

        // Display vertical lines to create the cell boundaries
        for (i = 0; i < n; ++i)
        {
            printf("     |");
        }
        printf("\n");

        // Display elements from 0 to rear index
        for (i = 0; i <= re; ++i)
        {
            printf("  %d  |", qu[i]);
        }

        // Display empty cells between rear index and front index
        for (i = re + 1; i < fr; ++i)
        {
            printf("     |");
        }

        // Display elements from front index to end of the queue
        for (i = fr; i < n; ++i)
        {
            printf("  %d  |", qu[i]);
        }

        printf("\n");

        // Display horizontal lines to separate sections
        for (i = 0; i < n; ++i)
        {
            printf("_____|");			
        }	
        printf("\n");
    }
    return 0;  // Return 0 to indicate successful execution
}
