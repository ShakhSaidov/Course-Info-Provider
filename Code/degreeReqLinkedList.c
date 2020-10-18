#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "reqLinkedList.h"
#include "degreeReqLinkedList.h"

/*
 * Function: createDegreeReqLinkedList
 * --------------------
 * Creates and initializes a linked list of degrees to be used by the caller
 * Returns: Linked List of Degrees
 */
degreeReqLinkedList* createDegreeReqLinkedList(){
  degreeReqLinkedList* list = (degreeReqLinkedList* )malloc(sizeof(degreeReqLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

/*
 * Function: insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l)
 * --------------------
 * Inserts a string into the specified list
 * list: linked list of degrees
 * l: linked list of course names
 */
void insertDegreeReqLinkedList(degreeReqLinkedList* list, reqLinkedList* l){
  RLNode* node = (RLNode*) malloc(sizeof(RLNode));
  node->list = l;
  
  if(list->head == NULL){          
    node->prev = NULL;
    node->next = NULL;
    list->head = node;
  } else {
    RLNode* iter = list->head;     
    while(iter->next != NULL) {
			iter = iter->next;          
	  }
	  iter->next = node;
	  node->prev = iter;
	  node->next = NULL;
	  list->tail = node;
  }
  
  list->size++;
}

 /*
 * Function: printDegreeCourses(degreeReqLinkedList* list)
 * --------------------
 * Prints the course-names that are required for the degree
 * list: linked list
 */
void printDegreeCourses(degreeReqLinkedList* list){
  RLNode* iter = list->head;
	while(iter != NULL) {
		printRequirements(iter->list);
		iter = iter->next;
	}
}

/*
 * Function: freeDegreeReqLinkedList(degreeReqLinkedList* list)
 * --------------------
 * Frees heap space used by the strings in list
 * list: linked list
 */
void freeDegreeReqLinkedList(degreeReqLinkedList* list){
  RLNode* iter = list->head;
  RLNode* next;
	while(iter != NULL) {
    next = iter->next;
    freeReqLinkedList(iter->list);
		free(iter);
    iter = next;
  }
  free(list);
}