/* Muhammed Muhnis T K
   C-Program to Implement Priority Queue
   JEC21CS083 */
#include<stdio.h>
struct pr_queue
{
	int it;
	int pr;
}a[20];
int loc,fr=-1,re=-1,n,i;
int enqueue(int it,int pr);
int dequeue();
int display();
int main()
{
	int el,prio;
	printf("Enter the Number of Elements to be Enqueued in the Priority Queue : ");
	scanf("%d",&n);
	for(int ir=0;ir<n;++ir)
	{
		printf("\nEnter the Element to be Enqueued : ");
		scanf("%d",&el);
		printf("Enter the  Priority of   Element : ");
		scanf("%d",&prio);
		enqueue(el,prio);
	}	
	int o;
	printf("\n\n______Priority Queue Operations______\n");
	printf("1.Enqueue Operation\n");
	printf("2.Dequeue Operation\n");
	printf("3.Display Operation\n");
	printf("4.Terminate Program"); 
	op:
	printf("\nEnter the Option Number : ");
	scanf("%d",&o);
    if(o==1)
	{
		if((fr==0)&&(re==n-1))
	    {
	        printf("Priority Queue is Full\n");
        }
        else
	    {
		    printf("Enter the Item to be Enqueued : ");
		    scanf("%d",&el);
		    printf("Enter the Priority of the Element to be Enqueued : ");
		    scanf("%d",&prio);
		    enqueue(el,prio);
		}
		goto op;			
    }
    else if(o==2)
    {
	    dequeue();
		goto op;
	else if(o==4)
	{
		printf("Program Terminated");
	}
	else
	{
		printf("!!!Wrong Input!!!");
		goto op;
	}
	return 0;
}