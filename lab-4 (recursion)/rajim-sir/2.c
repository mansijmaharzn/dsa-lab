// count digits of a number
#include<stdio.h>
#include<math.h>

int countNum(int num) {
    if (num < 10) // base case
        return 1;
    else // recursive case
        return 1 + countNum(num / 10);
}


int main() {
    int num, result;

    printf("Enter the number: ");
    scanf("%d", &num);
    result = countNum(num);   
    printf("Total digit present in %d is: %d\n", num, result);

    return 0;
}