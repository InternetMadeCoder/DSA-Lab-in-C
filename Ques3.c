// write a program to implement matrix addition and multiplication operations.

#include <stdio.h>

int main() {
    int ch;

    do {
        printf("1. Matrix Addition \n");
        printf("2. Matrix Multiplication \n");
        printf("3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int row, col;
                
                printf("Enter the size of the matrices: ");
                scanf("%d %d", &row, &col);
                
                int matrix1[row][col], matrix2[row][col], result[row][col];
                
                printf("Enter elements of the first matrix: \n");
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        scanf("%d", &matrix1[i][j]);
                    }
                }
                
                printf("Enter elements of the second matrix: \n");
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        scanf("%d", &matrix2[i][j]);
                    }
                }
                
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        result[i][j] = matrix1[i][j] + matrix2[i][j];
                    }
                }
                
                printf("Resultant matrix: \n");
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 2: {
                int row1, col1, row2, col2;
                
                printf("Enter the size of the first matrix: ");
                scanf("%d %d", &row1, &col1);
                
                printf("Enter the size of the second matrix: ");
                scanf("%d %d", &row2, &col2);
                
                if (col1 != row2) {
                    printf("Matrix multiplication is not possible.\n");
                    break;
                }

                int matrixA[row1][col1], matrixB[row2][col2], resultMult[row1][col2];
                
                printf("Enter elements of the first matrix: \n");
                for(int i = 0; i < row1; i++) {
                    for(int j = 0; j < col1; j++) {
                        scanf("%d", &matrixA[i][j]);
                    }
                }
                
                printf("Enter elements of the second matrix: \n");
                for(int i = 0; i < row2; i++) {
                    for(int j = 0; j < col2; j++) {
                        scanf("%d", &matrixB[i][j]);
                    }
                }
                
                for(int i = 0; i < row1; i++) {
                    for(int j = 0; j < col2; j++) {
                        resultMult[i][j] = 0;
                    }
                }
                
                for(int i = 0; i < row1; i++) {
                    for(int j = 0; j < col2; j++) {
                        for(int k = 0; k < col1; k++) {
                            resultMult[i][j] += matrixA[i][k] * matrixB[k][j];
                        }
                    }
                }
                
                printf("Resultant matrix: \n");
                for(int i = 0; i < row1; i++) {
                    for(int j = 0; j < col2; j++) {
                        printf("%d ", resultMult[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3:
                printf("Bye!\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 3);
}