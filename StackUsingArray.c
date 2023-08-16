#include<stdio.h>
int a[50],l,f,top,e;
int push(int el);
int display();
int pop();
int main()
{
	printf("Enter the Number of Elements to be Pushed to the Stack(Maximum Size=50): ");
	scanf("%d",&l);
	top=-1;
	if(l>50)
	{
		printf("\nMaximum size of the Stack is 50,Only 50 Elements can be Entered\n\n");
	}
	for(int i=0;i<l;++i)
	{
		if(top<49)
		{
			printf("Enter the %d th Element to be Pushed to the Stack :",i+1);
	        scanf("%d",&e);
	        push(e);
		}
		else
		{
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
	scanf("%d",&f);
	do
	{
		if(f==1)
	    {
		    printf("Enter the Element to be Pushed to the Stack : ");
		    scanf("%d",&e);
		    push(e);
		    printf("%d is Pushed to the Stack as %d th Location Element\n",e,top+1);
		    goto label1;
	    }
	    else if(f==2)
	    {
		    pop();
		    goto label1;
	    }
	    else if(f==3)
	    {
			display();
	        goto label1;
	    }
	    else if(f==4)
	    {
			break;	
		}
		else
		{
			printf("Wrong Input");
			goto label1;
		}	
	}while(f>0&&f<5);
	return 0;
}
int display()
{
	printf("The Elements in the Stack are :\n");
	for(int i=top;i>=0;--i)
	{
		printf("          |  %d  |\n",a[i]);
		printf("          |_____|\n");
	}
	printf("\n");
	return 0;
}
int push(int el)
{
	if(top<49)
	{
		++top;
	    a[top]=el;
	}
	else
	{
		printf("Stack is Full");
		return 0;
	}
	return 0;
}
int pop()
{
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		f=a[top];
		--top;
		printf("%d is Poped from the Stack  \n",f);
	}
	return 0;
}
