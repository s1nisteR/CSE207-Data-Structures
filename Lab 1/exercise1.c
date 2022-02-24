#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a[100];
        int n, i, pos=-1, item;
        printf("Enter number of elements: "); //Number of elements to have in our array
        scanf("%d", &n);
        printf("Enter your data: ");
        
        //We take input here
        for(i = 0; i < n; i++)
        {
                scanf("%d", &a[i]);
        }
        
        //We print the original array here
        printf("Your array : ");
        for(i = 0; i < n; i++)
        {
                printf("%d\t", a[i]);
        }
        
        
        //==========Start of bubble sort==========//
        int temp, j;
        
        int numberOfSwaps = 0; //variable to hold the total number of swaps
        int numberOfPasses = 0; //variable to hold the total number of passes
        
        for(i = 0; i < n - 1; i++)
        {
                for(j = 0; j < n - 1 - i; j++)
                {
                        //For each pass we increment numberOfPasses by one
                        //A pass does not necessarily have to result in a swap
                        numberOfPasses++;
                        
                        if(a[j] > a[j+1])
                        {
                                //swapping here
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                                
                                //after each successful swap we increment numberOfSwaps by one
                                numberOfSwaps++;
                                
                        }
                }
        }
        //==========End of bubble sort==========//
        
        
        //Print the sorted arrray
        printf("\nYour array : ");
        for(i = 0; i < n; i++)
        {
                printf("%d\t", a[i]);
        }
        
        //Print the number of swaps and number of passes
        printf("\nTotal Number of Passes: %d\nTotal Number of Swaps: %d\n", numberOfPasses, numberOfSwaps);
        
        
        return EXIT_SUCCESS;
}