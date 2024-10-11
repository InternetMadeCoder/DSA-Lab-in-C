#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void create();
void insertAtEnd();
void insertAtPos();
void deleteNode();
void display();
void search();
void reverse();
void findMid();

int main() {
    int choice;
    
    do {
        printf("Menu :\n1. Creation\n2. Insertion\n3. Deletion\n4. Display\n5. Search\n6. Mid element\n7. Insert at position\n8. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                create();
                break;
            case 2: 
                insertAtEnd();
                break;
            case 3: 
                deleteNode();
                break;
            case 4: 
                display();
                break;
            case 5: 
                search();
                break;
            case 6: 
                findMid();
                break;
            case 7:
                insertAtPos();
                break;
            case 8: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 8);
    
    return 0;
}

void create() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed.\n\n");
    }
    
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    
    head = newNode;
    tail = newNode;
    newNode->next=newNode;
    
    printf("Linked list created.\n\n");
}

void insertAtEnd() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n\n");
    }
    
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    
    if(head==NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
    
    printf("Node inserted at end.\n\n");
}

void insertAtPos() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL) {
        printf("Memory allocation failed.\n\n");
    }
    
    int position;
    printf("Enter position and data: ");
    scanf("%d %d", &position, &newNode->data);
    
    if(position == 1) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } 
    else {
        struct Node *temp = head;
        for(int i=2; i<position && temp!=NULL; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted successfully.");
}

void deleteNode() {
    int position;
    printf("Enter position of element to delete: ");
    scanf("%d", &position);
    
    if(position==1) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        struct Node *p = head;
        for(int i=2; i<position && p!=NULL; i++) {
            p = p->next;
        }
        struct Node *q = p->next;
        p->next = q->next;
        free(q);
    }
    printf("Node deleted.\n\n");
}

void display() {
    struct Node *temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("\n");
}

void search() {
    if (head == NULL) {
        printf("List is empty.\n\n");
        return;
    }
    
    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    
    int position = 1;
    
    struct Node *temp = head;
    do {
        if (temp->data == element) {
            printf("Element %d found at position %d.\n\n", element, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);  
    
    printf("Element NOT found\n\n");
}


void findMid() {
    // Code for finding the middle element
    struct Node *slow = head, *fast = head;
    
    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Mid element is %d.\n\n", slow->data);
}