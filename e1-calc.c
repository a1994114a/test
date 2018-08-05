#include <stdio.h>

int add(int a, int b) {
    return a + b;        
}

int subtract(int a, int b) {
    return a - b;
}

int divide(int a, int b) {

    int result = 0;
    
    while(a >= b) {
        a = subtract(a, b);
        result = add(result, 1);
    }
    return result;
}

int multiply(int a, int b) {
    int result = 0;

    while(b > 0) {
        result = add(result, a);
        b = subtract(b, 1);
    }
    return result;
}

int factorial(int a) {
    if (a == 0) {
        return 1;
    }

    int result = 1;

    while(a > 0) {
        result = multiply(result, a);
        a = subtract(a,1);
    }
    return result;
}

int main() {
    int x = 4;
    int x_fact = factorial(x);

    printf("%d! = %d\n", x, x_fact);
    
    return 0;
}
