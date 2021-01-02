#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

int main()
{
	int choice;
    do
    {
        printf("\n-------STACK MENU--------");
        printf("\n1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT \n");
        printf("\nEnter your choice correctly: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;        
            case 2: pop(); break;
            case 3: display();break;
            case 4: printf("EXITING...\n"); break;
            default: printf("INVALID CHOICE!!!\n");
        }
    }while(choice != 4);
    return 0;
}


void push()
{
    int item;
    struct node *newnode;
    printf("Enter the element you want to push : \n");
    scanf("%d",&item);    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(top==NULL)
        top=newnode;
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    if(top==NULL)
        printf("Stack is empty!!\n");
    else
    {      
      printf("Element removed is : %d\n", top->data);      
      top=top->next;        
    }       
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("Stack is empty");
        return;
    }
    printf("Contents of the stack are : \n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n"); 
}