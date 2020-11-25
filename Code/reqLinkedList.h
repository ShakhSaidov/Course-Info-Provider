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
 */
extern reqLinkedList* createReqLinkedList();

/*
 * Function:  insertReqLinkedList(reqLinkedList* list, char* n) 
 * --------------------
 * list: linked list
 * n: name to be added onto the list
 */
extern void insertReqLinkedList(reqLinkedList* l, char* n);

/*
 * Function:  deleteNode(reqLinkedList* list, char* n) 
 * --------------------
 * list: linked list
 * n: name to be deleted from list
 */
extern void deleteNode(reqLinkedList* list, char* n);

/*
 * Function: checkDisjunctCondition(reqLinkedList* l, char* or) 
 * --------------------
 * l: linked list
 * or: possibly a former disjunct course name that starts with 'OR ' 
 */
extern void checkDisjunctCondition(reqLinkedList* list, char* or);

/*
 * Function:  replaceHeadNode(reqLinkedList* l, char* n) 
 * --------------------
 * l: linked list in focus
 * n: name to be given to new node
 */
extern void replaceHeadNode(reqLinkedList* l, char* n);

/*
 * Function: existsInReqLinkedList(reqLinkedList* l, char* n) 
 * --------------------
 * l: linked list
 * n: name to be searched for in the list
 */
extern int existsInReqLinkedList(reqLinkedList* l, char* n);

 /*
 * Function: printRequirements(reqLinkedList* l) 
 * --------------------
 * l: linked list to be printed
 */
extern void printRequirements(reqLinkedList* l);

/*
 * Function: printRequirementsInNewLine(reqLinkedList* l) 
 * --------------------
 * l: linked list to be printed
 */
extern void printRequirementsInNewLine(reqLinkedList* l);


/*
 * Function: freeReqLinkedList(reqLinkedList* l)
 * --------------------
 * l: linked list to be freed
 */
extern void freeReqLinkedList(reqLinkedList* l);

/*
 * Function: freeRNode(RNode* n)
 * --------------------
 * n: node to be freed
 */
extern void freeRNode(RNode* n);

#endif 