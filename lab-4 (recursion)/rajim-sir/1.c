// recursive function to sum till n number
#include<stdio.h>


int sum(int num) {
    if (num == 0) // base case
        return num;
    else // recursive case
        return num + sum(num - 1);
}

int main() {
    int num, result;

    printf("Enter the nth number: ");
    scanf("%d", &num);
    result = sum(num);   
    printf("Sum is: %d", result);

    return 0;
}