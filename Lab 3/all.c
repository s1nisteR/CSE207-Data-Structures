#include<stdio.h>
#include<stdlib.h>

//Our Node Structure
struct node
{
        int val;
        struct node *next;
};
struct node *curr, *tail = NULL, *head = NULL;


//Helper function
void showValue()
{
        printf(":: Showing Values are stored ::\n");
        struct node *temp = head;
        while(temp != NULL){
                printf("%d  ", temp -> val);
                temp = temp -> next;
        }
        printf("\n");
}


//==================EXERCISE 2 - CREATE A LINKED LIST======================
void create()
{
        int i, n;
        printf("Enter how many node you want: ");
        scanf("%d", &n);
        printf("Enter node value what you want: ");
        for(i = 0; i < n; i++){
                curr = (struct node *) malloc(sizeof(struct node));
                scanf("%d", &(curr -> val));
                curr -> next = NULL;
                if(head == NULL){
                        head = curr;
                        tail = curr;
                } else{
                        tail -> next = curr;
                        tail = curr;
                }
        }
}
//===========================================================================

//=================EXERCISE 3 - INSERT NEW NODE AT BEGINNING==================
void insert_at_beginning()
{
        curr = (struct node *) malloc(sizeof(struct node));
        printf("Enter a new node value here: ");
        scanf("%d", &curr -> val);
        curr -> next = NULL;
        if(head == NULL){
                head = curr;
                tail = curr;
        } else{
                curr -> next = head;
                head = curr;
        }
}
//============================================================================


//======================EXERCISE 4 - INSERT NODE AT ANY POSITION===================
void insert_at_any_position()
{
        int posi, i;
        struct node *temp, *temp1;
        curr = (struct node *) malloc(sizeof(struct node));
        printf("Enter node position where you want to store value here: ");
        scanf("%d", &posi);
        printf("Enter new node value at position %d : ",posi);
        scanf("%d", &curr -> val);
        curr -> next = NULL;
        if(head == NULL){
                head = curr;
                tail = curr;
        } else{
                temp = head;
                for(i = 1; i <= posi-1; i++){
                        temp1 = temp;
                        temp = temp->next;
                }
                temp1 -> next = curr;
                curr -> next = temp;
        }
}
//===================================================================================


//=====================EXERCISE 5 - DELETE NODE FROM LAST POSITION(END)================
void delete_at_end()
{
        struct node *temp,*temp1;
        if(head!=NULL) {
                temp = head;
                while(temp->next!=NULL) {
                        temp1 = temp;
                        temp = temp->next;
                }
                temp1->next = NULL;
                free(temp);
        }
}
//======================================================================================


//=======================EXERCISE 6 - DELETE NODE FROM BEGINNING(FRONT)=================
void delete_at_beginning()
{
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
}
//=======================================================================================


//==================EXERCISE 7 - DELETE NODE FROM ANY POSITION===================
void delete_at_any_position()
{
        int posi, i, c=0;
        struct node *temp, *temp1;
        printf("Enter node position which one you want to remove: ");
        scanf("%d", &posi);
        if(head != NULL){
                temp = head;
                for(i = 1; i <= posi-1; i++){
                        temp1 = temp;
                        temp = temp->next;
                        c++;
                }
                if(c!=0){
                        temp1 -> next = temp -> next;
                        free(temp);
                }
        }
}
//==================================================================================


//=====================EXERCISE 8 - REVERSE A LINKED LIST============================
void reverse_list()
{
        struct node *prev = NULL, *curre = head, *next;
        while(curre!=NULL){
                next = curre->next;
                curre->next = prev;
                prev = curre;
                curre = next;
        }
        head = prev;
        printf("List has been reverse....\n");
}
//===================================================================================

//==================EXERCISE 9 - DELETE DUPLICATE DATA FROM LINKED LIST==============
void delete_any_duplicate_value()
{
        struct node *temp, *temp1, *dup;
        temp = head;
        while(temp!=NULL && temp->next!=NULL){
                temp1 = temp;
                while(temp1->next!=NULL){
                        if(temp->val == temp1->next->val){
                                dup = temp1->next;
                                temp1->next = temp1->next->next;
                                free(dup);
                        }
                        else{
                                temp1 = temp1->next;
                        }
                }
                temp = temp->next;
        }
        printf("All duplicate item has been deleted....\n");
}
//=====================================================================================


int main(){
        //======================EXERCISE 1 - CREATE A MENU====================================
        for(;;){
                printf("1. Create Linked List\n");
                printf("2. Show All Values\n");
                printf("3. Insert at the beginning\n");
                printf("4. Insert at any position\n");
                printf("5. Delete from last position\n");
                printf("6. Delete from beginning\n");
                printf("7. Delete at the any position\n");
                printf("8. Reverse the list\n");
                printf("9. Delete all duplicate values\n");
                printf("10. Exit\n");
                printf("\n");
                printf("Enter number between 1-12 here: ");
                int x;
                scanf("%d", &x);
                if(x==1){
                        create();
                }
                if(x==2){
                        showValue();
                }
                if(x==3){
                        insert_at_beginning();
                }
                if(x==4){
                        insert_at_any_position();
                }
                if(x==5){
                        delete_at_end();
                }
                if(x==6){
                        delete_at_beginning();
                }
                if(x==7){
                        delete_at_any_position();
                }
                if(x==8){
                        reverse_list();
                }
                if(x==9){
                        delete_any_duplicate_value();
                }
                if(x==10){
                        printf("\n");
                        break;
                }
        }
}
