#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create();
void display();
void delete(int);
void delete_first();
void delete_last();
struct node
{
    int id;
    char name[20];
    int sem;
    struct node *next;
};
struct node *head=NULL;
int count=0;

int main()
{
    int choice,ele;
    do
    {
    printf("\n1. CREATE \n2. DELETE FIRST NODE \n3. DELETE Nth NODE \n4. DELETE LAST NODE \n5. DISPLAY  \n6. EXIT");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create();
                break;
        case 2: delete_first();
                break;
        case 3: printf("Enter the ID to be deleted\n");
                scanf("%d",&ele);
                delete(ele);
                break;
        case 4: delete_last();
                break;
        case 5: display();
                break;
        case 6: printf("\nEXITINGGG....\n");
                break;
    }
    }while(choice != 6);
    return 0;
}

void create()
{
   struct node *newnode,*temp;
    int stu_id;
    char stu_name[20];
    int semester;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("Enter the ID of the student : ");
    scanf("%d", &stu_id); 
    printf("Enter the NAME of the student : ");
    scanf("%s",stu_name);       
    printf("Enter the SEMESTER of the student : ");
    scanf("%d", &semester);
    newnode->id=stu_id;
    strcpy(newnode->name, stu_name);
    newnode->sem=semester;
    if (head==NULL)
     { 
       newnode->next=NULL;
      head=newnode; 
      printf("Node created\n");
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
       printf("Node created\n");
   }  
}

void display()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("EMPTY LIST!! Nothing to print\n");
    }
    else
    {
        printf("\n-----CONTENTS OF LINKED LIST-----\n");
        printf("\nID\tNAME\tSEMESTER\n\n");
        while(ptr!=NULL)
       {        
        printf("%d\t%s\t%d\n",ptr->id,ptr->name,ptr->sem);
        ptr=ptr->next;
       }
    }    
}

void delete(int ele)
{
    struct node *temp,*del=NULL;
     
     if (head == NULL)
     {
         printf("Empty List. Can't delete\n");
         return;
     }
     temp=head;
     if(head->id==ele)
     {
         head=head->next;
         printf("Successfully deleted the ID from the list.\n");
         return;
     }
    while (temp->next!=NULL)
    {
        if(temp->next->id==ele)
        {
            del=temp->next;
           if(del->next==NULL)
           temp->next=NULL;
           else
            temp->next=del->next;
        }            
        else
           temp=temp->next;
    }
    if(del==NULL)
    {
        printf("Student ID not found in the list\n");
        return;
    }
    printf("Successfully deleted the ID from the list.\n");
}

void delete_first()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("Empty List. Can't delete.\n");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("ID deleted = %d\n", toDelete->id);

        free(toDelete);

        printf("Successfully deleted first node from the list.\n");
    }
}

void delete_last()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("Empty List. Can't delete.\n");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;
        /* Traverse to the last node of the list */
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }
        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }
        /* Delete the last node */
        free(toDelete);

        printf("Successfully deleted last node from the list.\n");
    }
}