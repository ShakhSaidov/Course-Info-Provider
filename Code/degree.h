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
 * Creates a Degree to be used by the caller
 * Returns: Degree
 */
extern Degree* createDegree();

 /*
 * Function: setDegreeName(Degree* d, char* n)
 * --------------------
 * Mallocs a space for a name and sets the name of the Degree 
 * d: degree in focus
 * n: string name
 */
extern void setDegreeName(Degree* d, char* n);

/*
 * Function: addDegreeNameToLinkedList(Degree* d, reqLinkedList* l)
 * --------------------
 * Adds a degree-name to a linked list
 * d: degree in focus
 * l: linked list
 */
extern void addDegreeNameToLinkedList(Degree* d, reqLinkedList* l);

/*
 * Function: addListToDegree(Degree* d, char* l)
 * --------------------
 * Adds a list of course-names to the given degree
 * d: degree in focus
 * l: line of course-names
 */
extern void addListToDegree(Degree* d, char* l);

/*
 * Function: findCourseInDegree(Degree* d, char* n)
 * --------------------
 * Looks if a given course-name is required by the degree
 * d: degree in focus
 * n: course name
 * Returns: 1 if course-name is found, 0 otherwise
 */
extern int findCourseInDegree(Degree* d, char* n);

 /*
 * Function: readDegreeFile(FILE* f)
 * --------------------
 * Reads a 'degree.txt' file and stores the courses needed to get the degree 
 * f: file to be read
 * Returns: Degree with all information stored
 */
extern Degree* readDegreeFile(FILE* n);

/*
 * Function: printDegreeReq(Degree* d)
 * --------------------
 * Prints the course-names that are required for the degree line-by-line
 * d: degree in focus
 */
extern void printDegreeReq(Degree* d);

/*
 * Function: printDegree(Degree* d)
 * --------------------
 * Prints the full degree information
 * d: degree in focus
 */
extern void printDegree(Degree* d);

/*
 * Function: printDegreeName(Degree* d)
 * --------------------
 * Prints only the degree name
 * d: degree in focus
 */
extern void printDegreeName(Degree* d);

/*
 * Function: freeDegree(Degree* d)
 * --------------------
 * Frees the heap space used by a given degree
 * d: degree in focus
 */
extern void freeDegree(Degree* d);

#endif 