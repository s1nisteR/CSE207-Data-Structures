#include <stdio.h>
#include <stdlib.h>


//Our BST node will have a key and pointers to both left and right subtrees
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
} node;

//Utility function to create a new node
node* newNode(int key)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Utility function to find inorder successor
node* inorderSuccessor(node* root)
{
    node* current = root;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

//===========EXERCISE 1 - BST INSERT OPERATION==============
node* insert(node* t_node, int key)
{
    //If NULL then we can insert here
    if(t_node == NULL)
    {
        return newNode(key);
    }
    if(key < t_node->key) //otherwise if key is smaller than current node's value insert to left subtree
    {
        t_node->left = insert(t_node->left, key);
    }
    else if(key >= t_node->key) //otherwise insert to right subtree
    {
        t_node->right = insert(t_node->right, key);
    }
    return t_node;
}
//=================================================================

//==============EXERCISE 2 - BST SEARCH OPERATION==================
node* search(node* root, int t_key)
{
    if(root == NULL) //if NULL reached that means the key is not in the tree
    {
        return NULL;
    }
    if(root->key == t_key) //if the current node's value is equal to the key that means we've found the value hence return it
    {
        return root;
    }
    if(t_key < root->key)   //otherwise if value to be searched is less than current node's value, search in the left subtree
    {
        return search(root->left, t_key);
    }
    if(t_key > root->key)  //otherwise search in the right subtree
    {
        return search(root->right, t_key);
    }
}
//=============================================================

//==============EXERCISE 3 - BST Traversals====================
void inOrder(node* root)
{
    if(root != NULL) //Recursively go Left, Root, Right
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(node* root)
{
    if(root != NULL) //Recursively go Root, Left, Right
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node* root)
{
    if(root != NULL) //Recursively go Left, Right, Root
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
//======================================================

//=========EXERCISE 4 - DELETION OPERATION===============

node* delete(node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->key) //if less than current node's value, deletion should take place somewhere in left subtree
    {
        root->left = delete(root->left, key);
    }
    else if(key > root->key) //otherwise somewhere in right subtree
    {
        root->right = delete(root->right, key);
    }
    else //otherwise, the value was found, now perform deletion
    {
        if(root->left == NULL && root->right == NULL) //if leaf node, just remove it by setting to NULL
        {
            return NULL;
        }
        else if(root->left == NULL) //if it has one child, then make the child point to its predecessor
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) //same thing but for left child, since right child is NULL
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderSuccessor(root->right); //otherwise, find the inorderSuccessor
        root->key = temp->key;
        root->right = delete(root->right, temp->key); //replace accordingly

    }
    return root;
}
//========================================================================


//===========EXERCISE 5 - FINDING LARGEST AND SMALLEST ELEMENTS============
void smallestElement(node *root)
{
    //keep going left to find smallest value
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    printf("Smallest value is %d\n", root->key);
}

void largestElement(struct node *root)
{
    //keep going right to find largest value
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    printf("Largest value is %d", root->key);
}
//===============================================================

int main()
{
    //Driver code to test the functions above
    node* root = newNode(26);
    insert(root, 27);
    insert(root, 24);
    insert(root, 23);
    insert(root, 26);
    inOrder(root);
    printf("\n");
    root = delete(root, 27);
    if(search(root, 27) != NULL) //found
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found!\n");
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    smallestElement(root);
    largestElement(root);
    return 0;
}
