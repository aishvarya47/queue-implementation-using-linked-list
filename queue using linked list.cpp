//QUEUE//
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
};
struct node*head=NULL;
struct node*front;
struct node*rear;
void enqueue(int value)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=newnode;
		newnode->data=value;
		newnode->next=NULL;
		front=newnode;
		rear=newnode;
	}
	else
	{
		front->next=newnode;
		newnode->data=value;
		newnode->next=NULL;
		rear=newnode;
		front=front->next;
	}
}
void dequeue()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("QUEUE IS EMPTY!\n");
	}
	else
	{
		printf("DEQUEUED ELEMENT = %d\n",head->data);
		temp=head;
		head=head->next;
		free(temp);
	}
}
void display()
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
		temp=temp->next;
	}
//	if(temp==NULL)
//	{
//		printf("%d",temp->data);
//	}
    printf("NULL\n");
}
int main()
{
	int choice,datum;
	printf("QUEUE IMPLEMENTATION USING LINKED LIST\n");
	while(1)
	{
	printf("1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("ENTER THE ELEMENT TO BE PUSHED:\n");
		scanf("%d",&datum);
		enqueue(datum);
	}
	else if(choice==2)
	{
		dequeue();
	}
	else if(choice==3)
	{
		display();

	}
	else
	{
		printf("EXIT\n");
	}
	}
	return 0;
}
