#ifndef REQ_LINKED_LIST_H
#define REQ_LINKED_LIST_H

typedef struct RNode{
  char* name;
  struct RNode* prev;
  struct RNode* next;
} RNode;        

typedef struct reqLinkedList{
  RNode* head;
  RNode* tail;
  int size;
} reqLinkedList;

/*
 * Function:  createReqLinkedList() 
 * --------------------
 * Creates and initializes a linked list of strings to be used by the caller
 * Returns: Linked List of strings
 */
extern reqLinkedList* createReqLinkedList();

/*
 * Function:  insertReqLinkedList(reqLinkedList* list, char* n) 
 * --------------------
 * Inserts a string into the specified list
 * list: linked list
 * n: string name
 */
extern void insertReqLinkedList(reqLinkedList* l, char* n);

/*
 * Function: existsInReqLinkedList(reqLinkedList* l, char* n) 
 * --------------------
 * Checks if a given string exists in the given linked list
 * l: linked list
 * n: string name
 * Returns: 1 if string found, 0 otherwise
 */
extern int existsInReqLinkedList(reqLinkedList* l, char* n);

 /*
 * Function: printRequirements(reqLinkedList* l) 
 * --------------------
 * Prints the content in the list as "Name1, Name2, Name3..."
 * l: linked list
 */
extern void printRequirements(reqLinkedList* l);

/*
 * Function: freeReqLinkedList(reqLinkedList* l)
 * --------------------
 * Frees heap space used by the strings in list
 * l: linked list
 */
extern void freeReqLinkedList(reqLinkedList* l);

#endif 