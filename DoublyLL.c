/*Doubly Linked List
1. creation
2. display
3. insertion
4. deletion
5. forward
6. backward
7. exit

struct 
sno - int (automatically)
name - 30 char[]
roll - int
branch - 3 char[]
section - 1 char[]
registration - long
city - 30 char[]
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sno;
    char name[30];
    int roll;
    char branch[3];
    char section[1];
    long registration;
    char city[30];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
int serialNum = 1;

struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sno = serialNum++;

    printf("Enter name: ");
    scanf("%s", newNode->name);

    printf("Enter roll: ");
    scanf("%d", &newNode->roll);

    printf("Enter branch: ");
    scanf("%s", &newNode->branch);

    printf("Enter section: ");
    scanf("%s", newNode->section);

    printf("Enter registration: ");
    scanf("%ld", &newNode->registration);

    printf("Enter city: ");
    scanf("%s", newNode->city);

    newNode->prev = newNode->next = NULL;
    return newNode;
} 

void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-5s %-30s %-10s %-5s %-5s %-15s %-30s\n", 
           "S.No", "Name", "Roll", "Branch", "Sec", "Reg. No", "City");
    printf("-----------------------------------------------------------------------------\n");

    while(temp != NULL) {
        printf("%-5d %-30s %-10d %-5s %-5s %-15ld %-30s\n", 
            temp->sno, temp->name, temp->roll, temp->branch, temp->section, 
            temp->registration, temp->city);
        temp = temp->next;
    }
}

void insertNode() {
    struct Node* newNode = createNode();
    if(head == NULL) {
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted.\n\n");
}

void deleteNode(int sno) {
    struct Node* temp = head;
    if(head == NULL) {
        printf("List is empty. \n");
        return;
    }

    while(temp!=NULL && temp->sno!=sno) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with S.No %d not found.\n", sno);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with S.No %d deleted successfully.\n", sno);
}

void displayForward() {
    struct Node* temp = head;
    char next;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (temp != NULL) {
        printf("\nSno: %d\n", temp->sno);
        printf("Name: %s\n", temp->name);
        printf("Roll: %d\n", temp->roll);
        printf("Branch: %s\n", temp->branch);
        printf("Section: %s\n", temp->section);
        printf("Registration: %ld\n", temp->registration);
        printf("City: %s\n", temp->city);
        
        if (temp->next != NULL) {
            printf("Press 'n' for next node or 'q' to quit: ");
            scanf(" %c", &next);
            if (next == 'q') break;
        }
        temp = temp->next;
    }
}

void displayBackward() {
    struct Node* temp = head;
    char next;
    
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;  
    }

    while (temp != NULL) {
        printf("\nSno: %d\n", temp->sno);
        printf("Name: %s\n", temp->name);
        printf("Roll: %d\n", temp->roll);
        printf("Branch: %s\n", temp->branch);
        printf("Section: %s\n", temp->section);
        printf("Registration: %ld\n", temp->registration);
        printf("City: %s\n", temp->city);
        
        if (temp->prev != NULL) {
            printf("Press 'p' for previous node or 'q' to quit: ");
            scanf(" %c", &next);
            if (next == 'q') break;
        }
        temp = temp->prev;
    }
}


int main() {
    int choice, sno;

    do {
        printf("Menu: \n");
        printf("1. Creation\n");
        printf("2. Display\n");
        printf("3. Insertion\n");
        printf("4. Deletion\n");
        printf("5. Forward\n");
        printf("6. Backward\n");
        printf("7. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertNode();
                break;
            
            case 2:
                displayList();
                break;
            
            case 3:
                insertNode();
                break;

            case 4:
                printf("Enter sno to delete: ");
                scanf("%d", &sno);
                deleteNode(sno);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7: 
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while(choice != 7);
}