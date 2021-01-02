#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create();
void display();
void delete(int);
void insert_before();
void insert_at_nth();
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
    printf("\n1. CREATE \n2. INSERT AT FRONT POSITION \n3. INSERT AT Nth POSITION  \n4. DISPLAY  \n5. EXIT");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create();
                break;
        case 2: insert_before();
                break;
         case 3: printf("Enter the position to be inserted\n");
                scanf("%d",&ele);
                insert_at_nth(ele);
                break;
        case 4: display();
                break;
        case 5: printf("\nEXITINGGG....\n");
                break;
    }
    }while(choice != 5);
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
        printf("Nothing to print\n");
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

void insert_before()
{
    struct node *newnode;
    int stu_id;
    char stu_name[20];
    int semester;    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the ID of the student : ");
    scanf("%d", &stu_id);
    printf("Enter the NAME of the student : ");
    scanf("%s",stu_name);
    printf("Enter the SEMESTER of the student : ");
    scanf("%d", &semester);
    newnode->id=stu_id;
    strcpy(newnode->name, stu_name);
    newnode->sem=semester;
    newnode->next=head;
    head=newnode;  
 }

 void insert_at_nth(int p)
{
    struct node *newnode;
    int stu_id;
    char stu_name[20];
    int semester;
    if(p>count+2)
        printf("The position exceeds the number of nodes");
    else
    {
    printf("Enter the ID of the student : ");
    scanf("%d", &stu_id);
    printf("Enter the NAME of the student : ");
    scanf("%s",stu_name);
    printf("Enter the SEMESTER of the student : ");
    scanf("%d", &semester);
    newnode =(struct node *) malloc (sizeof(struct node));
    
    newnode->id=stu_id;
    strcpy(newnode->name, stu_name);
    newnode->sem=semester;
    
    if(head==NULL&& p>1)
    {
      printf("List empty, enter in first position\n");  
    }
    
    if(p==1)
    {
        printf("Inserted at the beginning\n");
        newnode->next=head;
        head=newnode;
        count++;        
    }
    
    else
    {      
        int i;
        struct node *temp1;
        temp1=head;
        for(i=2;i<p;i++)
        {
        temp1= temp1->next;
        }
        temp1->next=newnode;
        
        printf("Node inserted at %d position in linked list\n",p);
        count++;
        }
    }
}
