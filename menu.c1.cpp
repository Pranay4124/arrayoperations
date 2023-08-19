#include <stdio.h>

#define MAX_SIZE 1000 // Maximum size of the array

void display(int arr[], int n) {
    printf("Array Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n, int ELEM, int POS) {
    if (POS < 1 || POS > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= POS; i--) {
        arr[i] = arr[i - 1];
    }
    arr[POS - 1] = ELEM;
    (*n)++;
}

void delete(int arr[], int *n, int POS) {
    if (POS < 1 || POS > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = POS - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[MAX_SIZE];
    int n, choice, ELEM, POS;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &ELEM);
                printf("Enter position: ");
                scanf("%d", &POS);
                insert(arr, &n, ELEM, POS);
                break;

            case 3:
                printf("Enter position of element to delete: ");
                scanf("%d", &POS);
                delete(arr, &n, POS);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

