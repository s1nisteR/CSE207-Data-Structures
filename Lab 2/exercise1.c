#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Maximum size of our stack
#define MAX_SIZE 100


//Declare our array to be used as a stack
int stack[MAX_SIZE];
//Initialize variable that points to the top of the stack
int top = -1;

//Function Declarations
bool push(int data);
void display();
bool pop(int* returnData);


int main()
{
        int choice = -1;
        int data;
        
        while(choice != 0)
        {
                //Take input of user's choice of operation
                printf("1. Insert data/ push stack\n2. Print stack\n3. Pop stack\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                printf("\n");
                
                
                switch(choice)
                {
                        case 0: break;
                        
                        
                        case 1:      //PUSH
                        {
                                printf("Enter data to PUSH: ");
                                scanf("%d", &data);
                                if(!push(data))
                                {
                                        printf("The stack is full!\n");
                                }
                                break;
                        }
                        
                        case 2:     //Display the stack
                        {
                                display();
                                break;
                        }
                        
                        case 3:     //POP
                        {
                                int poppedData; //variable to store and display the data that was popped
                                if(!pop(&poppedData))
                                {
                                        printf("Array is already empty!\n");
                                        break;
                                }
                                printf("Popped the data: %d\n", poppedData);
                                break;
                        }
                        
                        
                        default:
                        {
                                printf("Invalid choice\n");
                                break;
                        }
                }
        }
        
        return EXIT_SUCCESS;
}


//Function definitions
bool push(int data)
{
        //if top is at MAX_SIZE - 1 then our stack array is full
        if(top == MAX_SIZE - 1)
        {
                return false;
        }
        //increment top to point to free space
        top++;
        //store our data in that empty space
        stack[top] = data;
        return true;
}

bool pop(int* returnData)
{
        //check if stack is empty already
        if(top == -1)
        {
                return false;
        }
        //return the popped data
        *returnData = stack[top];
        top--;
        return true;
}

void display()
{
        //check if stack is already empty
        if(top == -1)
        {
                printf("The stack is empty!\n");
        }
        else
        {
                for(int i = top; i >= 0; i--)
                {
                        printf("%d ", stack[i]);
                }
                printf("\n");
        }
}