#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function Prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int rows, int cols);
void multiplyMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols);

int main() {
    int choice;
    int m1[MAX][MAX], m2[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    while (1) {
        printf("\n=====================================\n");
        printf("     CodeAlpha: Matrix Operations    \n");
        printf("=====================================\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("\nExiting Matrix Operations Program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Addition
                printf("\nEnter rows and columns for the matrices: ");
                scanf("%d %d", &r1, &c1);
                
                printf("\n--- Input First Matrix ---\n");
                inputMatrix(m1, r1, c1);
                printf("\n--- Input Second Matrix ---\n");
                inputMatrix(m2, r1, c1);
                
                addMatrices(m1, m2, result, r1, c1);
                
                printf("\nResultant Matrix (Addition):\n");
                displayMatrix(result, r1, c1);
                break;

            case 2: // Multiplication
                printf("\nEnter rows and columns for First Matrix: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Second Matrix: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("\nError: Multiplication not possible! Columns of 1st matrix must equal rows of 2nd matrix.\n");
                } else {
                    printf("\n--- Input First Matrix ---\n");
                    inputMatrix(m1, r1, c1);
                    printf("\n--- Input Second Matrix ---\n");
                    inputMatrix(m2, r2, c2);
                    
                    multiplyMatrices(m1, m2, result, r1, c1, c2);
                    
                    printf("\nResultant Matrix (Multiplication):\n");
                    displayMatrix(result, r1, c2);
                }
                break;

            case 3: // Transpose
                printf("\nEnter rows and columns of the matrix: ");
                scanf("%d %d", &r1, &c1);
                
                printf("\n--- Input Matrix ---\n");
                inputMatrix(m1, r1, c1);
                
                transposeMatrix(m1, result, r1, c1);
                
                printf("\nResultant Transposed Matrix:\n");
                displayMatrix(result, c1, r1); // Note rows and cols are swapped
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to take matrix inputs
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Addition
void addMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    // Initialize results matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
        }
    }
    // Perform multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function for Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = matrix[i][j];
        }
    }
}