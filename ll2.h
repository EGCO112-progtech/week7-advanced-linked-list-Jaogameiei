#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// self-referential structure
struct Node {
    struct Node *pPtr; // pointer to previous node
    int data; // student ID (รหัสนักเรียน)
    char name[50]; // student's name
    struct Node *nextPtr; // pointer to next node
}; // end structure Node

typedef struct Node LLnode; // synonym for struct Node
typedef LLnode *LLPtr; // synonym for LLnode*

// prototypes
int deletes(LLPtr *sPtr, int value);
int isEmpty(LLPtr sPtr);
void insert(LLPtr *sPtr, int value, char *name);
void printList(LLPtr currentPtr);
void printListR(LLPtr currentPtr);
void instructions(void);

// display program instructions to user
void instructions(void) {
    puts("Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to end.");
} // end function instructions

// insert a new value into the list in sorted order
void insert(LLPtr *sPtr, int value, char *name) {
    LLPtr newPtr; // pointer to new node
    LLPtr previousPtr; // pointer to previous node in list
    LLPtr currentPtr; // pointer to current node in list

    newPtr = (LLPtr) malloc(sizeof(LLnode)); // create node

    if (newPtr != NULL) { // is space available
        newPtr->data = value; // place value in node
        strcpy(newPtr->name, name); // copy the student's name
        newPtr->nextPtr = NULL; // node does not link to another node
        newPtr->pPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        } // end while

        // insert new node at beginning of list
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            if (*sPtr != NULL) { // if list is not empty
                (*sPtr)->pPtr = newPtr; // old first node's previous points to new node
            }
            *sPtr = newPtr;
        } // end if
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->pPtr = previousPtr;

            newPtr->nextPtr = currentPtr;
            if (currentPtr != NULL) { // if not inserting at the end
                currentPtr->pPtr = newPtr;
            }
        } // end else
    } else {
        printf("%d not inserted. No memory available.\n", value);
    } // end else
} // end function insert

// delete a list element
int deletes(LLPtr *sPtr, int value) {
    LLPtr previousPtr = NULL; // pointer to previous node in list
    LLPtr currentPtr = *sPtr; // pointer to current node in list
    LLPtr tempPtr; // temporary node pointer

    // Delete first node
    if (value == (*sPtr)->data) {
        tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        if (*sPtr != NULL) {
            (*sPtr)->pPtr = NULL;
        }
        free(tempPtr); // free the de-threaded node
        return value;
    } // end if

    // Find the node to delete
    while (currentPtr != NULL && currentPtr->data != value) {
        previousPtr = currentPtr; // walk to next node
        currentPtr = currentPtr->nextPtr; // ... next node
    }

    // Node with the given value is found
    if (currentPtr != NULL) {
        tempPtr = currentPtr;
        previousPtr->nextPtr = currentPtr->nextPtr;
        if (currentPtr->nextPtr != NULL) {
            currentPtr->nextPtr->pPtr = previousPtr;
        }
        free(tempPtr);
        return value;
    }

    // If value not found, return a value indicating failure
    return -1; // return -1 if value was not found
}

// check if the list is empty
int isEmpty(LLPtr sPtr) {
    return sPtr == NULL;
} // end function isEmpty

// print the list
void printList(LLPtr currentPtr) {
    // if list is empty
    if (isEmpty(currentPtr)) {
        puts("List is empty.");
    } else {
        puts("The list is:");
        
        // traverse the list
        while (currentPtr != NULL) {
            printf("%d %s --> ", currentPtr->data, currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}
// print the list in reverse
void printListR(LLPtr currentPtr) {
    // Traverse to the last node
    if (currentPtr == NULL) {
        printf("List is empty\n");
        return;
    }

    puts("List reverse is:");

    // Traverse to the last node
    while (currentPtr->nextPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }

    // Print in reverse order using the pPtr (previous pointer)
    while (currentPtr != NULL) {
        printf("%d %s --> ", currentPtr->data, currentPtr->name);
        currentPtr = currentPtr->pPtr;
    }

    printf("NULL\n");
}
