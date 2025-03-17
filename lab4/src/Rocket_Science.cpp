#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>



// int main(int argc, char **argv) {  array直接是指针
//     int B[5] = {1, 2, 3, 4, 5};
//     printf("%d", B);
//     return 0;
// }

// #define N 3

// // Use an Auxiliary Matrix to Rotate Image
// void rotateMatrix(int img[N][N], int img_rotated[N][N]) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             img_rotated[j][N - 1 - i] = img[i][j];
//         }
//     }
// }

// int main(int argc, char **argv) {
//     int img[N][N], img_rotated[N][N];
//     printf("Please input the image: \n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             scanf("%d", &img[i][j]);
//         }
//     }
//     printf("The image is: \n %d %d %d \n %d %d %d \n %d %d %d \n", img[0][0], img[0][1], img[0][2], img[1][0], img[1][1], img[1][2], img[2][0], img[2][1], img[2][2]);

//     rotateMatrix(img, img_rotated);
//     printf("The rotated image is: \n %d %d %d \n %d %d %d \n %d %d %d \n", img_rotated[0][0], img_rotated[0][1], img_rotated[0][2], img_rotated[1][0], img_rotated[1][1], img_rotated[1][2], img_rotated[2][0], img_rotated[2][1], img_rotated[2][2]);

//     return 0;
// }

// In-place Matrix Rotation
// void rotateMatrix(int img[N][N]) {
//     int temp;
//     for (int i = 0; i < N / 2; i++) {
//         for (int j = i; j < N - 1 - i; j++) {
//             temp = img[i][j];
//             img[i][j] = img[N - 1 - j][i];
//             img[N - 1 - j][i] = img[N - 1 - i][N - 1 - j];
//             img[N - 1 - i][N - 1 - j] = img[j][N - 1 - i];
//             img[j][N - 1 - i] = temp;
//         }
//     }
// }

// int main(int argc, char **argv) {
//     int img[N][N];
//     printf("Please input the image: \n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             scanf("%d", &img[i][j]);
//         }
//     }
//     printf("The image is: \n %d %d %d \n %d %d %d \n %d %d %d \n", img[0][0], img[0][1], img[0][2], img[1][0], img[1][1], img[1][2], img[2][0], img[2][1], img[2][2]);

//     rotateMatrix(img);
//     printf("The rotated image is: \n %d %d %d \n %d %d %d \n %d %d %d \n", img[0][0], img[0][1], img[0][2], img[1][0], img[1][1], img[1][2], img[2][0], img[2][1], img[2][2]);
// }


// Arbitrary Size Matrix Rotation
void rotateMatrix(int *img, int size) {
    for (int layer = 0; layer < size / 2; layer++) {
        int first = layer;
        int last = size - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = img[first * size + i];
            img[first * size + i] = img[(last - offset) * size + first];
            img[(last - offset) * size + first] = img[last * size + last - offset];
            img[last * size + last - offset] = img[i * size + last];
            img[i * size + last] = top;
        }
    }
    
}

int main(int argc, char **argv) {
    int dynamicN;
    printf("Please input the size of the image: \n");
    scanf("%d", &dynamicN);
    int *img = (int *)malloc(dynamicN * dynamicN * sizeof(int));
    // int img[dynamicN][dynamicN];

    printf("Please input %dx%d image: \n" , dynamicN, dynamicN);
    for (int i = 0; i < dynamicN; i++) {
        for (int j = 0; j < dynamicN; j++) {
            scanf("%d", &img[i * dynamicN + j]);
        }
    }
    printf("The image is: \n");
    for (int i = 0; i < dynamicN; i++) {
        for (int j = 0; j < dynamicN; j++) {
            printf("%d ", img[i * dynamicN + j]);
        }
        printf("\n");
    }

    rotateMatrix((int *)img, dynamicN);
    printf("The rotated image is: \n");
    for (int i = 0; i < dynamicN; i++) {
        for (int j = 0; j < dynamicN; j++) {
            printf("%d ", img[i * dynamicN + j]);
        }
        printf("\n");
    }
    return 0;
}