#ifndef COURSE_H
#define COURSE_H
#include <stdio.h>
#include "reqLinkedList.h"

typedef struct Course{
  reqLinkedList* list;
  char* name;
  char* title;
} Course;    

/*
 * Function: createCourse()
 * --------------------
 * Creates a course to be used by the caller
 * Returns: a course with uninitialized contents
 */
extern Course* createCourse(); 

/*
 * Function: setCourseName(Course* c, char* n)
 * --------------------
 * Sets the given course's name with passed string
 * c: course in focus
 * n: name of course
 */
extern void setCourseName(Course* c, char* n);

/*
 * Function: setCourseTitle(Course* c, char* t)
 * --------------------
 * Sets the given course's title with passed string
 * c: course in focus
 * t: title of course
 */
extern void setCourseTitle(Course* c, char* t);

/*
 * Function: addReqListToCourse(reqLinkedList* l, Course* c, char* n)
 * --------------------
 * Adds a linked list of pre-requisited into passed course
 * l: linked list of pre-requisites
 * c: course in focus
 * n: file-line that lists pre-requisites
 */
extern void addReqListToCourse(reqLinkedList* l, Course* c, char* n);

/*
 * Function: printCourse(Course* c)
 * --------------------
 * Prints full course information 
 * c: course in focus
 */
extern void printCourse(Course* c);

/*
 * Function: printPrerequisites(Course* c)
 * --------------------
 * Prints the given course's pre-requisites only
 * c: course in focus
 */
extern void printPrerequisites(Course* c);

/*
 * Function: printCourseOnly(Course* c)
 * --------------------
 * Prints the given course's name only
 * c: course in focus
 */
extern void printCourseOnly(Course* c);

/*
 * Function: freeCourse(Course* c)
 * --------------------
 * Frees heap space used by course
 * c: course in focus
 */
extern void freeCourse(Course* c);

#endif 