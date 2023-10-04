#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getMatrix(int **matrix, int rows, int columns);
void printMatrix(int **matrix, int rows, int columns);
void checkMatrix(int **matrix, int rows,int columns);


int main()
{
    int **matrix;
    int rows,columns;
    printf("%s","Please enter values of rows and columns for Square Matrix: ");
    scanf("%d%d",&rows,&columns);

    if(rows == columns)
    {
        matrix = (int**)malloc(rows * sizeof(int*));
        for(int i = 0; i < rows; i++)
        {
            matrix[i] = (int*)malloc(columns * sizeof(int));
        }
        getMatrix(matrix,rows,columns);
        printMatrix(matrix,rows,columns);
        checkMatrix(matrix,rows,columns);
    }
    else
    {
        while (rows != columns)
        {
            printf("%s","It must be square Matrix.\nPlease enter values of rows and columns for Square Matrix: ");
            scanf("%d%d",&rows,&columns);
        }
        matrix = (int**)malloc(rows * sizeof(int*));
        for(int i = 0; i < rows; i++)
        {
            matrix[i] = (int*)malloc(columns * sizeof(int));
        }
        getMatrix(matrix,rows,columns);
        printMatrix(matrix,rows,columns);
        checkMatrix(matrix,rows,columns);
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
}

void getMatrix(int **matrix, int rows, int columns)
{

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("Enter %d. row(s) %d. column(s): ",i+1,j+1);
            scanf(" %d",&matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int columns)
{

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void checkMatrix(int **matrix, int rows, int columns)
{
    bool isDiagonal = true;
    bool isSymmetric = true;


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            // checking if it is diagonal
            if((i != j) && matrix[i][j] != 0)
            {
            isDiagonal = false;
            break;
            }
        // checking if it is symmetric
            if((i != j) && matrix[i][j] != matrix[j][i])
            {
            isSymmetric = false;
            break;
            }
        }
    }
    if (isDiagonal && isSymmetric)
    {
        printf("Matrix is both symmetric and diagonal.\n");
    }
    else if (isDiagonal)
    {
        printf("Matrix is diagonal.\n");
    }
    else if (isSymmetric)
    {
        printf("Matrix is symmetric.\n");
    }
    else
    {
        printf("Matrix is neither symmetric nor diagonal.\n");
    }
}
