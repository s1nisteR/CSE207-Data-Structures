//==========SINGLY LINKED LIST==========//

#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
        int data;
        struct Node* next;
} Node;

//Linked List Traversal (and displaying)
void display(Node* head)
{
        int nodeNumber = 0;
        Node* current;
        current = head->next;
        while(current->next != NULL)
        {
                printf("Value of Node %d: %d\n", nodeNumber, current->data);
                current = current->next;
                nodeNumber++;
        }
        printf("\n");
}

//Insert at front
void insertFront(Node* head, Node* node)
{
        
        node->next = head->next;
        head->next = node;
}

//Insert after a node
void insert(Node* after, Node* node)
{
        node->next = after->next;
        after->next = node;
}


//Insert at back
void insertBack(Node* head, Node* node)
{
        Node* current = head->next;
        while(current->next->next != NULL)
        {
                current = current->next; 
        }
        node->next = current->next;
        current->next = node;
}


int main()
{
        
        Node* head = (Node*)malloc(sizeof(Node));
        Node* first = (Node*)malloc(sizeof(Node));
        Node* second = (Node*)malloc(sizeof(Node));
        Node* tail = (Node*)malloc(sizeof(Node));
        
        Node* SIP = (Node*)malloc(sizeof(Node));
        Node* Sami = (Node*)malloc(sizeof(Node));
        Node* Messiah = (Node*)malloc(sizeof(Node));
        
        head->next = first;
        first->data = 30;
        first->next = second;
        second->data = 40;
        second->next = Messiah;
        tail->next = NULL;
        
        SIP->data = 69;
        Sami->data = 420;
        Messiah->data = 1338;
        
        Messiah->next = SIP;
        SIP->next = Sami;
        Sami->next = tail;
        
        
        
        //Display the Linked List
        printf("Initial View: \n");
        display(head);
        
        //Add a new node to the front
        printf("New Node Added To The Front: \n");
        Node* front = (Node*)malloc(sizeof(Node));
        front->data = 42069;
        insertFront(head, front);
        display(head);
        
        
        //Add a new node after a node
        printf("New Node Added After Another Node: \n");
        Node* funny = (Node*)malloc(sizeof(Node));
        funny->data = 1234567890;
        insert(SIP, funny);
        display(head);
        
        
        //Add a new node to the back
        printf("New Node Added To The Back: \n");
        Node* end = (Node*)malloc(sizeof(Node));
        end->data = 1;
        insertBack(head, end);
        display(head);
        
        
        
        //free the resources
        free(head);
        free(tail);
        free(first);
        free(second);
        free(Sami);
        free(SIP);
        free(Messiah);
        free(front);
        free(funny);
        free(end);
        
        return EXIT_SUCCESS;
}


