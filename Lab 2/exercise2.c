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

//Basically using pop() as a glorified isEmpty() function below, where pop() will fail only if the stack is empty
//Program could be modified to include an explicit isEmpty() function, which will be done for exercise 3 :)
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
                //if ( then push into stack
                if(input[i] == '(')
                {
                        push('(');
                }
                else if(input[i] == ')')
                {
                        //if can't pop that means extra ) is present, print required message then quit
                        if(!pop(&tmp))
                        {
                                printf("Closing parentheses not matched\n");
                                return EXIT_SUCCESS;
                        }
                }
        }
        
        //if success so far, try popping one more time
        //if we can pop means there is an extra ( present
        //print required message then exit
        if(pop(&tmp))
        {
                printf("Opening parentheses not end\n");
        }
        else     //otherwise everything is okay!
        {
                printf("Everything is okay!\n");
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