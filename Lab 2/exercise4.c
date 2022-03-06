#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Maximum size of our stack and hence our input
#define MAX_SIZE 10000


//Declare our array to be used as a stack
int stack[MAX_SIZE];
//Initialize variable that points to the top of the stack
int top = -1;

//Function Declarations
bool push(int data);
void display();
bool pop(int* returnData);
bool isEmpty();

int main()
{
        //Take user denary input
        int num;
        scanf("%d", &num);
        
        //While num is not zero, push the remainders of num % 2 onto stack and make num be num / 2 at each step of the loop  
        while(num != 0)
        {
                push((num % 2));
                num = num / 2;
        }
        
        
        int popResult;
        //Finally popping and printing each element until stack is empty will give us the binary representation of our supplied denary number
        while(!isEmpty())
        {
                pop(&popResult);
                printf("%d ", popResult);
        }
        printf("\n");
        
        
        //We could also just do this instead, and display the stack
        //Will achieve the same goal
        //display();
        
        
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

//Not needed for this exercise
//Only needed for previous exercises
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
//Function to check whether our stack is empty or not
bool isEmpty()
{
        if(top == -1) return true;
        return false;
}