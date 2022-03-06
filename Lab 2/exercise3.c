#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Maximum size of our stack and hence our input
#define MAX_SIZE 100


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
        //Taking user's input string
        char input[MAX_SIZE] = "";
        scanf("%s", input);     //Possible Buffer Overflow
        
        //Temporary variable to pass into pop() function(for specific design of this program)
        int tmp;
        
        //Loop over each character of the string
        for(int i = 0; i < strlen(input); i++)
        {
                //if ( { [ then push onto the top of the stack
                if(input[i] == '(' || input[i] == '{' || input[i] == '[')
                {
                        push(input[i]);
                }
                //otherwise pop ONLY IF the top is the corresponding opening bracket
                else if(input[i] == ')')
                {
                        if(stack[top] == '(')
                        {
                                pop(&tmp);
                        }
                        //if mismatch then invalid
                        else
                        {
                                printf("The parentheses are invalid!\n");
                                return EXIT_SUCCESS;
                        }
                }
                else if(input[i] == '}')
                {
                        if(stack[top] == '{')
                        {
                                pop(&tmp);
                        }
                        else
                        {
                                printf("The parentheses are invalid!\n");
                                return EXIT_SUCCESS;
                        }
                }
                else if(input[i] == ']')
                {
                        if(stack[top] == '[')
                        {
                                pop(&tmp);
                        }
                        else
                        {
                                printf("The parentheses are invalid!\n");
                                return EXIT_SUCCESS;
                        }
                }
        }
        
        //Check if stack empty
        //If not empty that means some braces are unbalanced
        if(isEmpty())
        {
                printf("The parentheses are valid!\n");
        }
        else
        {
                printf("The parentheses are invalid!\n");
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
                        printf("%c ", stack[i]);
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