#ifndef DEGREE_H
#define DEGREE_H
#include <stdbool.h>
#include "reqLinkedList.h"
#include "degreeReqLinkedList.h"

typedef struct Degree{
  degreeReqLinkedList* list;
  char* name;
} Degree;    

/*
 * Function: createDegree()
 * --------------------
 */
extern Degree* createDegree();

 /*
 * Function: setDegreeName(Degree* d, char* n)
 * --------------------
 * d: degree in focus
 * n: name to be given to degree
 */
extern void setDegreeName(Degree* d, char* n);

/*
 * Function: addDegreeNameToLinkedList(Degree* d, reqLinkedList* l)
 * --------------------
 * d: degree whose name will be added to list
 * l: linked list
 */
extern void addDegreeNameToLinkedList(Degree* d, reqLinkedList* l);

/*
 * Function: addListToDegree(Degree* d, char* l)
 * --------------------
 * d: degree in focus
 * l: line of course-names to be added to degree
 */
extern void addListToDegree(Degree* d, char* l);

 /*
 * Function: readDegreeFile(FILE* f)
 * --------------------
 * f: file to be read
 */
extern Degree* readDegreeFile(FILE* n);

/*
 * Function: findCourseInDegree(Degree* d, char* n)
 * --------------------
 * d: degree in focus
 * n: course name to be searched for
 */
extern int findCourseInDegree(Degree* d, char* n);

/*
 * Function: int removeCourseFromDegree(Degree* d, char* n)
 * --------------------
 * d: degree in focus
 * n: course name to be removed from degree
 */
extern int removeCourseFromDegree(Degree* d, char* n);

/*
 * Function: printDegreeReq(Degree* d)
 * --------------------
 * d: degree to be printed
 */
extern void printDegreeReq(Degree* d);

/*
 * Function: printDegree(Degree* d)
 * --------------------
 * d: degree to be printed
 */
extern void printDegree(Degree* d);

/*
 * Function: printDegreeName(Degree* d)
 * --------------------
 * d: degree to be printed
 */
extern void printDegreeName(Degree* d);

/*
 * Function: freeDegree(Degree* d)
 * --------------------
 * d: degree to be freed
 */
extern void freeDegree(Degree* d);

#endif 