#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reqLinkedList.h"
#include "degreeReqLinkedList.h"
#include "degree.h"


/*
 * Function: createDegree()
 * --------------------
 * Creates a Degree to be used by the caller
 * Returns: Degree
 */
Degree* createDegree(){
  Degree* d = (Degree* )malloc(sizeof(Degree));
  degreeReqLinkedList* list = createDegreeReqLinkedList();
  d->list = list;
  return d;
}

/*
 * Function: setDegreeName(Degree* d, char* n)
 * --------------------
 * Mallocs a space for a name and sets the name of the Degree 
 * d: degree in focus
 * n: name to be given to degree
 */
void setDegreeName(Degree* d, char* n){
  d->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  strcpy(d->name, n);
}

/*
 * Function: addDegreeNameToLinkedList(Degree* d, reqLinkedList* l)
 * --------------------
 * Adds a degree-name to a linked list
 * d: degree whose name will be added to list
 * l: linked list
 */
void addDegreeNameToLinkedList(Degree* d, reqLinkedList* l){
  int length = strlen(d->name);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &((d->name)[0]), length-1);                        //getting rid of the '\n' of the name
  insertReqLinkedList(l, name);
  free(name);
} 

/*
 * Function: addListToDegree(Degree* d, char* l)
 * --------------------
 * Adds a list of course-names to the given degree
 * d: degree in focus
 * l: line of course-names to be added to degree
 */
void addListToDegree(Degree* d, char* l){
  reqLinkedList* reqList = createReqLinkedList();
  char* token = strtok(l, ",");
  while(token != NULL){
    int length = strlen(token)-1;
    if(token[length] == '\n'){                        //getting rid of the '\n' of the name
      token[length] = 0;
      insertReqLinkedList(reqList, token);
    } else {
    insertReqLinkedList(reqList, token);
    }
    token = strtok(NULL, ",");
  }
  insertDegreeReqLinkedList(d->list, reqList);

  free(token);
}

/*
 * Function: readDegreeFile(FILE* f)
 * --------------------
 * Reads a 'degree.txt' file and stores the courses needed to get the degree 
 * f: file to be read
 * Returns: Degree with all information stored
 */
Degree* readDegreeFile(FILE* f){
  int fileLine = 1;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  
  Degree* d = createDegree();
  while ((read = getline(&line, &len, f)) != -1){            //reads line-by-line from file f
    if(strcmp(line, "\n") == 0) break;
    if(fileLine == 1){                                       //degree name
      setDegreeName(d, line);
    } else {
      addListToDegree(d, line);                              //course-names
    }
    fileLine++; 
  }
  free(line);
  return d;
}

/*
 * Function: findCourseInDegree(Degree* d, char* n)
 * --------------------
 * Looks if a given course-name is required by the degree
 * d: degree in focus
 * n: course name to be searched for
 * Returns: 1 if course-name is found, 0 otherwise
 */
int findCourseInDegree(Degree* d, char* n){
  int found = 0;
  RLNode* iter1 = d->list->head;      //course in degree list
  while(iter1 != NULL){
    RNode* iter2 = iter1->list->head;    //course in course list
    while(iter2 != NULL){
      char* courseName = (char* )calloc(strlen(iter2->name) + 1, sizeof(char));
      if((iter2->name)[0] == 'O'){                                          //if course is a disjunct
        memcpy(courseName, &((iter2->name)[3]), strlen(iter2->name) - 3);
      } else {
        strcpy(courseName, iter2->name);
      }
  
      if(strcmp(courseName, n) == 0){
        found = 1;
        free(courseName);
        break;
      } 
      iter2 = iter2->next;
      free(courseName);
    }
    if(found == 1){
      break;
    }
    iter1 = iter1->next; 
  }
  return found;
}

/*
 * Function: int removeCourseFromDegree(Degree* d, char* n)
 * --------------------
 * Removes the given course from the degree requirements
 * d: degree in focus
 * n: course name to be removed from degree
 */
int removeCourseFromDegree(Degree* d, char* n){
  return removeCourseFromDegreeReq(d->list, n);
}

/*
 * Function: printDegreeReq(Degree* d)
 * --------------------
 * Prints the course-names that are required for the degree line-by-line
 * d: degree to be printed
 */
void printDegreeReq(Degree* d){
  printDegreeCourses(d->list);
}

/*
 * Function: printDegree(Degree* d)
 * --------------------
 * Prints the full degree information
 * d: degree to be printed
 */
void printDegree(Degree* d){
  printf("%s", d->name);
  printDegreeCourses(d->list);
  printf("\n");
}

/*
 * Function: printDegreeName(Degree* d)
 * --------------------
 * Prints only the degree name
 * d: degree to be printed
 */
void printDegreeName(Degree* d){
  printf("%s", d->name);
}

/*
 * Function: freeDegree(Degree* d)
 * --------------------
 * Frees the heap space used by a given degree
 * d: degree to be freed
 */
void freeDegree(Degree* d){
  freeDegreeReqLinkedList(d->list);
  free(d->name);
  free(d);
}