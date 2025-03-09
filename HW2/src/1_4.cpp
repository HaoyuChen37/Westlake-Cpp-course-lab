#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

// int main(int argc, char **argv) {
//     int a = 5;
//     // int a = 3;
//     // int a = 7;
//     switch(a) {
//         case 3:
//             a++;
//         case 5:
//             a--;
//         default:
//             a = 0;
//     }
//     printf("The value of a is %d", a);
// }


int main(int argc, char **argv) {
    int j,k,sum1=0,sum2=0;
    for(k=1,j=5;k<=10;k++,j++){
        sum1+=k;
        sum2+=j;
    }
    printf("The values are %d, %d, %d, %d", j, k, sum1, sum2);
}