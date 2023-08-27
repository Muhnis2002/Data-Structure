/*Muhammed Muhnis T K
 C-Program to Implement Singly Linked List
 JEC21CS083*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int dt;
	struct node *ln;
};
struct node *head,*ptr,*new,*temp;
int display();
int insert_fr(int it);
int insert_end(int o);
int insert_key(int k,int o);
int delete_fr();
int delete_end();
int delete_key(int o);
int search(int o);
int main()
{
	printf("\n\n____SINGLY LINKED LIST OPERATIONS____\n");
	printf("1.Insert at Front\n");
	printf("2.Insert at End\n");
	printf("3.Insert after a Specified Node\n");
	printf("4.Delete from Front\n");
	printf("5.Delete From End\n");
	printf("6.Delete a Specified Node\n");
	printf("7.Search for an Element in the List\n");
	printf("8.Display\n");
	int o,k;
	op:
	printf("\n\nEnter the Option Number : ");
	scanf("%d",&o);
	if(o==1)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		insert_fr(o);
		printf("%d is Inserted at Front",o);
		goto op;
	}
	else if(o==2)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		insert_end(o);
		printf("%d is Inserted at End",o);
		goto op;
	}
	else if(o==3)
	{
		printf("Enter the Element to be Inserted : ");
		scanf("%d",&o);
		printf("Enter the Key after the Element is to be Inserted : ");
		scanf("%d",&k);
		insert_key(k,o);
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
		printf("Enter Element to be Deleted : ");
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
		printf("!!Wrong Input!!");
		goto op;
	}
	return 0;
}
int insert_fr(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->ln=head;
	new->dt=it;
	head=new;
	return 0;
}
int insert_end(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->dt=it;
	new->ln=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->ln!=NULL)
		{
			ptr=ptr->ln;
		}
	}
	ptr->ln=new;
	return 0;
}
int insert_key(int k,int x)
{
	if(head==NULL)
	{
		printf("Search Failed,Insertion is not possible ");
	}
	else
	{
		ptr=head;
		while((ptr->dt!=k)&&(ptr->ln!=NULL))
		{
			ptr=ptr->ln;
		}
		if(ptr->dt!=k)
		{
			printf("Search Failed,Insertion is not possible ");
		}
		else
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->dt=x;
			new->ln=ptr->ln;
			ptr->ln=new;
			printf("%d is Inserted after %d ",x,k);			
		}
		
	}
	return 0;
}
int delete_fr()
{
	if(head==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		temp=head;
		head=head->ln;
		printf("%d is Deleted",temp->dt);
		free(temp);
	}
	return 0;
}
int delete_end()
{
	struct node *prev;
	struct node *curr;
	if(head==NULL)
	{
		printf("List is Empty");
	}
	else if(head->ln==NULL)
	{
		temp=head;
		head=NULL;
		printf("%d is Deleted",temp->dt);
		free(temp);
	}
	else
	{
		prev=head;
		curr=head->ln;
		while(curr->ln!=NULL)
		{
			prev=curr;
			curr=curr->ln;
		}
		prev->ln=NULL;
		printf("%d is Deleted",curr->dt);
		free(curr);
	}
	return 0;
}
int delete_key(int k)
{
	if(head==NULL)
	{
		printf("List is Empty");
	}
	else if(head->dt==k)
	{
		temp=head;
		head=head->ln;
		free(temp);
	}
	else
	{
		struct node *prev;
	    struct node *curr;
		prev=head;
		curr=head;
		while((curr->dt!=k)&&(curr->ln!=NULL))
		{
			prev=curr;
			curr=curr->ln;
		}
		if(curr->dt!=k)
		{
			printf("Search Key not found ");
		}
		else
		{
			prev->ln=curr->ln;
			printf("%d is Deleted",curr->dt);
			free(curr);			
		}
	}
	return 0;
}