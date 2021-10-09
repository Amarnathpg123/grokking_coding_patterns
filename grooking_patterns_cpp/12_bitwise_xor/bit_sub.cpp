#include <stdio.h>
void subs(int i, int j) {
    printf("The Subtraction of the number is : ");
    while(j != 0) {
        int borrow;
        borrow = (~i) & j;
        i = i^j;
        j = borrow << 1;
    }       
    printf("%d", i);
}

void main() {
    int i,j,k;
    printf("Enter the numbers : ");
    scanf("%d %d", &i, &j);
    subs(i, j);
    printf("\n");
}