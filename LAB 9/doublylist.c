#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void insert_beg()
{
	 struct node *new_node;
	 new_node=(struct node*)malloc(sizeof(struct node));
	 printf("Enter the number you want to insert : \n");
	 scanf("%d",&new_node->data);
	 new_node->next=NULL;
	 new_node->prev=NULL;

	 if(head==NULL)
	 {
			head=new_node;
      printf("Element INSERTED!!\n");
	 }
	 else
	 {
			new_node->next=head;
			head->prev=new_node;
			head=new_node;
      printf("Element INSERTED!!\n");
	 }
}

void insert_left()
{
	int listele;
	struct node *new_node,*temp;
	printf("Enter the element in the list : \n");
	scanf("%d",&listele);
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the new node data : \n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
    if(head==NULL)
    {
        printf("Empty list\n"); return;
    }
	temp=head;
	while(temp->data!=listele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Element is  not in the list");
			return;
		}
	}
  new_node->prev=temp->prev;
	temp->prev=new_node;
	new_node->next=temp;
	new_node->prev->next=new_node;
}

void insert_right()
{
  int listele;
	struct node *new_node,*temp;
	printf("Enter the element in the list :\n");
	scanf("%d",&listele);
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the new node data : \n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
    if(head==NULL)
    {
        printf("Empty list\n"); return;
    }
	temp=head;
	while(temp->data!=listele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Element is  not in the list");
			return;
		}
	}
	new_node->next=temp->next;
	temp->next=new_node;
	new_node->prev=temp;
	new_node->next->prev=new_node;
}

void insert_end()
{
	struct node *new_node,*temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to insert : \n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=new_node;
		 new_node->prev=temp;
	}
}

void del()
{
	struct node *temp;
	int ele;
  if(head==NULL)
  {
      printf("EMPTY LIST!!\n");
      return;
  }
	printf("Enter the element to be deleted :\n");
	scanf("%d",&ele);
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element is NOT FOUND in the list!!\n");
		 return;
		}
	 }
	 if(temp==head)
	 {
		 head=head->next;
     printf("Element is DELETED!!\n");
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
      printf("Element is DELETED!!\n");
	 }
	 else
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
     printf("Element is DELETED!!\n");
	 }
}

void display()
{
	 struct node *temp;
	 temp=head;
   if(temp==NULL)
   {
        printf("Nothing to print!! EMPTY LIST!!\n");
        return;
   }
   printf("CONTENTS OF THE LIST ARE : \n");
	 while(temp!=NULL)
	 {
		 printf("%d\t",temp->data);
		 temp=temp->next;
	 }
	 printf("\n");
}

int main()
{
	int choice;
	 do
	 {
      printf("\n-----MENU------\n");
      printf(" 1. INSERT AT THE BEGINNING \n");
			printf(" 2. INSERT AT THE LEFT \n");
      printf(" 3. INSERT AT THE RIGHT \n");
      printf(" 4. INSERT AT THE END \n");
			printf(" 5. DELETE \n");
			printf(" 6. DISPLAY\n");
			printf(" 7. EXIT\n");
			printf("\nEnter your choice : \n");
			scanf("%d",&choice);
			switch(choice)
			{
         case 1 : insert_beg(); break;
				 case 2 : insert_left(); break;
         case 3 : insert_right(); break;
         case 4 : insert_end(); break;
				 case 5 : del(); break;
				 case 6 : display(); break;
				 case 7 : printf("EXITING...\n");break;
         default : printf("Enter your choice CORRECTLY!!\n"); break;
			}
	 }
   while(choice != 7);
   return 0;
}
