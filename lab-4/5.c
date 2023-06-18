// program to convert decimal to binary
#include<stdio.h>


int convertToBinary(int decimalNumber) {
    if (decimalNumber == 0)
        return 0;
    else
        return decimalNumber % 2 + 10 * convertToBinary(decimalNumber/2);
}


int main() {
    int decimalNumber;

    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    printf("%d in binary number is: %d", decimalNumber, convertToBinary(decimalNumber));
    
    return 0;
}