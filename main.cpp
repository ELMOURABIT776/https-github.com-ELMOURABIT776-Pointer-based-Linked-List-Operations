#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }


    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found!\n", data);
        return;
    }


     Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}


void printList( Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int num, value, deleteValue;


    printf("Enter the number of elements to insert in the linked list: ");
    scanf("%d", &num);


    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }


    printf("Linked List before deletion: ");
    printList(head);


    printf("Enter the value to delete from the linked list: ");
    scanf("%d", &deleteValue);


    deleteNode(&head, deleteValue);


    printf("Linked List after deletion: ");
    printList(head);


    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


