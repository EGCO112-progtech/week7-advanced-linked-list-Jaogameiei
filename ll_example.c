// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "ll2.h"

int main(void) { 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // char entered by user
   int studentID; // student ID
   char studentName[50];

   instructions(); // display the menu
   printf("%s", "? ");
   scanf("%u", &choice);

   // loop while user does not choose 3
   while (choice != 3) { 
      switch (choice) { 
         case 1:
            printf("%s", "Enter student ID and name: ");
            scanf("%d %s", &studentID,studentName);
            insert(&startPtr, studentID, studentName);
            printList(startPtr);
            printListR(startPtr);
            break;
         case 2: // delete an element
            // if list is not empty
            if (!isEmpty(startPtr)) { 
               printf("%s", "Enter number to be deleted: ");
               scanf("%d", &item);

               // if character is found, remove it
               if (deletes(&startPtr, item)) { // remove item
                  printf("%d deleted.\n", item);
                  printList(startPtr);
                  printListR(startPtr);
               } else {
                  printf("%d not found.\n\n", item);
               } // end else
            } else {
               puts("List is empty.\n");
            } // end else
            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   } // end while

   /* Clear all nodes at the end of nodes */
   puts("End of run.");
} // end main
