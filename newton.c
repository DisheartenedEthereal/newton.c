#include <stdio.h>
#include <math.h>
#define CONSTANT_H 1e-6
double f(double x) {
    return x * x * x - 5 * x - 9;
}

double df(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

int main() {
    double x0, x1, epsilon, h = CONSTANT_H;
    int max_iterations, i;
    
    printf("Enter the initial guess x0: ");
    scanf("%lf", &x0);
    
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);
    
    
    for (i = 1; i <= max_iterations; i++) {
        x1 = x0 - f(x0) / df(x0, h);
        printf("Iteration %d: x%d = %.10lf\n", i, i, x1);
        if (fabs(x1 - x0) < epsilon) {
            printf("Converged to solution x = %.10lf after %d iterations.\n", x1, i);
            return 0;
        }
        x0 = x1;
    }
    
    printf("Failed to converge after %d iterations.\n", max_iterations);
    
    return 0;
}