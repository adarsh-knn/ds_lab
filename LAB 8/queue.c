#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insert();
void display();
void delete();

struct  node *rear=NULL, *front =NULL;

int main()
{
;
    int choice;
    do
    {
        printf("\n--------QUEUE MENU--------");
        printf("\n1. CREATE \n2. DELETE  \n3. DISPLAY  \n4. EXIT \n");
        printf("\nEnter your choice correctly : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;        
            case 2: delete(); break;
            case 3: display();break;
            case 4: printf("EXITING...\n"); break;
            default: printf("INVALID CHOICE!!!\n");
        }
    }while(choice != 4);
    return 0;
}

void insert()
{
    struct  node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(rear==NULL)
    {
        rear=newnode;
        front=newnode;        
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void delete()
{
    if(front==NULL)
    {
       printf("Queue is empty!! QUEUE UNDERFLOW!!\n");return;  
    }
       
    else
    {
        printf("Deleted ele is : %d\n",front->data);
        if(front==rear)
        {
           front=NULL;
           rear=NULL;
        }
        else
        front=front->next; 
    }
}

void display()
{
    struct node *temp;
    if(front ==NULL)
    {
        printf("Queue is empty!! NOTHING TO DISPLAY!!\n");
        return;
    }
    temp=front;
    printf("Contents of the queue are : \n");
    while (temp !=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");  
}