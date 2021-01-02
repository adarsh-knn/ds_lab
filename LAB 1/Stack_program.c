#include <stdio.h>

int top = -1;
void push(int stack[], int ele);
int pop(int stack[]);
void display(int stack[]);

int main()
{
	int stack[5];
	int i, choice, ele;
	
	do
	{
		printf("---MENU---\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice!\n");	
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
			printf("Enter the element that you want to Push :\n");
			scanf("%d", &ele);
			push(stack, ele);
			break;

			case 2:
			ele = pop(stack);
			if (ele == -1)
				printf("Stack Underflow\n");
			else
				printf("The Poped element is : %d\n", ele);
			break;
			case 3: display(stack);		
					break;
			case 4: printf("EXITING....\n");
					break;
			default: printf("Invalid choice!\n");
		}
	}
	while(choice != 4);
	return 0;
}

void push(int stack[], int ele)
{
    if (top==4)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top]=ele;
    }
}

int pop(int stack[])
{
    int popele;
    if(top==-1)
    
       return -1;
      
    else
    {
        popele=stack[top];
        top--;
        return (popele);
    }   
}

void display(int stack[])
{
    int i;
    printf("The stack elements\n");
    for(i=top;i>=0;i--)
    {
        
        printf("%d\n",stack[i]);
    }
}
