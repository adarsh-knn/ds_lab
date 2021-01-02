#include <stdio.h>
#include <stdlib.h>

#define N  5

int queue[N];

void enQueue(int value, int *front, int *rear)
{
   if(*rear == N-1)
      printf("\nQueue is FULL!");
   else{
      if(*front == -1)
   *front = 0;
      (*rear)++;
      queue[*rear] = value;
      printf("\n Element has been INSERTED!");
   }
}
void deQueue(int *front, int *rear)
{
   if(*rear == *front && *front == -1) 
  {
     printf("\nQueue is EMPTY!\n");
     
  }
  else if(*front == *rear)
  {
    printf("\nDeleted element is : %d", queue[*front]);
    *front = *rear = -1;
    }
  else
  {
    printf("\nDeleted element is : %d", queue[*front]);
    *front += 1;
  }
}
void display(int *front, int *rear)
{
   if(*rear == -1)
      printf("\nQueue is EMPTY!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i = *front; i <= *rear; i++)
    printf("%d\t",queue[i]);
   }
}
int main()
{
  
   int value, choice;
   int front = -1, rear = -1;
   while(1)
   {
        printf("\n\tMENU");
        printf("\n----------------------------");
        printf("\n 1. INSERT element in queue");
        printf("\n 2. DELETE element from queue");
        printf("\n 3. DISPLAY the queue");
        printf("\n 4. EXIT");
        printf("\n----------------------------");
        printf("\nChoose operation : ");
      
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
              printf("Enter the value you want to insert: ");
              scanf("%d",&value);
              enQueue(value, &front, &rear);
              break;
            case 2: 
              deQueue(&front, &rear);
              break;
            case 3: 
              display(&front, &rear);
              break;
            case 4: 
              exit(0);
            default: printf("\nEnter the choice CORRECTLY!!");
        }
     }
   return 0;
}
