#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>


// 1.4
// int main(int argc, char **argv) {
  
//     char c = 'e';
//     int i = 127;
//     printf("Value of c is %c, value of i: %c\n", c, i);
//     printf("Value of c is %i, value of i: %i\n", c, i);

//     return 0;
// }


// 1.5
// int main(int argc, char **argv) {
  
//     unsigned char c = -1;
    
//     printf("Value of c is %c, value of c: %i\n", c, c);

//     return 0;
// }


// 1.6
// int main(int argc, char **argv) {
  
//     float a = 2e-60;
//     float b = 2e60;
    
//     printf("Value of a is %d, value of b: %d\n", a, b);

//     return 0;
// }


// 1.7-1.8
// int main(int argc, char **argv) {
  
//     int a = 5, b = 3, c = 7;
//     // float a = 5, b = 3, c = 7;
//     float ans1, ans2, ans3, ans4;
    
//     ans1 = (a-b)*c;
//     ans2 = a/b;
//     ans3 = b/a;
//     ans4 = a % b ;
    
//     printf("Value of ans1 is %f, value of ans2: %f, value of ans3: %f, value of ans4: %f\n", ans1, ans2, ans3, ans4);

//     return 0;
// }

// 1.12
// int main() {
//     int i = -2048;

//     // 第一个printf
//     printf("The value of is is %d", i);
//     printf("|\n");

//     // 第二个printf
//     printf("The value of is is %4d", i);
//     printf("|\n");

//     // 第三个printf
//     printf("The value of is is %6i", i);
//     printf("|\n");

//     // 第四个printf
//     printf("The value of is is %-6i", i);
//     printf("|\n");

//     return 0;
// }


// 1.14
// int main(int argc, char **argv) {
//     printf("This \t is \v a \b testing \n sentence.\n");

//     return 0;
// }


// 1.15
// int main() {
//     int a;
//     float b;
//     double c;

//     // Test %i
//     std::cout << "Enter an integer: ";
//     int result_i = scanf("%i", &a);
//     std::cout << "Return value of scanf(\"%i\", &a): " << result_i << std::endl;

//     // Test %f
//     std::cout << "Enter a float: ";
//     int result_f = scanf("%f", &b);
//     std::cout << "Return value of scanf(\"%f\", &b): " << result_f << std::endl;

//     // Test %lg
//     std::cout << "Enter a double: ";
//     int result_lg = scanf("%lg", &c);
//     std::cout << "Return value of scanf(\"%lg\", &c): " << result_lg << std::endl;

//     return 0;
// }


// 1.16
// int main() {
//     int c = 100;
//     putchar('a');
//     putchar(120);
//     putchar('\n');
//     putchar(c);
// }


// 1.17
// int main() {
//     int a[10];
//     a[1] = 100;
//     a[5] = 200;
//     a[7] = a[5] - a[1];
//     printf("a[1] = %d\n", a[1]);
//     printf("a[5] = %d\n", a[5]);
//     printf("a[7] = %d\n", a[7]);
//     return 0;
// }


// 1.18
int main() {
    struct Person {
        char Name[50] = {'X', 'H', 'D', 'X'};
        char Affiliation[50] = {'W', 'e', 's', 't', 'l', 'a', 'k', 'e', ' ', 'U', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'};
        int Age = 18;
        char Gender = 'M';
        double Weight = 75.9;
    };

    Person Person;

    printf("Name: %s\n", Person.Name);
    printf("Affiliation: %s\n", Person.Affiliation);
    printf("Age: %d\n", Person.Age);
    printf("Gender: %c\n", Person.Gender);
    printf("Weight: %f\n", Person.Weight);

    return 0;
}