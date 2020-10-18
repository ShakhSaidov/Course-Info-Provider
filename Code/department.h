#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <stdio.h>
#include "courseArrayList.h"

typedef struct Department{
  courseArrayList* list;
  char* name;
} Department;    

/*
 * Function: createDepartment()
 * --------------------
 * Creates a Department to be used by the caller
 * Returns: Department with uninitialized contents
 */
extern Department* createDepartment();

/*
 * Function: setDepartmentName(Department* d, char* n)
 * --------------------
 * Mallocs a space for a name and sets the name of the Department
 * d: department in focus
 * n: string name
 */
extern void setDepartmentName(Department* d, char* n);

/*
 * Function: addCourseListToDept(Department* d, courseArrayList* c)
 * --------------------
 * Adds a list of courses into given department
 * d: department in focus
 * c: array list of courses
 */
extern void addCourseListToDepartment(Department* d, char* l);

/*
 * Function: readDepartmentFile(FILE* f)
 * --------------------
 * Reads a 'department.txt' file and stores the relevant course information
 * f: file to be read
 * Returns: Department with all information stored
 */
extern Department* readDepartmentFile(FILE* n);

/*
 * Function: findCourseInDept(Department* d, char* n)
 * --------------------
 * Looks if a given course-name is a part of the department
 * d: department in focus
 * n: course name
 * Returns: Course with the given name
 */
extern Course* findCourseInDept(Department* d, char* n);

/*
 * Function: printDepartment(Department* d)
 * --------------------
 * Prints the full department information
 * d: department in focus
 */
extern void printDepartment(Department* d);

/*
 * Function: freeDepartment(Department* d)
 * --------------------
 * Frees the heap space used by a given department
 * d: department in focus
 */
extern void freeDepartment(Department* d);

#endif 