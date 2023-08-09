// sum of digits of a given number
#include<stdio.h>

int sum(int num) {
    if (num == 0) {
        return num;
    } else {
        return (num%10 + sum(num/10));
    }
}


int main() {
    int num, result;

    printf("Enter the number: ");
    scanf("%d", &num);
    result = sum(num);   
    printf("Sum of digits of %d is: %d", num, result);

    return 0;
}