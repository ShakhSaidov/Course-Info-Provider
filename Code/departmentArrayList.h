#ifndef DEPARTMENT_ARRAY_LIST_H
#define DEPARTMENT_ARRAY_LIST_H
#include "department.h"

typedef struct departmentArrayList{
	Department** departments;
	int size;
	int capacity;
} departmentArrayList;

/*
 * Function: createDepartmentArrayList(int s)
 * --------------------
 * Creates an array list of departments to be used by the caller
 * s: size of array list
 * Returns: array list of departments
 */
extern departmentArrayList* createDepartmentArrayList(int s);

/*
 * Function: getDepartment(departmentArrayList* list, int index)
 * --------------------
 * Gets the department at the given index in the array list
 * list: array list of departments
 * index: the index in array list
 * Returns: Department in given index of list
 */
extern Department* getDepartment(departmentArrayList* list, int index);

/*
 * Function: expandDepartmentArrayList(departmentArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of departments
 * length: the new size of array list
 * Returns: updated array list with new size
 */
extern departmentArrayList* expandDepartmentArrayList(departmentArrayList* list, int length);

/*
 * Function: findDept(departmentArrayList* list, char* n)
 * --------------------
 * Searches for a department with given name in the array list
 * list: array list of departments
 * name: department name to be searched for
 * Returns: Department with matching name
 */
extern Department* findDept(departmentArrayList* list, char* name);

/*
 * Function: addDepartmentToArrayList(departmentArrayList* list, Department* d)
 * --------------------
 * Adds the given department into the given list
 * list: array list of departments
 * d: department with course info
 */
extern void addDepartmentToArrayList(departmentArrayList* list, Department* d);

/*
 * Function: printDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Prints each department information in array list
 * list: array list of departments
 */
extern void printDepartmentArrayList(departmentArrayList* list);

/*
 * Function: printDepartmentsInArrayList(departmentArrayList* list)
 * --------------------
 * Prints each department name in array list
 * list: array list of departments
 */
extern void printDepartmentsInArrayList(departmentArrayList* list);

/*
 * Function: getCourseTitleAndPrereq(departmentArrayList* l, char* n)
 * --------------------
 * Finds a course with matching name with the passed string and displays its title and pre-requisites
 * l: array list of departments
 * n: course name
 */
extern void getCourseTitleAndPrereq(departmentArrayList* l, char* n);

/*
 * Function: getCoursesInDepartment(departmentArrayList* l, char* n)
 * --------------------
 * Prints the courses of a department with matching names with passed string. 
 * The format matches the user comman "p d "
 * l: array list of departments
 * n: department name
 */
extern void getCoursesInDepartment(departmentArrayList* l, char* n);

/*
 * Function: getCourseDepartment(departmentArrayList* l, char* n)
 * --------------------
 * Prints the department names that a course with matching names with the passed string is included in. 
 * The format matches the first output of user command "p c "
 * l: array list of departments
 * n: course name
 */
extern void getCourseDepartment(departmentArrayList* l, char* n);

/*
 * Function: getCoursePrerequisites(departmentArrayList* l, char* n)
 * --------------------
 * Prints the pre-requisites of a course with matching names with the passed string. 
 * The format matches the second output of user command "p c "
 * l: array list of departments
 * n: course name
 */
extern void getCoursePrerequisites(departmentArrayList* l, char* n);

/*
 * Function: getCoursesAvailableNow(departmentArrayList* l, char* n)
 * --------------------
 * Prints courses that can be taken after taking a course with matching names with the passed string.
 * The format matches the first output of user command "s "
 * l: array list of departments
 * n: course name
 */
extern void getCoursesAvailableNow(departmentArrayList* l, char* n);

/*
 * Function: freeDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Frees heap space used for the array list
 * list: array list of departments
 */
extern void freeDepartmentArrayList(departmentArrayList* list);

#endif