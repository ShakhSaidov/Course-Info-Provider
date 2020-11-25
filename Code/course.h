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
 */
extern Course* createCourse(); 

/*
 * Function: setCourseName(Course* c, char* n)
 * --------------------
 * c: course in focus
 * n: name to be given to course
 */
extern void setCourseName(Course* c, char* n);

/*
 * Function: setCourseTitle(Course* c, char* t)
 * --------------------
 * c: course in focus
 * t: title to be given to course
 */
extern void setCourseTitle(Course* c, char* t);

/*
 * Function: addReqListToCourse(reqLinkedList* l, Course* c, char* n)
 * --------------------
 * l: linked list of pre-requisites
 * c: course in focus
 * n: full line of pre-requisites
 */
extern void addReqListToCourse(reqLinkedList* l, Course* c, char* n);

/*
 * Function: printCourse(Course* c)
 * --------------------
 * c: course to be printed
 */
extern void printCourse(Course* c);

/*
 * Function: printPrerequisites(Course* c)
 * --------------------
 * c: course to be printed
 */
extern void printPrerequisites(Course* c);

/*
 * Function: printCourseOnly(Course* c)
 * --------------------
 * c: course to be printed
 */
extern void printCourseOnly(Course* c);

/*
 * Function: freeCourse(Course* c)
 * --------------------
 * c: course to be freed
 */
extern void freeCourse(Course* c);

#endif 