#include <stdio.h>
#include "math_stuff.h"
#include <string.h>
#include "matrix_struct.h"

void displayMenucli(int number);
int getUserOption();
void clearScreen();
void createMtx(struct matrix* myMatrix, int* numberOfMatrices);
void displayMatrix(struct matrix myMatrix);
void displayAllMatrix(struct matrix myMatrix[], int number);
void sumMtx(struct matrix myMatrix[], int numberOfMatrices);

struct matrix myMatrix[100];
int numberOfMatrices = 0;

int homecli()
{
    clearScreen();
    while (1)
    {
        // clearScreen();
        int option;
        displayMenucli(numberOfMatrices);
        option = getUserOption();
        clearScreen();

        switch (option)
        {
        case 1:
            createMtx(&myMatrix[numberOfMatrices], &numberOfMatrices);
            break;
        case 2:

            break;

        case 3:
            displayAllMatrix(myMatrix, numberOfMatrices);
            break;
        case 4:
            clearScreen();
            sumMtx(myMatrix, numberOfMatrices);
            break;
        case 0:
            return 1;
        }
    }
}

void displayMenucli(int number)
{
    printf("---------------------\n");
    printf("3x3 Matrices Calculator\n\n");

    printf("[1] Create matrix\n");
    printf("[2] Change matrix\n");
    printf("[3] Display matrices\n");
    printf("[4] Sum of two matrices\n");
    printf("[0] Quit\n");
    printf("---------------------\n");
    printf("You have %i matrices.\n", number);
}

int getUserOption()
{
    int opt;
    do
    {
        printf("Option: ");
        if (scanf("%d", &opt) != 1) {
            // Clear the input buffer
            while(getchar() != '\n');
        }
    } while (opt != 2 && opt != 1 && opt != 3 && opt != 0 && opt != 4);
    return opt;
}

void clearScreen()
{
    printf("\033[2J\033[H");
}

void createMtx(struct matrix* myMatrix, int* numberOfMatrices)
{
    char input[100];

    while (1)
    {
        printf("Matrix entries in one line, seperate by a space character\nEntries: ");
        while (getchar() != '\n'); //clear input buffer

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d %d %d %d %d %d %d %d %d",
           &myMatrix->value[0][0], &myMatrix->value[0][1], &myMatrix->value[0][2],
           &myMatrix->value[1][0], &myMatrix->value[1][1], &myMatrix->value[1][2],
           &myMatrix->value[2][0], &myMatrix->value[2][1], &myMatrix->value[2][2]) == 9)
        {
            clearScreen();
            printf("Sucessfully created a matrix.\n");
            printf("Please give a name for your matrix: ");
            fgets(myMatrix->name, sizeof(myMatrix->name), stdin);
            myMatrix->name[strlen(myMatrix->name) - 1] = '\0';
            displayMatrix(*myMatrix);
            break;
        }
    }
    *numberOfMatrices += 1;
}

void displayMatrix(struct matrix myMatrix)

{
    for (int i = 0; i < 3; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", myMatrix.value[i][j]);
        }
        printf("]\n");
    }
}

void displayAllMatrix(struct matrix myMatrix[], int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("----------\n");
        displayMatrix(myMatrix[i]);
        printf("\"%s\"\n", myMatrix[i].name);
    }
}

void sumMtx(struct matrix myMatrix[], int numberOfMatrices)
{
    while(getchar() != '\n');
    printf("# Choose your first matrix to performe.\n");
    printf("# You have ");
    for (int i = 0; i < numberOfMatrices; i++)
    {
        printf("\"%s\" ", myMatrix[i].name );
    }
    printf("\n-> $ ");
    char firstMtxName[20], secondMtxName[20];
    int valid = 0;
    while (valid != 1)
    {
        valid = 0;
        fgets(firstMtxName, sizeof(firstMtxName), stdin);
        firstMtxName[strlen(firstMtxName) - 1] = '\0';
        // while(getchar() != '\n');
        for (int i = 0; i < numberOfMatrices; i++)
        {
            if (strcmp(firstMtxName, myMatrix[i].name) == 0)
            {
                valid = 1;
                break;
            }

        }
        // while(getchar() != '\n');
        if (valid != 1)
        {
            printf("# Wrong name. Do it again.\n-> $ ");
        }

    }
    printf("# You have chosen \"%s\". As the first array to perform addition.\n", firstMtxName);
    printf("# Choose your second matrix to performe.\n");
    printf("# You have ");
    for (int i = 0; i < numberOfMatrices; i++)
    {
        printf("\"%s\" ", myMatrix[i].name );
    }
    printf("\n-> $ ");
    // while(getchar() != '\n');
    valid = 0;
    while (valid != 1)
    {
        valid = 0;

        fgets(secondMtxName, sizeof(secondMtxName), stdin);
        secondMtxName[strlen(secondMtxName) - 1] = '\0';
        // while(getchar() != '\n');
        for (int i = 0; i < numberOfMatrices; i++)
        {
            if (strcmp(secondMtxName, myMatrix[i].name) == 0)
            {
                valid = 1;
                break;
            }

        }
        // while(getchar() != '\n');
        if (valid != 1)
        {
            printf("Wrong name. Do it again.\n-> $ ");
        }
    }
    printf("You have chosen \"%s\". As the second array to perform addition.\n", secondMtxName);
    struct matrix mtx1, mtx2;
    for (int i = 0; i < numberOfMatrices; i++)
    {
        if (strcmp(myMatrix[i].name, firstMtxName) == 0)
        {
            mtx1 = myMatrix[i];
        }
        if (strcmp(myMatrix[i].name, secondMtxName) == 0)
        {
            mtx2 = myMatrix[i];
        }
    }
    struct matrix sumMtx = sumOfTwoMatrices(mtx1, mtx2);
    displayMatrix(sumMtx);
}