#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>



// 1.1-1.2
// int polynomial(int x){
//     return 2*pow(x,2) + 3*x + 1;
// }

// int main(int argc, char **argv) {
//     int x;
//     printf("Enter a number: ");
//     scanf("%d", &x);
//     int j = polynomial(x);
//     printf("The result is: ");
//     printf("%d", j);
//     return 0;
// }


// 1.3
// #define POLYNOMIAL(x) (1 + 3 * (x) + 2 * (x) * (x))

// int main(int argc, char **argv) {
//     int x;
//     printf("Enter a number: ");
//     scanf("%d", &x);
//     int j = POLYNOMIAL(x);
//     printf("The result is: ");
//     printf("%d", j);
//     return 0;
// }


// 1.4
// void replace(int *a, int *b){
//     *a = *a + *b;
// }

// int main(int argc, char **argv) {
//     int a = 5;
//     int b = 3;
//     replace(&a, &b);
//     printf("a: %d\n", a);
//     printf("b: %d\n", b);

//     return 0;
// }


// 1.5
// 函数：根据概率p随机打印"Hello!"或"Goodbye!"
// void printMessageWithProbability(float p) {
//     if (p <= 0.0 || p >= 1.0) {
//         fprintf(stderr, "Error: Probability p must be between 0 and 1.\n");
//         return;
//     }

//     // 生成一个随机数（0到1之间）
//     float randomValue = rand() / (float)RAND_MAX;

//     // 根据概率p决定输出
//     if (randomValue < p) {
//         printf("Hello!\n");
//     } else {
//         printf("Goodbye!\n");
//     }
// }

// int main() {
//     float p;

//     // 输入概率p
//     printf("Enter the probability p (0 < p < 1): ");
//     scanf("%f", &p);

//     // 调用函数，根据概率打印消息
//     printMessageWithProbability(p);

//     return 0;
// }


// 1.7
// /* with pointer */
// void clamp_with_pointer(double *x, double a, double b) {
//     double lower = (a < b) ? a : b;
//     double upper = (a < b) ? b : a;
    
//     if (*x < lower) {
//         *x = lower;
//     } else if (*x > upper) {
//         *x = upper;
//     }
// }

// /* without pointer */
// double clamp_without_pointer(double x, double a, double b) {
//     double lower = (a < b) ? a : b;
//     double upper = (a < b) ? b : a;
    
//     return (x < lower) ? lower : (x > upper) ? upper : x;
// }

// int main() {
//     double x, a, b;

//     // 输入x, a, b
//     printf("Enter x: ");
//     scanf("%lf", &x);
//     printf("Enter a: ");
//     scanf("%lf", &a);
//     printf("Enter b: ");
//     scanf("%lf", &b);

//     // 调用函数，修改x的值
//     clamp_with_pointer(&x, a, b);
//     printf("x (with pointer): %lf\n", x);

//     // 调用函数，不修改x的值
//     printf("x (without pointer): %lf\n", clamp_without_pointer(x, a, b));

//     return 0;
// }


// 1.8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUM_ROWS 10
#define CEILING 5
#define FLOOR -17

/* Function prototype */
void clamp(double *x, double a, double b) {
    double lower = (a < b) ? a : b;
    double upper = (a < b) ? b : a;
    
    if (*x < lower) {
        *x = lower;
    } else if (*x > upper) {
        *x = upper;
    }
}
void printTable(double a, double b, int n);
double poly(double x);  // Assumed polynomial from Problem 1

int main(void) {
    /* Declare variables for the lower and upper bound */
    double a, b;
    /* Get values from user */
    printf("Enter endpoints a and b (a < b):\n");
    scanf("%lf %lf", &a, &b);

    /* Clamp the user input endpoints into the range of [FLOOR, CEILING] */
    clamp(&a, FLOOR, CEILING);
    clamp(&b, FLOOR, CEILING);

    /* Set a random seed */
    srand(time(NULL));
    /* Print NUM_ROWS rows */
    /* For each row, print a random float in clamped range [a,b] and the polynomial result */
    printTable(a, b, NUM_ROWS);
    return 0;
}

void printTable(double a, double b, int n) {
    double lower = a < b ? a : b;
    double upper = a < b ? b : a;

    for (int i = 0; i < n; ++i) {
        double rand_ratio = (double)rand() / RAND_MAX;
        double random_num = lower + rand_ratio * (upper - lower);
        double result = poly(random_num);
        printf("%8.3f | %8.3f\n", random_num, result);
    }
}


double poly(double x) {
    return 2*pow(x,2) + 3*x + 1;
}