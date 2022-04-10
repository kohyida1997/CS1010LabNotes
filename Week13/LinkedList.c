#include <stdio.h>
#include <stdlib.h>
#define INSERT 1
#define DELETE 2
#define DISPLAY_TRAIN 3
#define TERMINATE 4

struct cart {
    int capacity;
    struct cart *next;
};

struct cart *head;
void insertCart();
void deleteCart();
void displayTrain();

int main() {
    int commandID = 0;
    while (commandID != TERMINATE) {
        scanf("%d", &commandID);
        switch (commandID) {
        case INSERT:
            insertCart();
            break;
        case DELETE:
            deleteCart();
            break;
        case DISPLAY_TRAIN:
            displayTrain();
            break;
        case TERMINATE:
            break;
        default:
            printf("ERROR\n");
        }
    }
}

void insertCart() {
    struct cart *ptr, *temp;
    int item;
    ptr = (struct cart *)malloc(sizeof(struct cart));

    if (ptr == NULL) {
        printf("ERROR\n");
    } else {
        scanf("%d", &item);
        ptr->capacity = item;
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}

void deleteCart() {
    struct cart *ptr, *ptr1;
    if (head == NULL) {
        printf("EMPTY\n");
    } else if (head->next == NULL) {
        head = NULL;
        free(head);
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
}

void displayTrain()
{
    struct cart *ptr;
    ptr = head;
    if (ptr == NULL) {
        printf("EMPTY\n");
    }

    else {
        while (ptr != NULL) {
            printf("%d", ptr->capacity);
            ptr = ptr->next;
            if (ptr != NULL) {
                printf("->");
            } else {
                printf("\n");
            }
        }
    }
}
