/*
 Muhammed Muhnis T K
 C-Program to Implement Circular Linked List
 JEC21CS083
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int dt;
	struct node *ln;
};
struct node *ptr,*head,*new,*temp,*prev,*curr;
int display();
int insert_fr(int it);
int insert_end(int it);
int insert_after(int it,int k);
int delete_fr();
int delete_end();
int delete_key(int k);
int search(int k);
int main()
{
	int o,p;
	printf("_____CIRCULAR LINKED LIST OPERATION______\n");
	printf("1.Insert at Front\n");
	printf("2.Insert at End\n");
	printf("3.Insert after a Specified Node\n");
	printf("4.Delete From Front\n");
	printf("5.Delete From End\n");
	printf("6.Delete a Specified Node\n");
	printf("7.Search an Element\n");
	printf("8.Display\n");
	printf("9.Terminate Program\n");
	op:
	printf("\n\nEnter the Option Number : ");
	scanf("%d",&o);
	if(o==1)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		insert_fr(o);
		goto op;
	}
	else if(o==2)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		insert_end(o);
		goto op;
	}
	else if(o==3)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		printf("Enter the Key : ");
		scanf("%d",&p);
		insert_after(o,p);
		goto op;
	}
	else if(o==4)
	{
		delete_fr();
		goto op;
	}
	else if(o==5)
	{
		delete_end();
		goto op;
	}
	else if(o==6)
	{
		printf("Enter the Element to be Deleted : ");
		scanf("%d",&o);
		delete_key(o);
		goto op;
	}
	else if(o==7)
	{
		printf("Enter the Element to be Searched : ");
		scanf("%d",&o);
		search(o);
		goto op;
	}
	else if(o==8)
	{
		display();
		goto op;
	}
	else if(o==9)
	{
		printf("Program Terminated");
	}
	else
	{
		printf("!! Wrong Input !!");
		goto op;
	}
	return 0;
}