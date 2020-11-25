#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <stdio.h>
#include "courseTree.h"

typedef struct Department{
  courseTree* tree;
  char* name;
} Department;    

/*
 * Function: createDepartment()
 * --------------------
 */
extern Department* createDepartment();

/*
 * Function: setDepartmentName(Department* d, char* n)
 * --------------------
 * d: department in focus
 * n: department's name to be given
 */
extern void setDepartmentName(Department* d, char* n);

/*
 * Function: addCourseTreeToDept(Department* d, courseTree* c)
 * --------------------
 * d: department in focus
 * c: array list of courses to add onto department
 */
extern void addCourseTreeToDepartment(Department* d, char* l);

/*
 * Function: readDepartmentFile(FILE* f)
 * --------------------
 * f: file to be read
 */
extern Department* readDepartmentFile(FILE* n);

/*
 * Function: findCourseInDept(Department* d, char* n)
 * --------------------
 * d: department in focus
 * n: course name to be searched for
 */
extern Course* findCourseInDept(Department* d, char* n);

/*
 * Function: int removeCourseFromDept(Department* d, char* n)
 * --------------------
 * d: department in focus
 * n: course name to be removed
 */
extern int removeCourseFromDept(Department* d, char* n);

/*
 * Function: printDepartment(Department* d)
 * --------------------
 * d: department to be printed
 */
extern void printDepartment(Department* d);

/*
 * Function: freeDepartment(Department* d)
 * --------------------
 * d: department to be freed
 */
extern void freeDepartment(Department* d);

#endif 