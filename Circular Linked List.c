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
int insert_fr(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->dt=it;
	if(head==NULL)
	{
		head=new;
		new->ln=new;
	}
	else
	{
		ptr=head;
		while(ptr->ln!=head)
			ptr=ptr->ln;
		new->ln=head;
		head=new;
		ptr->ln=head;
	}
	printf("%d is Inserted at Front",it);
	return 0;
}
int insert_end(int it)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->dt=it;
	if(head==NULL)
	{
		new->ln=new;
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->ln!=head)
		{
			ptr=ptr->ln;
		}
		ptr->ln=new;
		new->ln=head;
	}
	printf("%d is Inserted at End",it);
	return 0;
}
int insert_after(int it,int k)
{
	if(head==NULL)
	{
		printf("Search Data Not Found");
	}
	else
	{
		while(ptr->dt!=k)
		{
			ptr=ptr->ln;
			if(ptr==head)
			{
				break;
			}
		}
		if(ptr->dt==k)
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->dt=it;
			new->ln=ptr->ln;
			ptr->ln=new;
			printf("%d is Inserted after %d",it,k);
		}
		else
		{
			printf("Search Data Not Found,Insertion Not Possible");
		}
	}
	return 0;
}
int delete_fr()
{
	if(head==NULL)
	{
		printf("!! List is Empty !! Delettion is Not Possible!!");
	}
	else if(head->ln==head)
	{
		temp=head;
		head=NULL;
		printf("%d is Deleted",temp->dt);
		free(temp);		
	}
	else
	{
		temp=ptr=head;
		while(ptr->ln!=head)
		{
			ptr=ptr->ln;
		}
		head=head->ln;
		ptr->ln=head;
		printf("%d is Deleted",temp->dt);
		free(temp);
	}
	return 0;
}
int delete_end()
{
	if(head==NULL)
	{
		printf("!!List is Empty !! Deletion is Not Possible ");
	}
	else if(head->ln==head)
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
		while(curr->ln!=head)
		{
			prev=curr;
			curr=curr->ln;
		}
		prev->ln=head;
		printf("%d is Deleted",curr->dt);
		free(curr);
	}
	return 0;
}
int delete_key(int k)
{
	if(head==NULL)
	{
		printf("List is Empty !! Deletion is Not Possible !!");
	}
	else if(head->ln==head)
	{
		if(head->dt==k)
		{
			temp=head;
			head=NULL;
			printf("%d is Deleted",temp->dt);
			free(temp);
		}
		else
		{
			printf("Key Data Not Found !! Deletion not Possible !!");
		}
	}
	else if(head->dt==k)
	{
		temp=ptr=head;
		while(ptr->ln!=head)
		{
			ptr=ptr->ln;
		}
		head=head->ln;
		ptr->ln=head;
		printf("%d is Deleted",temp->dt);
		free(temp);
	}
	else
	{
		prev=head;
		curr=head->ln;
		while((curr->ln!=head)&&(curr->dt!=k))
		{
			prev=curr;
			curr=curr->ln;
		}
		if(curr->dt==k)
		{
			prev->ln=curr->ln;
			printf("%d is Deleted",curr->dt);
			free(curr);
		}
		else
		{
			printf("Key ELement not Found !!Deletion is Not Possible ");
		}
	}
	return 0;
}