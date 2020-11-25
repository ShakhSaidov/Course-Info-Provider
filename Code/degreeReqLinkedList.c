#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
 * list: linked list of degrees to be printed
 */
void printDegreeCourses(degreeReqLinkedList* list){
  RLNode* iter = list->head;
	while(iter != NULL) {
		printRequirements(iter->list);
		iter = iter->next;
	}
}

/*
 * Function: void removeCourseFromDegreeReq(degreeReqLinkedList* l, char* n)
 * --------------------
 * Removes the given course from the degree requirements list
 * l: degree requirements list
 * n: course name to be removed
 */
int removeCourseFromDegreeReq(degreeReqLinkedList* l, char* n){
  RLNode* iter1 = l->head;
  while(iter1 != NULL){
    RNode* iter2 = iter1->list->head;
    while(iter2 != NULL){
      char* nameToCompare = (char* )calloc(strlen(iter2->name) + 1, sizeof(char));
      if((iter2->name)[0] == 'O'){                          //if disjunct
        memcpy(nameToCompare, &((iter2->name)[3]), strlen(iter2->name)-2); 
      } else {
        memcpy(nameToCompare, &((iter2->name)[0]), strlen(iter2->name)); 
      }
      if(strcmp(nameToCompare, n) == 0){
        deleteNode(iter1->list, iter2->name);
        checkDisjunctCondition(iter1->list, "OR ");            //adds an OR if the first disjunct course out of many was removed
        removeEmptyNode(l);
        free(nameToCompare);
        return 1;
      }
      free(nameToCompare);
      iter2 = iter2->next;
    }
    iter1 = iter1->next;
  }
  return 0;
}

/*
 * Function:  removeEmptyNode(degreeReqLinkedList* list) 
 * --------------------
 * Deletes empty nodes from the list
 * list: linked list in focus
 */
void removeEmptyNode(degreeReqLinkedList* list){
  int count = 0;
  RLNode* current = list->head;           
  RLNode* previous = current;           
  while(current != NULL){       
    if(current->list->size == 0){      
      previous->next = current->next;
      if(current == list->head) list->head = current->next;
      freeRLNode(current);
      list->size--;  
      return;
    }                               
    previous = current;             
    current = current->next;
    count++;        
  }                               
} 

/*
 * Function: freeDegreeReqLinkedList(degreeReqLinkedList* list)
 * --------------------
 * Frees heap space used by the strings in list
 * list: linked list to be freed
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

/*
 * Function: freeRLNode(RNode* n)
 * --------------------
 * Frees heap space used by the node in list
 * n: node to be freed
 */
void freeRLNode(RLNode* n){
  freeReqLinkedList(n->list);
  free(n);
}