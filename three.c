//time complexity of o(n^2)
//  ch.sc.u4aie25003


#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter a small integer (e.g., 5 to 30): ");
    scanf("%d", &n);

    int result = fibonacci(n);
    printf("Fibonacci result: %d\n", result);

    return 0;
}