#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;

void create(int n);
void deleteEndNode();
void display();

int main()
{
	int n;
	printf("Enter number of nodes you want in the linked list");
	scanf("%d",&n);
	create(n);

	printf("the list intially has elements");
	display();

	deleteEndNode();

	printf("The updated list contains elements");
	display();

	return 0;
}

void create(int n)
{
	struct node *newnode, *temp;
	int data,i;
	head=(struct node*)malloc(sizeof(struct node));

	printf("Enter data in 1st node");
	scanf("%d",&data);

	head ->data=data;
	head->next=NULL;

	temp=head;

	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));

		printf("Enter data of node %d: ",i);
		scanf("%d",&data);

		newnode->data=data;
		newnode->next=NULL;

		temp->next=newnode;
		temp=temp->next;
	}
}

void deleteEndNode()
{
	struct node *del,*ptr;
	if(head==NULL)
		printf("List is empty");
	else
	{
		del=head;
		ptr=head;

		while(del->next != NULL)
		{
		    ptr=del;
		    del=del->next;
		}

		if(del==head)
		 head=NULL;
		else
		 ptr->next=NULL;

		free(del);
	}
}
void display()
{
	struct node *temp;

	if(head==NULL)
	  printf("list is empty");
	else
	 {
	   temp=head;
	   while(temp!=NULL)
	   {
	     printf("%d\n",temp->data);
	     temp=temp->next;
	   }
	 }
	getch();
}