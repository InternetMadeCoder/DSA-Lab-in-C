#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void create();
void insert();
void insertAtPos();
void deleteNode();
void display();
void search();
void reverse();
void findMid();

int main() {
    int choice;
    
    do {
        printf("Menu :\n1. Creation\n2. Insertion\n3. Deletion\n4. Display\n5. Search\n6. Reverse\n7. Mid element\n8. Insert at position\n9. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                create();
                break;
            case 2: 
                insert();
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
                reverse();
                break;
            case 7: 
                findMid();
                break;
            case 8:
                insertAtPos();
                break;
            case 9: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 9);
    
    return 0;
}

void create() {
    // Code for creating the Linked List
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    
    head = newNode;
    newNode->next = NULL;
    
    printf("Node created.\n\n");
}

void insert() {
    // Code for inserting a node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("memory allocation failed.\n");
    }
    
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    
    if(head==NULL) {
        head = newNode;
        newNode->next=NULL;
    } else {
        struct Node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    printf("Node inserted at end.");
}

void insertAtPos() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    
    int position, element;
    printf("Enter position and element: ");
    scanf("%d %d", &position, &element);
    
    newNode->data = element;
    
    if(position==1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        struct Node *temp=head;
        for(int i=2; i<position && temp!=NULL; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at %d position.\n\n", position);
}

void deleteNode() {
    // Code for deleting a node
    int position;
    printf("Enter position of the node to be deleted: ");
    scanf("%d", &position);
    
    if(position==1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    else{
        struct Node *p = head;
        for(int i=2; i<position && p!=NULL; i++) {
            p = p->next;
        } 
        struct Node *q = p->next;
        p->next = q->next;
        free(q);
    }
    printf("Node at position %d deleted \n\n", position);
}

void display() {
    // Code for displaying the circular linked list
    struct Node *temp = head;
    if(temp==NULL) {
        printf("Empty List\n");
        return;
    }
    while(temp!=NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search() {
    // Code for searching an element in the list
    if(head == NULL) {
        printf("Empty list.\n\n");
    }

    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);

    int position = 1;
    
    struct Node *temp=head;
    do {
        if(temp->data == element) {
            printf("Element found at %d position.\n\n", position);
            return;
        }
        temp = temp->next;
        position++;
    } while(temp!=NULL);
    
    printf("%d NOT FOUND\n\n");
}

void reverse() {
    // Code for reversing the circular linked list
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while(current!=NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list reversed. \n\n");
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