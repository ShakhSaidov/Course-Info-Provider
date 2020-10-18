#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "reqLinkedList.h"

/*
 * Function:  createReqLinkedList() 
 * --------------------
 * Creates and initializes a linked list of strings to be used by the caller
 * Returns: Linked List
 */
reqLinkedList* createReqLinkedList(){
  reqLinkedList* list = (reqLinkedList* )malloc(sizeof(reqLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

/*
 * Function:  insertReqLinkedList(reqLinkedList* list, char* n) 
 * --------------------
 * Inserts a string into the specified list
 * list: linked list
 * n: string name
 */
void insertReqLinkedList(reqLinkedList* l, char* n){
  RNode* node = (RNode* )malloc(sizeof(RNode));
  node->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  if(n[0] == 'O'){                                             //checking for special cases for name
    memcpy(node->name, &n[3], strlen(n) - 3);
  } else if(n[0] == ' '){
    memcpy(node->name, &n[1], strlen(n) - 1);
  } else{
    strcpy(node->name, n);
  }
  
  if(l->head == NULL){          
    node->prev = NULL;
    node->next = NULL;
    l->head = node;
  } else {
    RNode* iter = l->head;      
    while(iter->next != NULL) {
			iter = iter->next;           
	  }
	  iter->next = node;
	  node->prev = iter;
	  node->next = NULL;
	  l->tail = node;
  }
  
  l->size++;
}

/*
 * Function: existsInReqLinkedList(reqLinkedList* l, char* n) 
 * --------------------
 * Checks if a given string exists in the given linked list
 * l: linked list
 * n: string name
 * Returns: 1 if string found, 0 otherwise
 */
int existsInReqLinkedList(reqLinkedList* l, char* n){
  int found = 0;
  RNode* iter = l->head;
	while(iter != NULL) {
    if(strcmp(iter->name, n) == 0){
      found = 1;
      break;
    }
		iter = iter->next;
	}
  return found;
}


/*
 * Function: printRequirements(reqLinkedList* l) 
 * --------------------
 * Prints the content in the list as "Name1, Name2, Name3..."
 * l: linked list
 */
void printRequirements(reqLinkedList* l){
  RNode* iter = l->head;
	while(iter != NULL) {
		printf("%s",iter->name);
		iter = iter->next;
		  if(iter != NULL){     //printing the Reqs
		  printf(", ");
	  }
	}
  printf("\n");
}

/*
 * Function: freeReqLinkedList(reqLinkedList* l)
 * --------------------
 * Frees heap space used by the strings in list
 * l: linked list
 */
void freeReqLinkedList(reqLinkedList* l){
  RNode* iter = l->head;
  RNode* next;
	while(iter != NULL) {
    next = iter->next;
    free(iter->name);
		free(iter);
    iter = next;
  }
  free(l);
}