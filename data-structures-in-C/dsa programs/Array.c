#include <stdio.h>
#include <stdlib.h>

int *getMatrix(int m, int n) {
    int *array = malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("Enter [%d][%d] Value: ", i, j);
            scanf(" %d", &array[i * n + j]);
        }
    return array;
}

int *add(int *a1, int *a2, int m, int n) {
    if (!a1 || !a2) return NULL;
    int *r = malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            r[i * n + j] = a1[i * n + j] + a2[i * n + j];
    return r;
}

int *subs(int *a1, int *a2, int m, int n) {
    if (!a1 || !a2) return NULL;
    int *r = malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            r[i * n + j] = a1[i * n + j] - a2[i * n + j];
    return r;
}

int *multiply(int *a1, int *a2, int m1, int n1, int n2) {
    if (!a1 || !a2) return NULL;
    int *r = calloc(m1 * n2, sizeof(int));
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n1; k++)
                r[i * n2 + j] += a1[i * n1 + k] * a2[k * n2 + j];
    return r;
}

void display(int *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("[ ");
        for (int j = 0; j < n; j++)
            printf("%d ", a[i * n + j]);
        printf("]\n");
    }
}

int main() {
    char o;
    int r, c, r1, c1, d;
    int *array = NULL, *a1 = NULL, *a2 = NULL;

    while (1) {
        printf("Enter Operation Your Choice (c for create, a for add, s for subtract, m for multiply, q to quit): ");
        scanf(" %c", &o);

        if (o == 'q') break;

        switch (o) {
        case 'c':
            printf("Enter Rows of the array: ");
            scanf(" %d", &r1);
            printf("Enter Columns of the array: ");
            scanf(" %d", &c1);
            array = getMatrix(r1, c1);
            break;

        case 'a':
            o = 'y';
            if (array) {
                printf("Do You Want to add a new Matrix with Existing one or Create both?(y/n): ");
                scanf(" %c", &o);
            }
            if (o == 'y' || o == 'Y') {
                printf("Enter Rows of the array: ");
                scanf(" %d", &r);
                printf("Enter Columns of the array: ");
                scanf(" %d", &c);

                printf("First Matrix: \n");
                a1 = getMatrix(r, c);
                printf("Second Matrix: \n");
                a2 = getMatrix(r, c);

                printf("Addition Result: \n");
                int *result = add(a1, a2, r, c);
                display(result, r, c);

                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result;
                    r1 = r;
                    c1 = c;
                } else {
                    free(result);
                }
            } else {
                if (!array) {
                    printf("No Existing Matrix To Use 'c' To create one\n");
                    break;
                }
                printf("Second Matrix: \n");
                a2 = getMatrix(r1, c1);
                printf("Existing Matrix: \n");
                display(array, r1, c1);
                printf("Second Matrix: \n");
                display(a2, r1, c1);
                int *result = add(a1, a2, r, c);
                printf("Addition Result: \n");
                display(result, r1, c1);

                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result;
                } else {
                    free(result);
                }
            }
            free(a1);
            free(a2);
            break;
        case 's':
            o = 'y';
            if (array) {
                printf("Do You Want to add a new Matrix with Existing one or Create both?(y/n): ");
                scanf(" %c", &o);
            }
            if (o == 'y' || o == 'Y') {
                printf("Enter Rows of the array: ");
                scanf(" %d", &r);
                printf("Enter Columns of the array: ");
                scanf(" %d", &c);

                printf("First Matrix: \n");
                a1 = getMatrix(r, c);
                printf("Second Matrix: \n");
                a2 = getMatrix(r, c);

                printf("Subtraction Result: \n");
                int *result = subs(a1, a2, r, c);
                display(result, r, c);

                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result;
                    r1 = r;
                    c1 = c;
                } else {
                    free(result);
                }
                free(a1);
                free(a2);
            } else {
                if (!array) {
                    printf("No Existing Matrix To Use 'c' To create one\n");
                    break;
                }
                printf("Second Matrix: \n");
                a2 = getMatrix(r1, c1);
                printf("Existing Matrix: \n");
                display(array, r1, c1);

                printf("Second Matrix: \n");
                display(a2, r1, c1);
                int *result = subs(a1, a2, r, c);
                printf("Subtraction Result: \n");
                display(result, r1, c1);

                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result;
                } else {
                    free(result);
                }
            }
            free(a1);
            free(a2);
            break;
        case 'm':
            o = 'y';
            if (array) {
                printf("Do You Want to add a new Matrix with Existing one or Create both?(y/n): ");
                scanf(" %c", &o);
            }
            if (o == 'y' || o == 'Y') {
                printf("Enter Rows of the array: ");
                scanf(" %d", &r);
                printf("Enter Columns of the Array 1/Rows of the Array 2: ");
                scanf(" %d", &c);
                printf("First Matrix: \n");
                a1 = getMatrix(r, c);
                display(a1, r, c);

                printf("Enter Columns of the array 2: ");
                scanf(" %d", &d);
                printf("Second Matrix: \n");
                a2 = getMatrix(c, d);
                display(a2, c, d);

                printf("Multiplication Result: \n");
                int *result = multiply(a1, a2, r, c, d);
                display(result, r, d);

                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result;
                    r1 = r;
                    c1 = d;
                } else {
                    free(result);
                }
                free(a1);
                free(a2);
            } else {
                if (!array) {
                    printf("No Existing Matrix To Use 'c' To create one\n");
                    break;
                }
                printf("Second Matrix: \n");
                printf("Enter Columns of the Array 2: ");
                scanf(" %d", &d);
                a2 = getMatrix(c1, d);

                printf("Existing Matrix: \n");
                display(array, r1, c1);
                printf("Second Matrix: \n");
                display(a2, c1, d);

                int *result = multiply(a1, a2, r1, c1, d);
                printf("Do You Update Existing One? (y/n): ");
                scanf(" %c", &o);
                if (o == 'y' || o == 'Y') {
                    printf("Ok..\n");
                    free(array);
                    array = result; c1 = d;
                } else {
                    free(result);
                }
            }
            free(a1);
            free(a2);
            break;
        default:
            printf("Invalid operation!. Try again.\n");
            break;
        }
    }
    free(array);
    return 0;
}