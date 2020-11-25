#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "reqLinkedList.h"

/*
 * Function:  createReqLinkedList() 
 * --------------------
 * Creates and initializes a linked list of strings to be used by the caller
 * Returns: a new Linked List
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
 * n: name to be added onto the list
 */
void insertReqLinkedList(reqLinkedList* l, char* n){
  RNode* node = (RNode* )malloc(sizeof(RNode));
  node->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  if(n[0] == ' '){
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
 * Function:  deleteNode(reqLinkedList* list, char* n) 
 * --------------------
 * Deletes a string into the specified list
 * list: linked list
 * n: name to be deleted from list
 */
void deleteNode(reqLinkedList* list, char* n){
  RNode* current = list->head;            
  RNode* previous = current;           
  while(current != NULL){           
    if(strcmp(current->name, n) == 0){      
      previous->next = current->next;
      if(current == list->head) list->head = current->next;
      freeRNode(current);
      list->size--;
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                   
} 

/*
 * Function: checkDisjunctCondition(reqLinkedList* l, char* or) 
 * --------------------
 * Checks if after a removal of a node, there is a disjunct course that is left alone. If so, fixes it and converts it to a single requirement
 * l: linked list
 * or: possibly a former disjunct course name that starts with 'OR ' 
 */
void checkDisjunctCondition(reqLinkedList* list, char* or){
  if(list->size == 1 && ((list->head->name)[0] == 'O')){
    char* newName1 = (char* )calloc(strlen(list->head->name), sizeof(char));
    memcpy(newName1, &((list->head->name)[3]), strlen(list->head->name)-2);   
    deleteNode(list, list->head->name);
    insertReqLinkedList(list, newName1);
    free(newName1);
  } else if (list->size >= 2 && (list->head->name)[0] != 'O'){
    char* newName2 = (char* )calloc(strlen(or) + strlen(list->head->name) + 1, sizeof(char));
    memcpy(newName2, &(or[0]), strlen(or));   
    strcat(newName2, list->head->name);
    replaceHeadNode(list, newName2);
    free(newName2);
  }
}

/*
 * Function:  replaceHeadNode(reqLinkedList* l, char* n) 
 * --------------------
 * Replaces the head node of the given list with a new node containing the passed string/name
 * l: linked list in focus
 * n: name to be given to new node
 */
void replaceHeadNode(reqLinkedList* l, char* n){
  RNode* newNode = (RNode* )malloc(sizeof(RNode));
  newNode->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  strcpy(newNode->name, n);
  
  RNode* temp = l->head;
  newNode->next = temp->next;
  l->head = newNode;
  freeRNode(temp);
}

/*
 * Function: existsInReqLinkedList(reqLinkedList* l, char* n) 
 * --------------------
 * Checks if a given string exists in the given linked list
 * l: linked list
 * n: name to be searched for in the list
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
 * l: linked list to be printed
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
 * Function: printRequirementsInNewLine(reqLinkedList* l) 
 * --------------------
 * Prints each content of the list in a new line
 * l: linked list to be printed
 */
void printRequirementsInNewLine(reqLinkedList* l){
  RNode* iter = l->head;
	while(iter != NULL) {
		printf("%s\n",iter->name);
		iter = iter->next;
	}
}

/*
 * Function: freeReqLinkedList(reqLinkedList* l)
 * --------------------
 * Frees heap space used by the strings in list
 * l: linked list to be freed
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

/*
 * Function: freeRNode(RNode* n)
 * --------------------
 * Frees heap space used by the node in list
 * n: node to be freed
 */
void freeRNode(RNode* n){
  free(n->name);
  free(n);
}