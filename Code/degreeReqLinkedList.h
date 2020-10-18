#ifndef DEGREE_REQ_LINKED_LIST_H
#define DEGREE_REQ_LINKED_LIST_H
#include "reqLinkedList.h"

typedef struct RLNode{
  reqLinkedList* list;
  struct RLNode* prev;
  struct RLNode* next;
} RLNode;        

typedef struct degreeReqLinkedList{
  RLNode* head;
  RLNode* tail;
  int size;
} degreeReqLinkedList;

/*
 * Function: createDegreeReqLinkedList
 * --------------------
 * Creates and initializes a linked list of degrees to be used by the caller
 * Returns: Linked List of Degrees
 */
extern degreeReqLinkedList* createDegreeReqLinkedList();

/*
 * Function: insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l)
 * --------------------
 * Inserts a string into the specified list
 * list: linked list of degrees
 * l: linked list of course names
 */
extern void insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l);

 /*
 * Function: printDegreeCourses(degreeReqLinkedList* list)
 * --------------------
 * Prints the course-names that are required for the degree
 * list: linked list
 */
extern void printDegreeCourses(degreeReqLinkedList* list);

/*
 * Function: freeDegreeReqLinkedList(degreeReqLinkedList* list)
 * --------------------
 * Frees heap space used by the strings in list
 * list: linked list
 */
extern void freeDegreeReqLinkedList(degreeReqLinkedList* list);

#endif 