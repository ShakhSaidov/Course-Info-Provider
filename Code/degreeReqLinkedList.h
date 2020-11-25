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
 */
extern degreeReqLinkedList* createDegreeReqLinkedList();

/*
 * Function: insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l)
 * --------------------
 * list: linked list of degrees
 * l: linked list of course names
 */
extern void insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l);

 /*
 * Function: printDegreeCourses(degreeReqLinkedList* list)
 * --------------------
 * list: linked list of degrees to be printed
 */
extern void printDegreeCourses(degreeReqLinkedList* list);

/*
 * Function: int removeCourseFromDegreeReq(degreeReqLinkedList* l, char* n)
 * --------------------
 * l: degree requirements list
 * n: course name to be removed
 */
extern int removeCourseFromDegreeReq(degreeReqLinkedList* l, char* n);

/*
 * Function:  removeEmptyNode(degreeReqLinkedList* list) 
 * --------------------
 * list: linked list in focus
 */
extern void removeEmptyNode(degreeReqLinkedList* list);

/*
 * Function: freeDegreeReqLinkedList(degreeReqLinkedList* list)
 * --------------------
 * list: linked list to be freed
 */
extern void freeDegreeReqLinkedList(degreeReqLinkedList* list);

/*
 * Function: freeRLNode(RNode* n)
 * --------------------
 * n: node to be freed
 */
extern void freeRLNode(RLNode* n);

#endif 