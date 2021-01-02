#include <stdio.h>
#include <stdlib.h>
void create1();
void create2();
void sort();
void reverse();
void concatenate();
void display();
struct node
{
  int data;
  struct node *next;  
};

struct node *head=NULL;
struct node *head2= NULL;
int c;

int main(int argc, char **argv)
{
	int choice;
    do
    {
    printf("\n1. CREATE \n2. SORT LINKED LIST \n3. REVERSE LINKED LIST \n4. CONCATENATE 2 LINKED LISTS \n5. DISPLAY  \n6. EXIT");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create1();
                break;
        case 2: sort();
                //display();
                break;
        case 3: reverse();
                //display();
                break;
        case 4: create2();
                concatenate();
                //display();
                break;
        case 5: display();
                break;
        case 6: printf("\nEXITINGGG....\n");
                break;
    }
    }while(choice != 6);
    return 0;
}

void create1()
{
    struct node *newnode;
    struct node *temp;
    int s;
    printf("Enter integer  : ");
    scanf("%d",&s);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data =s;
    if (head==NULL)
    { 
      newnode->next=NULL;
      head=newnode; 
      printf("first node of linked list created\n");
      c++;
    }
     else 
     {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
    temp->next=newnode;
    newnode->next=NULL;
    c++;
    printf("Node created\n");
   }  
}

void reverse()
{
    struct node *prev=NULL,*current=head, *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("The list is reversed successfully!!\n");
}

void display()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\n-----CONTENTS OF LINKED LIST-----\n");
        while(ptr!=NULL)
       {          
          printf("%d\t",ptr->data);
          ptr=ptr->next;
       }
    }
    printf("\n");
}

void concatenate()
{
    struct node *ptr;
        if(head==NULL)
        {
                head=head2;
        }
        if(head2==NULL)
               {
                head2=head;
               }
        ptr=head;
        while(ptr->next!=NULL)
                ptr=ptr->next;
        ptr->next=head2;
}

void sort()
{
    int swap, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  

    if (head == NULL) 
        return; 
  
    do
    { 
        swap = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                int temp = ptr1->data; 
                ptr1->data = ptr1->next->data; 
                ptr1->next->data = temp; 
                swap = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while(swap); 
}

void create2()
{
  struct node *newnode;
  struct node *temp;
    int s,y;
    printf("Enter elements to the SECOND linked list 2\n");
    do
    {
    printf("Enter integer  : \n");
    scanf("%d",&s);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data =s;
    if (head2==NULL)
    { 
      newnode->next=NULL;
      head2=newnode; 
      printf("first node of linked list created\n");
      c++;
    }
     else 
     {
    temp=head2;
        while(temp->next!=NULL)
        {
      temp=temp->next;
        }
    temp->next=newnode;
    newnode->next=NULL;
    c++;
    printf("Node created\n");
   } 
   printf("Do u want to continue adding: 0 or 1\n");
   scanf("%d",&y);
    }
    while(y!=0);
}
