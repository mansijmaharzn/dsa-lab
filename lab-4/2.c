// count digits of a number
#include<stdio.h>

int countNum(int num) {
    static int count= 0;
    if (num == 0) {
        return count;
    } else {
        count++;
        return  countNum(num/10);
    }    
}


int main() {
    int num, result;

    printf("Enter the number: ");
    scanf("%d", &num);
    result = countNum(num);   
    printf("Total digit present in %d is: %d", num, result);

    return 0;
}