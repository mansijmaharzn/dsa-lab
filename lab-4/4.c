// calculate gcd of two numnum2ers
#include<stdio.h>


int findGCD(int num1, int num2) {
    if (num2==0) {
        return num1;
    } else {
        return findGCD(num2, num1 % num2);
    }
}


int main() {
    int num1, num2;

    printf("Enter num1 and num2: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is: %d", num1, num2, findGCD(num1, num2));

    return 0;
}