/*
 Muhammed Muhnis T K
 C-Program to Implement Double Ended Queue Using Array
 JEC21CS083
*/
#include<stdio.h>
int qu[20],n,fr=-1,re=-1,i,en;
int display();
int dequeue();
int enqueue(int it);
int main()
{
	printf("Enter the Number of Elements to be Entered in the Queue(MAXIMUM SIZE=20) : ");
	scanf("%d",&n);
	if(n>20)
	{
		printf("Only First 20 Elements can be Enqueued to the Queue");
	}
	for(i=0;i<n;++i)
	{
		printf("Enter the %d th Element to be Enqueued : ",i+1);
		scanf("%d",&en);
		enqueue(en);
	}
	int o;
	printf("\n_____CIRCULAR QUEUE OPERATION_____\n");
	printf("1.Enqueue Operation\n");
	printf("2.Dequeue Operation\n");
	printf("3.Display\n");
	printf("4.Terminate Program\n");
	op:
	printf("\nEnter the Option Number : ");
	scanf("%d",&o);
	if(o==1)
	{
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
		dequeue();
		goto op;
	}
	else if(o==3)
	{
		display();
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