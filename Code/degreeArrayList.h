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
 * Creates an array list of degrees to be used by the caller
 * s: size of array list
 * Returns: array list of degrees
 */
extern degreeArrayList* createDegreeArrayList(int s);

/*
 * Function: getDegree(degreeArrayList* list, int index)
 * --------------------
 * Gets the degree at the given index in the array list
 * list: array list of degrees
 * index: the index in array list
 * Returns: Degree in given index of list
 */
extern degreeArrayList* expandDegreeArrayList(degreeArrayList* list, int length);

/*
 * Function: expandDegreeArrayList(degreeArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of degrees
 * length: the new size of array list
 * Returns: updated array list with new size
 */
extern Degree* getDegree(degreeArrayList* list, int index);

/*
 * Function: findDegree(degreeArrayList* list, char* name)
 * --------------------
 * Searches for a degree with given name in the array list
 * list: array list of degrees
 * name: degree name to be searched for
 * Returns: Degree with matching name
 */
extern Degree* findDegree(degreeArrayList* list, char* name);

/*
 * Function: addDegreeToArrayList(degreeArrayList* list, Degree* d)
 * --------------------
 * Adds the given degree into the given list
 * list: array list of degrees
 * d: degree with course info
 */
extern void addDegreeToArrayList(degreeArrayList* list, Degree* d);

/*
 * Function: printDegreeArrayList(degreeArrayList* list)
 * --------------------
 * Prints each degree information in array list
 * list: array list of degrees
 */
extern void printDegreeArrayList(degreeArrayList* list);

/*
 * Function: printDegreeNameArrayList(degreeArrayList* list)
 * --------------------
 * Prints each degree name in array list
 * list: array list of degrees
 */
extern void printDegreeNameArrayList(degreeArrayList* list);

/*
 * Function: printDegreeRequirements(degreeArrayList* list, char* degName)
 * --------------------
 * Prints the full information of given degree in list
 * list: array list of degrees
 * degName: degree name 
 */
extern void printDegreeRequirements(degreeArrayList* list, char* degName);

/*
 * Function: printDegreesRequiringCourse(degreeArrayList* list, char* name)
 * --------------------
 * Prints the Degrees that require the given course-name in the format required by the command "s "
 * list: array list of degrees 
 * degName: degree name 
 */
extern void printDegreesRequiringCourse(degreeArrayList* list, char* name);

/*
 * Function: printDegreesWithCourse(degreeArrayList* list, char* name)
 * --------------------
 * Prints the Degrees that require the given course-name in the format required by the command "p c "
 * list: array list of degrees 
 * degName: degree name 
 */
extern void printDegreesWithCourse(degreeArrayList* list, char* name);

/*
 * Function: freeDegreeArrayList(degreeArrayList* list)
 * --------------------
 * frees heap space used for the array list
 * list: array list of degrees
 */
extern void freeDegreeArrayList(degreeArrayList* list);

#endif