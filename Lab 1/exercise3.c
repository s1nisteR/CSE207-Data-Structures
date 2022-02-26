//==========Written By Matthews Ankon Baroi==========//
//CSE207 - Section 5
//Lab 1

#include <stdio.h>
#include <stdlib.h>



int main()
{
        
        int choice;
        
        //Take user's choice of operation as input
        printf("Enter your choice:\n1 for addition\n2 for subtraction\n3 for multiplication\n");
        scanf("%d", &choice);
        
        int rowA, colA, rowB, colB;
        
        //Take the first matrix as input
        printf("Enter numbers of rows for first matrix: ");
        scanf("%d", &rowA);
        
        printf("\nEnter numbers of columns for first matrix: ");
        scanf("%d", &colA);
        int matA[rowA][colA];
        
        
        printf("Enter the first matrix: \n");
        for(int i = 0; i < rowA; i++)
        {
                for(int j = 0; j < colA; j++)
                {
                        scanf("%d", &matA[i][j]);
                }
                printf("\n");
        }
        
        
        //Take the second matrix as input
        printf("\nEnter numbers of rows for second matrix: ");
        scanf("%d", &rowB);
        
        printf("\nEnter numbers of columns for second matrix: ");
        scanf("%d", &colB);
        
        int matB[rowB][colB];
        
        printf("Enter the second matrix: \n");
        for(int i = 0; i < rowB; i++)
        {
                for(int j = 0; j < colB; j++)
                {
                        scanf("%d", &matB[i][j]);
                }
                printf("\n");
        }
        
        printf("You choose %d\n", choice);
        
        //Switch between user's choice of operation
        switch(choice)
        {
                case 1:       //Addition
                {
                        printf("Addition: \n");
                        //If dimension for both matrices is different then addition is not possible
                        if(rowA != rowB || colA != colB)
                        {
                                printf("Both matrices must be the same dimension for addition");
                                break;
                        }
                        int result[rowA][colA];
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colA; j++)
                                {
                                        result[i][j] = matA[i][j] + matB[i][j];
                                }
                        }
                        //display the resultant matrix
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colA; j++)
                                {
                                        printf("%d ", result[i][j]);
                                }
                                printf("\n");
                        }
                        break;
                }
                case 2:        //Subtraction
                {
                        printf("Subtraction: \n");
                        //If dimension for both matrices is different then subtraction is not possible
                        if(rowA != rowB || colA != colB)
                        {
                                printf("Both matrices must be the same dimension for subtraction");
                                break;
                        }
                        int result[rowA][colA];
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colA; j++)
                                {
                                        result[i][j] = matA[i][j] - matB[i][j];
                                }
                        }
                        //display the resultant matrix
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colA; j++)
                                {
                                        printf("%d ", result[i][j]);
                                }
                                printf("\n");
                        }
                        break;
                }
                case 3:        //Multiplication
                {
                        printf("Multiplication: \n");
                        //If number of columns of first matrix is not equal to number of rows of second matrix, then multiplication is not possible
                        if(colA != rowB)
                        {
                                printf("The number of columns of first matrix must be equal to number of rows of second matrix for multiplication");
                                break;
                        }
                        int result[rowA][colB];
                        int sum;
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colB; j++)
                                {
                                        sum = 0;
                                        for(int k = 0; k < colA; k++)
                                        {
                                                sum += matA[i][k] * matB[k][j];
                                        }
                                        result[i][j] = sum;
                                }
                        }
                        //display the resultant matrix
                        for(int i = 0; i < rowA; i++)
                        {
                                for(int j = 0; j < colA; j++)
                                {
                                        printf("%d ", result[i][j]);
                                }
                                printf("\n");
                        }
                        break;
                }
                default:
                printf("Invalid choice! Exiting...");
                break;
        }
        
        
        return EXIT_SUCCESS;
}
