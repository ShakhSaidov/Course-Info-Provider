#ifndef DEGREE_ARRAY_LIST_H
#define DEGREE_ARRAY_LIST_H
#include "degree.h"

typedef struct degreeArrayList{
	Degree** degrees;
	int size;
	int capacity;
} degreeArrayList;

/*
 * Function: createDegreeArrayList(int s)
 * --------------------
 * s: wanted size for array list
 */
extern degreeArrayList* createDegreeArrayList(int s);

/*
 * Function: getDegree(degreeArrayList* list, int index)
 * --------------------
 * list: array list of degrees
 * index: the index of the element to retrieve
 */
extern Degree* getDegree(degreeArrayList* list, int index);

/*
 * Function: expandDegreeArrayList(degreeArrayList* list, int length)
 * --------------------
 * list: array list of degrees
 * length: the new size of array list
 */
extern degreeArrayList* expandDegreeArrayList(degreeArrayList* list, int length);

/*
 * Function: findDegree(degreeArrayList* list, char* name)
 * --------------------
 * list: array list of degrees
 * name: degree to be searched for
 */
extern Degree* findDegree(degreeArrayList* list, char* name);

/*
 * Function: removeCourseFromDegreeInList(degreeArrayList* list, char* name)
 * --------------------
 * list: array list of degrees
 * name: degree and course name in the format of "degreeName, courseName"
 */
extern void removeCourseFromDegreeInList(degreeArrayList* list, char* name);

/*
 * Function: removeCourseFromDegreeList(degreeArrayList* list, char* name)
 * --------------------
 * list: array list of degrees
 * name: dept and course name in the format of "dept. name, courseName"
 */
extern void removeCourseFromDegreeList(degreeArrayList* list, char* name);

/*
 * Function: addDegreeToArrayList(degreeArrayList* list, Degree* d)
 * --------------------
 * list: array list of degrees
 * d: degree with course info
 */
extern void addDegreeToArrayList(degreeArrayList* list, Degree* d);

/*
 * Function: printDegreeArrayList(degreeArrayList* list)
 * --------------------
 * list: array list of degrees to be printed
 */
extern void printDegreeArrayList(degreeArrayList* list);

/*
 * Function: printDegreeNameArrayList(degreeArrayList* list)
 * --------------------
 * list: array list of degrees to be printed
 */
extern void printDegreeNameArrayList(degreeArrayList* list);

/*
 * Function: printDegreeRequirements(degreeArrayList* list, char* degName)
 * --------------------
 * list: array list of degrees
 * degName: degree name in focus
 */
extern void printDegreeRequirements(degreeArrayList* list, char* degName);

/*
 * Function: printDegreesRequiringCourse(degreeArrayList* list, char* name)
 * --------------------
 * list: array list of degrees 
 * name: course name in focus
 */
extern void printDegreesRequiringCourse(degreeArrayList* list, char* name);

/*
 * Function: printDegreesWithCourse(degreeArrayList* list, char* name)
 * --------------------
 * list: array list of degrees 
 * name: degree name to be printed
 */
extern void printDegreesWithCourse(degreeArrayList* list, char* name);

/*
 * Function: freeDegreeArrayList(degreeArrayList* list)
 * --------------------
 * list: array list of degrees to be freed
 */
extern void freeDegreeArrayList(degreeArrayList* list);

#endif