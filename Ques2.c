/*
write a menu drive program to perform the following array operations.
Create
Insertion
Deletion
Display
Search 
Exit 
*/

#include <stdio.h>

int main() {
    int size, array[size];
    int ch, position, element, found;

    do {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Array\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &size);
    
                printf("Enter the elements:\n");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &array[i]);
                }
                printf("Array created.\n");
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position : ");
                scanf("%d", &position);

                if (position < 1 || position > size + 1) {
                    printf("Invalid position.\n");
                    break;
                }
                for (int i = size; i >= position; i--) {
                    array[i] = array[i - 1];
                }
                array[position - 1] = element;
                size++;
                printf("Element inserted.\n");
                break;

            case 3:
                if (size == 0) {
                    printf("Error: Array is empty. No elements to delete.\n");
                    break;
                }
                printf("Enter the position of the element to delete: ");
                scanf("%d", &position);

                if (position < 1 || position > size) {
                    printf("Invalid position.\n");
                    break;
                }
                for (int i = position - 1; i < size - 1; i++) {
                    array[i] = array[i + 1];
                }
                size--;
                printf("Element deleted successfully.\n");
                break;

            case 4:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                if (size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter the element to search: ");
                scanf("%d", &element);
                found = 0;
                for (int i = 0; i < size; i++) {
                    if (array[i] == element) {
                        printf("Element found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Element not found.\n");
                }
                break;

            case 6:
                printf("Bye!\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 6);
}