
// self-referential structure
struct Node {
   struct Node *pPtr; //pointer to next node
   int data; // each listNode contains a character
   struct Node *nextPtr; // pointer to next node
}; // end structure listNode

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode *LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr *sPtr, int value );
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value );
void printList( LLPtr currentPtr );
void printListR( LLPtr currentPtr );
void instructions( void );


// display program instructions to user
void instructions( void )
{
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr *sPtr, int value )
{
   LLPtr newPtr; // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node
      newPtr->pPtr =NULL;
    
       
      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if (previousPtr == NULL) {
         newPtr->nextPtr = *sPtr;
         if (*sPtr != NULL) {        // if list is not empty
             (*sPtr)->pPtr = newPtr;  // old first node's previous points to new node
         }
         *sPtr = newPtr;  
        
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->pPtr = previousPtr;
   
          
         newPtr->nextPtr = currentPtr;
         if (currentPtr != NULL) {    // if not inserting at the end
            currentPtr->pPtr = newPtr;
    
      } // end else
   } // end if
}else {
      printf( "%d not inserted. No memory available.\n", value );
   } // end else
} // end function insert

// delete a list element
int deletes(LLPtr *sPtr, int value) {
   LLPtr previousPtr = NULL; // pointer to previous node in list
   LLPtr currentPtr = *sPtr; // pointer to current node in list
   LLPtr tempPtr; // temporary node pointer

   // Delete first node
   if ( value == ( *sPtr )->data ) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      if(*sPtr != NULL){
         (*sPtr)->pPtr = NULL;
      }
      free( tempPtr ); // free the de-threaded node
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
      if(currentPtr->nextPtr != NULL){
         currentPtr->nextPtr->pPtr=previousPtr;
      }
      free(tempPtr);
      return value;
   }

   // If value not found, return a value indicating failure
   return -1; // return -1 if value was not found
}



int isEmpty( LLPtr sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr->nextPtr!= NULL ) {
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } // end while

      printf( "%d --> NULL\n",currentPtr->data );
       
   } // end else
} // end function printList
void printListR(LLPtr currentPtr)
{
    // Base case: if list is empty or we've reached the end
    if (currentPtr == NULL) {
        printf("List is empty\n");
        return;
    }
    else{
      puts("List reverse is:");
      while(currentPtr->nextPtr != NULL){
         currentPtr = currentPtr->nextPtr;
      }
      
      while(currentPtr != NULL){
         printf("%d -> ", currentPtr->data);
         currentPtr = currentPtr->pPtr;
      }
      printf("NULL\n");
    }
    
   }