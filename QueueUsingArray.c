/*Muhammed Muhnis T K
  C-Program to Implement Queue Using Array
  JEC21CS083*/ 
#include<stdio.h>
int qu[20],n,fr=-1,re=-1,i,en;
int enqueue(int it);
int display();
int dequeue();
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
	op:
	printf("\n_____QUEUE OPERATION_____\n");
	printf("1.Enqueue Operation\n");
	printf("2.Dequeue Operation\n");
	printf("3.Display\n");
	printf("4.Terminate Program\n");
	printf("Enter the Option Number : ");
	scanf("%d",&o);
	if(o==1)
	{
		if(re<n-1)
		{
			printf("Enter the Element to be Enqueued : ");
		    scanf("%d",&en);
		    enqueue(en);
		    printf("%d is Enqueued\n",en);
		}
		else
		{
			printf("Queue is Full\n");
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
int enqueue(int it)
{
	if((fr==-1)&&(re==-1))
	{
		fr=0;
		re=0;
		qu[re]=it;
	}
	else if((fr==0)&&(re==n))
	{
		printf("Queue is Full\n");
	}
	else
	{
		qu[++re]=it;
	}
	return 0;
}
int dequeue()
{
	if((fr==-1)&&(re==-1))
	{
		printf("Queue is Empty\n");
	}
	else if(fr==re)
	{
		printf("%d is Dequeued\n",qu[fr]);
		fr=re=-1;
	}
	else 
	{
		printf("%d is Dequeued\n",qu[fr++]);
	}
	return 0;
}
int display()
{
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
			printf("  %d  |",qu[i]);
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
	}
	return 0;
}
