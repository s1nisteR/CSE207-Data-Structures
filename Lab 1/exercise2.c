//==========Written By Matthews Ankon Baroi==========//
//CSE207 - Section 5
//Lab 1


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_SIZE 100 //assuming that the maximum number of elements that can be taken from output is 100

int main()
{
        int arr[MAX_SIZE]; 
        int n, input;
        
        int max1, max2, min1, min2, indexMax1, indexMin1;
        max1 = INT_MIN;
        max2 = INT_MIN;
        min1 = INT_MAX;
        min2 = INT_MAX;
        
        
        
        
        //We take the total number of elements
        printf("Enter total number of elements: ");
        scanf("%d", &n);
        
        //We input the elements into our array
        printf("\nEnter the elements: ");
        for(int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }
        
        
        //Run a loop to find indexes of the first maximum and first minimum
        for(int i = 0; i < n; i++)
        {
                if(arr[i] > max1)
                {
                        max1 = arr[i];
                        indexMax1 = i;
                }
                
                if(arr[i] < min1)
                {
                        min1 = arr[i];
                        indexMin1 = i;
                }
        }
        
        //Now we run a loop but ignore positions with the first maximum and first minimum
        //Doing this we find the second maximum and the second minimum
        for(int i = 0; i < n; i++)
        {
                if(arr[i] > max2 && i != indexMax1)
                {
                        max2 = arr[i];
                }
                if(arr[i] < min2 && i != indexMin1)
                {
                        min2 = arr[i];
                }
        }
        
        
        //And now we print the second maximum and second minimum
        printf("Second Maximum: %d\n", max2);
        printf("Second Minimum: %d\n", min2);
        
        
        
        
        return EXIT_SUCCESS;
}