// to find the product of given two integer number
#include <stdio.h>


int multiply(int num1, int num2) {
    if (num2 == 0)
        return 0;
    else if (num2 > 0)
        return num1 + multiply(num1, num2 - 1);
    else
        return -multiply(num1, -num2);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Product: %d\n", multiply(num1, num2));

    return 0;
}
