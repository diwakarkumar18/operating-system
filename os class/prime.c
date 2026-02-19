#include <stdio.h>

int main() {
    int n, i;
    int flag = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 2; i < n; i++) {
        if(n % i == 0) {
            flag = 1;
            break;
        }
    }

    if(n <= 1) flag = 1;

    if(flag)
        printf("%d is not prime\n", n);
    else
        printf("%d is prime\n", n);

    return 0;
}