#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



// IMPORTANT NOTICE: After writing your answers in the following functions, don't forget to DELETE ORIGINAL RETURN 0 CODES!

//----------Problem 1: Enter an integer, convert it to the Roman number----------
    // Declaration of the variables.
    // Input: 
    // num: Integer. The number from user input.
    // Output: 
    // roman: char* (char pointer). A pointer which points towards the converted roman number.
    // Your function intToRoman is expected to return a char(string), which is the converted Roman number of input integer.
char* intToRoman(int num) {
    //Please write the codes of your solution here
    int size = 0;
    int temp = num;
    while (temp > 0)
    {
        if ((temp - 1000) >= 0){
            temp -= 1000;
            size += 1;
        }
        else if ((temp - 900) >= 0){
            temp -= 900;
            size += 2;
            
        }
        else if ((temp - 500) >= 0){
            temp -= 500;
            size += 1;
            
        }
        else if ((temp - 400) >= 0){
            temp -= 400;
            size += 2;
            
        }
        else if ((temp - 100) >= 0){
            temp -= 100;
            size += 1;
            
        }
        else if ((temp - 90) >= 0){
            temp -= 90;
            size += 2;
           
        }
        else if ((temp - 50) >= 0){
            temp -= 50;
            size += 1;
            
        }
        else if ((temp - 40) >= 0){
            temp -= 40;
            size += 2;
           
        }
        else if ((temp - 10) >= 0){
            temp -= 10;
            size += 1;
            
        }
        else if ((temp - 9) >= 0){
            temp -= 9;
            size += 2;
            
        }
        else if ((temp - 5) >= 0){
            temp -= 5;
            size += 1;
           
        }
        else if ((temp - 4) >= 0){
            temp -= 4;
            size += 2;
            
        }
        else if ((temp - 1) >= 0){
            temp -= 1;
            size += 1;
        }
    }
    char* roman = (char*)malloc((size + 1) * sizeof(char));
    int i = 0;
    while (num > 0)
    {
        if ((num - 1000) >= 0){
            num -= 1000;
            roman[i] = 'M';
            i++;
        }
        else if ((num - 900) >= 0){
            num -= 900;
            roman[i] = 'C';
            roman[i+1] = 'M';
            i += 2;
        }
        else if ((num - 500) >= 0){
            num -= 500;
            roman[i] = 'D';
            i++;
        }
        else if ((num - 400) >= 0){
            num -= 400;
            roman[i] = 'C';
            roman[i+1] = 'D';
            i += 2;
        }
        else if ((num - 100) >= 0){
            num -= 100;
            roman[i] = 'C';
            i++;
        }
        else if ((num - 90) >= 0){
            num -= 90;
            roman[i] = 'X';
            roman[i+1] = 'C';
            i += 2;
        }
        else if ((num - 50) >= 0){
            num -= 50;
            roman[i] = 'L';
            i++;
        }
        else if ((num - 40) >= 0){
            num -= 40;
            roman[i] = 'X';
            roman[i+1] = 'L';
            i += 2;
        }
        else if ((num - 10) >= 0){
            num -= 10;
            roman[i] = 'X';
            i++;
        }
        else if ((num - 9) >= 0){
            num -= 9;
            roman[i] = 'I';
            roman[i+1] = 'X';
            i += 2;
        }
        else if ((num - 5) >= 0){
            num -= 5;
            roman[i] = 'V';
            i++;
        }
        else if ((num - 4) >= 0){
            num -= 4;
            roman[i] = 'I';
            roman[i+1] = 'V';
            i += 2;
        }
        else if ((num - 1) >= 0){
            num -= 1;
            roman[i] = 'I';
            i += 1;
    }
}
    roman[size] = '\0';
    return roman;
}

//----------Problem 2(a): Enter an N*N matrix, return all N*N elements within the matrix in spiral order.----------
    // Declaration of the variables.
    // Input:
    // matrix: int**. Input matrix (in the pointer manner, which actually represents the starting address of the input matrix.)
    // N: Integer. Matrix size
    // Output:
    // order: int* (integer pointer). A pointer which points towards an integer array, which is the elements in the N*N matrix in the spiral order.
    // Your function spiralOrder is expected to return all of the N*N elements within the input N*N matrix in the spiral order.
    // HINT: You can divide the N*N matrix into LAYERS and access the elements in each layer in clockwise direction!
    int* spiralOrder(int** matrix, int N) {
        //Please write the codes of your solution here
        int* order = (int*)malloc(N * N * sizeof(int));

        int top = 0;
        int bottom = N - 1;
        int left = 0;
        int right = N - 1;
        int index = 0;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                order[index] = matrix[top][i];
                index++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                order[index] = matrix[i][right];
                index++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    order[index] = matrix[bottom][i];
                    index++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    order[index] = matrix[i][left];
                    index++;
                }
                left++;
            }
        }
        return order;
    }

//----------Problem 2(b): Given an integer N, create an N*N matrix with N*N consecutive numbers in spiral order.----------
    // Declaration of the variables.
    // Input:
    // N: Integer. Matrix size
    // Output:
    // matrix: int**. A pointer which points towards the matrix, in which the N*N consecutive numbers (from 1 to N*N) are placed in spiral order.
    // Your function generateMatrix is expected to return an N*N matrix in which the N*N consecutive numbers (from 1 to N*N) are placed in spiral order.
    // HINT: You can divide the N*N matrix into LAYERS and access the elements in each layer in clockwise direction!
    int** generateMatrix(int N) {
        //Please write the codes of your solution here
        int** matrix = (int**)malloc(N * sizeof(int*));
        for (int i = 0; i < N; i++) {
            matrix[i] = (int*)malloc(N * sizeof(int));
        }

        int top = 0;
        int bottom = N - 1;
        int left = 0;
        int right = N - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }
        return matrix;
    }
    
    

int main() {
  
    // Declare variables
    int num;

    //Problem 1: Let user input another integer, convert it to the Roman number.
    printf("Please enter the integer you would like to convert to Roman number: \n");
    scanf("%d", &num);
    
    char* roman = intToRoman(num);
    printf("The converted Roman number is: %s\n", roman);

    // Problem 2(a): Let user input the matrix size N, then let user input all elements in the N*N matrix, returns the matrix elements in spiral order.
    int N1;
    printf("\nPlease enter the size N of the designated matrix: ");
    scanf("%d", &N1);

    int** matrix = (int **)malloc(N1 * N1 * sizeof(int));
    for (int i = 0; i < N1; i++) {
        matrix[i] = (int*)malloc(N1 * sizeof(int));
    }

    printf("Please enter %dx%d matrix elements. \n", N1, N1);
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N1; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int* result = spiralOrder(matrix, N1);

    printf("The matrix elements in spiral order is: \n");
    for (int i = 0; i < N1 * N1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Problem 2(b): Let user input an integer N, then returns an N*N matrix in which the N*N consecutive numbers (from 1 to N*N) are placed in the spiral order.
    int N2;  
    printf("\nPlease enter the size N of the designated matrix: \n");
    scanf("%d", &N2);
    int** matrix2 = generateMatrix(N2);  

    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;
}