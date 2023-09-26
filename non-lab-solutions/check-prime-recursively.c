#include<stdio.h>


int isPrime(int n, int i) {
    // Base cases
    if (n <= 2) // 2 is a prime number and 1 is not a prime number
        return (n == 2) ? 1 : 0;

    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
 
    // Check for next divisor
    return isPrime(n, i + 1);
}


int main() {
    int n = 11;

    if (isPrime(n, 2))
        printf("Yes its a prime number!");

    else
        printf("No its not a prime number!");

    return 0;
}