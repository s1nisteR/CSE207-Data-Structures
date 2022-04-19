//Lab 5

#include <stdio.h>

//Exercise 1
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

//Exercise 2
int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

//Exercise 3
double pow(int base, int exp)
{
    //base condition
    if(exp == 0)
    {
        return 1;
    }
    else if(exp < 0)
    {
        return 1 / pow(base, exp * -1);
    }
    else
    {
        return base * pow(base, exp - 1);
    }
}


//Exercise 4
void TowersOfHanoi(int n, char beg, char aux, char end)
{
    if(n == 0)
    {
        return;
    }
    else if(n == 1)
    {
        printf("%c -> %c\n", beg, end);
        return;
    }
    TowersOfHanoi(n - 1, beg, end, aux);
    printf("%c -> %c\n", beg, end);
    TowersOfHanoi(n - 1, aux, beg, end);
}

int main()
{

    //driver code for exercise 3
    int num, exp;
    printf("Input any number: ");
    scanf("%d", &num);
    printf("\nInput power: ");
    scanf("%d", &exp);
    printf("\nOutput: %d\n", (int)pow(num, exp));


    //driver code for exercise 4
    TowersOfHanoi(3, 'A', 'B', 'C');


    return 0;
}
