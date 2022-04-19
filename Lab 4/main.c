#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;


//function declarations
void enqueue(int data);
bool dequeue();
void printQueue();
node* copyQueue();
void compressString();
void stackToQueue();
void deleteAllNegativeIntegers();


int main()
{
    //Science is what we understand well enough to explain to a computer, Art is all the rest. - Donald Knuth
    //Write some awesome code here

    return 0;
}

void enqueue(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(front == NULL && rear == NULL) //if it is the very first node
    {
        newNode->next = NULL; //since this is the only node, it points to null
        front = newNode; //make front point to this first node
        rear = newNode;  //make rear also point to this first node since it is the only node that is present
    }
    else //other items present as well
    {
        newNode->next = rear->next; //make the new node point to the node that was pointed by the previous
        rear->next = newNode;       //make the previous node point to our new node to form a proper link between the nodes
        rear = newNode;             //finally make rear point to our new node
    }
}

bool dequeue()
{
    if(front == NULL && rear == NULL) //no element is present in the queue
    {
        printf("The queue is already empty!\n");
        return false;
    }
    else if(front == rear) //if only a single node is present
    {
        free(front);       //free the node pointed by front
        front = NULL;      //make front be null, since the queue is now empty
        rear = NULL;       //make rear be null as well, since the queue is now empty
    }
    else
    {
        node* pointToThis = front->next;    //front's next that will become the new front
        free(front);                 //delete that node
        front = pointToThis;                //finally make front point to this node
    }
    return true;
}

void printQueue()
{
    node* temp = (node*)malloc(sizeof(node));
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("The queue is empty!\n");
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




node* copyQueue()
{
    if(front == NULL && rear == NULL)
    {
        printf("Original Queue is Empty!\n");
        return NULL;
    }
    node* newFront = (node*)malloc(sizeof(node));
    node* newRear = (node*)malloc(sizeof(node));
    newFront = NULL;
    newRear = NULL;

    node* iterator = (node*)malloc(sizeof(node));
    iterator = front;
    while(iterator != NULL)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = iterator->data;
        if(newFront == NULL && newRear == NULL) //if it is the very first node
        {
            newNode->next = NULL; //since this is the only node, it points to null
            newFront = newNode; //make front point to this first node
            newRear = newNode;  //make rear also point to this first node since it is the only node that is present
        }
        else //other items present as well
        {
            newNode->next = newRear->next; //make the new node point to the node that was pointed by the previous
            newRear->next = newNode;       //make the previous node point to our new node to form a proper link between the nodes
            newRear = newNode;             //finally make rear point to our new node
        }

        iterator = iterator->next;
    }

    //Print function, remove later
    node* temp = (node*)malloc(sizeof(node));
    temp = newFront;
    if(newFront == NULL && newRear == NULL)
    {
        printf("The queue is empty!\n");
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");



    return newFront;
}


void compressString()
{
    char input[200];
    gets(input);
    if(strlen(input) == 0)
    {
        return;
    }
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] != ' ')
        {
            enqueue((int)input[i]);
        }
    }
    int i = 0;
    char output[200];
    output[i] = (char)front->data;
    while(dequeue() && front != NULL)
    {
        i++;
        output[i] = (char)front->data;
    }
    output[++i] = '\0';
    printf("%s", output);
}

//Our stack
int arr[100];
int stackPointer = -1;

void push(int data)
{
    arr[++stackPointer] = data;
}

int pop()
{
    int poppedValue = arr[stackPointer];
    stackPointer--;
    return poppedValue;
}
//=======================================
void stackToQueue()
{
    int n;
    int input;
    int output;
    printf("Enter number of values: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        push(input);
    }
    while(stackPointer != -1)
    {
        output = pop();
        enqueue(output);
    }
    printQueue();
}


void deleteAllNegativeIntegers()
{
    int n;
    int input;
    printf("Enter number of values: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if(input >= 0)
        {
            enqueue(input);
        }
    }
    printQueue();
}

