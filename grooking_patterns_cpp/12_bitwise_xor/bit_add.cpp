#include <stdio.h>
void sum(int i, int j) {
	printf("The sum of the number is : ");
	while(j != 0) {
		int carry;
		carry = i & j;
		i = i^j;
		j = carry << 1;
	}
	printf("%d", i);
}

void main() {
	int i,j;
	printf("Enter the numbers : ");
	scanf("%d %d", &i, &j);
	sum(i, j);
	printf("\n");
}