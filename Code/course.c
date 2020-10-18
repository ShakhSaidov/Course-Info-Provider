#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "reqLinkedList.h"

/*
 * Function: createCourse()
 * --------------------
 * Creates a course to be used by the caller
 * Returns: a course with uninitialized contents
 */
Course* createCourse(){
  Course* c = (Course* )malloc(sizeof(Course));
  return c;
}

/*
 * Function: setCourseName(Course* c, char* n)
 * --------------------
 * Sets the given course's name with passed string
 * c: course in focus
 * n: name of course
 */
void setCourseName(Course* c, char* n){
  c->name = (char* )calloc(strlen(n) + 1, sizeof(char));   
  strcpy(c->name, n);
}

/*
 * Function: setCourseTitle(Course* c, char* t)
 * --------------------
 * Sets the given course's title with passed string
 * c: course in focus
 * t: title of course
 */
void setCourseTitle(Course* c, char* t){
  c->title = (char* )calloc(strlen(t) + 1, sizeof(char)); 
  strcpy(c->title, t);
}

/*
 * Function: addReqListToCourse(reqLinkedList* l, Course* c, char* n)
 * --------------------
 * Adds a linked list of pre-requisited into passed course
 * l: linked list of pre-requisites
 * c: course in focus
 * n: file-line that lists pre-requisites
 */
void addReqListToCourse(reqLinkedList* l, Course* c, char* n){
  char* token = strtok(n, ",");
  while(token != NULL){
    insertReqLinkedList(l, token);
    token = strtok(NULL, ",");
  }
  c->list = l;
  free(token);
}

/*
 * Function: printCourse(Course* c)
 * --------------------
 * Prints full course information 
 * c: course in focus
 */
void printCourse(Course* c){
  printf("%s", c->name);
  printf("%s", c->title);
  printRequirements(c->list);
  printf("\n");
}

/*
 * Function: printPrerequisites(Course* c)
 * --------------------
 * Prints the given course's pre-requisites only
 * c: course in focus
 */
void printPrerequisites(Course* c){
  printRequirements(c->list);
}

/*
 * Function: printCourseOnly(Course* c)
 * --------------------
 * Prints the given course's name only
 * c: course in focus
 */
void printCourseOnly(Course* c){
  printf("%s\n", c->name);
}

/*
 * Function: freeCourse(Course* c)
 * --------------------
 * Frees heap space used by course
 * c: course in focus
 */
void freeCourse(Course* c){
  freeReqLinkedList(c->list);
  free(c->name);
  free(c->title);
  free(c);
}