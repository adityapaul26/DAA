#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int arr[SIZE];
int f = -1;
int r = -1;

// Display Queue
void displayQueue() {
    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("[");
    if (r >= f) {
        for (int i = f; i <= r; i++)
            printf("%d, ", arr[i]);
    } else {
        for (int i = f; i < SIZE; i++)
            printf("%d, ", arr[i]);
        for (int i = 0; i <= r; i++)
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

// All enQueue Operations:
void enQueueR(int key) {
    if (((r == SIZE - 1) && (!f)) || r == f - 1) {
        printf("Overflow!\n");
        return;
    }
    if (f == r && f == -1) {
        f = r = 0; arr[r] = key;
        return;
    }
    if (r == SIZE - 1 && f) {
        arr[r = 0] = key;
        return;
    }
    arr[++r] = key;
}

void enQueueF(int key) {
    if (((r == SIZE - 1) && (!f)) || r + 1 == f) {
        printf("Overflow!\n");
        return;
    }
    if (f == r && f == -1) {
        f = r = 0;
        arr[f] = key;
        return;
    }
    if (!f && r != SIZE - 1) {
        arr[f = SIZE - 1] = key;
        return;
    }
    arr[--f] = key;
}

// All deQueue Operations:
void deQueueF() {
    if ((f == r && f == -1)) {
        printf("Underflow!\n");
        return;
    }
    if (f == r)
        f = r = -1;
    else if (f == SIZE - 1)
        f = 0;
    else
        f++;
}

void deQueueR() {
    if (f == -1) {
        printf("Underflow!\n");
        return;
    }

    if (f == r)
        f = r = -1;
    else if (r == 0)
        r = SIZE - 1;
    else
        r--;
}

int getVal() {
    int c;
	printf("Enter Value: ");
    scanf("%d", &c);
    return c;
}

void memFree() {
	f = r = -1;
}

int main() {
    char ch;

    while (1) {
        printf("Double Ended Queue:\n\t1. Input Restricted DEQueue (use 'i')\n\t2. Output Restricted DEQueue (use 'o')\n\t3. To Reset Use 'r'\n\t4. To Reset Use any key\n");
        printf("Enter Your Choice (Double Ended Queue): ");
        scanf(" %c", &ch);

        if (ch == 'i') {
            printf("Input Restricted DEQueue.\n");
            printf("\t1.'e' to use enQueue (in the rear)\n\t2.'f' to use deQueue from front\n\t3.'r' to use deQueue in rear\n\t4.'d' to show Queue\n\t5.'x' to clear screen\n\t6.'q' to back\n");
            while (1) {
                printf("Enter Your Choice (Input Restricted DEQueue): ");
                scanf(" %c", &ch);
                switch (ch) {
                    case 'e':
                        enQueueR(getVal());
                        break;
                    case 'f':
                        deQueueF();
                        break;
                    case 'r':
                        deQueueR();
                        break;
                    case 'd':
                        displayQueue();
                        break;
					case 'x':
						system("cls");
						printf("\t1.'e' to use enQueue (in the rear)\n\t2.'f' to use deQueue from front\n\t3.'r' to use deQueue in rear\n\t4.'d' to show Queue\n\t5.'x' to clear screen\n\t6.'q' to back\n");
						break;
					case 'q':
                        printf("Back To Previous Menu...\n");
                        break;
                    default:
                        printf("Invalid Operation!\n");
                        break;
                }
                if (ch == 'q') break;
            }
        } else if (ch == 'o') {
            printf("Output Restricted DEQueue.\n");
			printf("\t1.'e' to use deQueue (in the front)\n\t2.'f' to use enQueue from front\n\t3.'r' to use enQueue in rear\n\t4.'d' to show Queue\n\t5.'x' to clear screen\n\t6.'q' to back\n");
			while (1) {
                printf("Enter Your Choice (Output Restricted DEQueue): ");
                scanf(" %c", &ch);
                switch (ch) {
                    case 'e':
                        deQueueF();
                        break;
                    case 'f':
                        enQueueF(getVal());
                        break;
                    case 'r':
                        enQueueR(getVal());
                        break;
                    case 'd':
                        displayQueue();
                        break;
					case 'x':
						system("cls");
            			printf("\t1.'e' to use deQueue (in the front)\n\t2.'f' to use enQueue from front\n\t3.'r' to use enQueue in rear\n\t4.'d' to show Queue\n\t5.'q' to back\n");
						break;
					case 'q':
						printf("Back To Previous Menu...\n");
                        break;
                    default:
                        printf("Invalid Operation!\n");
                        break;
                }
                if (ch == 'q') break;
            }
        } else if (ch == 'r') {
            memFree();
            printf("Reset....!\n");
        } else {
            printf("Exiting....\n");
            break;
        }
    }

    return 0;
}