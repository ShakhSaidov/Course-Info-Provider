#ifndef DEPARTMENT_ARRAY_LIST_H
#define DEPARTMENT_ARRAY_LIST_H
#include "department.h"
#include "studentTree.h"

typedef struct departmentArrayList{
	Department** departments;
	int size;
	int capacity;
} departmentArrayList;

/*
 * Function: createDepartmentArrayList(int s)
 * --------------------
 * s: wanted size for array list
 */
extern departmentArrayList* createDepartmentArrayList(int s);

/*
 * Function: getDepartment(departmentArrayList* list, int index)
 * --------------------
 * list: array list of departments
 * index: the index of the element to be retrieved
 */
extern Department* getDepartment(departmentArrayList* list, int index);

/*
 * Function: expandDepartmentArrayList(departmentArrayList* list, int length)
 * --------------------
 * list: array list of departments
 * length: the new size of array list
 */
extern departmentArrayList* expandDepartmentArrayList(departmentArrayList* list, int length);

/*
 * Function: findDept(departmentArrayList* list, char* n)
 * --------------------
 * list: array list of departments
 * name: department name to be searched for
 */
extern Department* findDept(departmentArrayList* list, char* name);

/*
 * Function: addDepartmentToArrayList(departmentArrayList* list, Department* d)
 * --------------------
 * list: array list of departments
 * d: department to be added
 */
extern void addDepartmentToArrayList(departmentArrayList* list, Department* d);

/*
 * Function: addToDepartment(departmentArrayList* list, char* n)
 * --------------------
 * list: array list of departments
 * n: information to be added, given in the format "department, courseName, courseTitle, coursePreReq"
 */
void addToDepartment(departmentArrayList* list, char* n);

/*
 * Function: printDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * list: array list of departments to be printed
 */ 
extern void printDepartmentArrayList(departmentArrayList* list);

/*
 * Function: printDepartmentsInArrayList(departmentArrayList* list)
 * --------------------
 * list: array list of departments to be printed
 */
extern void printDepartmentsInArrayList(departmentArrayList* list);

/*
 * Function: getCourseTitleAndPrereq(departmentArrayList* l, char* n)
 * --------------------
 * l: array list of departments
 * n: course name
 */
extern void getCourseTitleAndPrereq(departmentArrayList* l, char* n);

/*
 * Function: getCoursesInDepartment(departmentArrayList* l, char* n)
 * --------------------
 * l: array list of departments
 * n: department name
 */
extern void getCoursesInDepartment(departmentArrayList* l, char* n);

/*
 * Function: getCourseDepartment(departmentArrayList* l, char* n)
 * --------------------
 * l: array list of departments
 * n: course name
 */
extern void getCourseDepartment(departmentArrayList* l, char* n);

/*
 * Function: removeCourseFromDeptInList(departmentArrayList* list, char* name)
 * --------------------
 * list: array list of departments
 * name: department and course name in the format of "departmentName, courseName"
 */
extern void removeCourseFromDeptInList(departmentArrayList* list, char* name);

/*
 * Function: removeCourseAsPrereqFromDeptList(departmentArrayList* list, char* name)
 * --------------------
 * list: array list of departments
 * name: department and course name in the format of "departmentName, courseName"
 */
extern void removeCourseAsPrereqFromDeptList(departmentArrayList* list, char* name);

/*
 * Function: getCoursePrerequisites(departmentArrayList* l, char* n)
 * --------------------
 * l: array list of departments
 * n: course name
 */
extern void getCoursePrerequisites(departmentArrayList* l, char* n);

/*
 * Function: getCoursesAvailableNow(departmentArrayList* l, char* n)
 * --------------------
 * l: array list of departments
 * n: course name
 */
extern void getCoursesAvailableNow(departmentArrayList* l, char* n);

/*
 * Function: printCoursesCanTake(departmentArrayList* l, studentTree* tree, char* n)
 * --------------------
 * l: array list of departments
 * tree: binary tree of students
 * n: course name
 */
extern void printCoursesCanTake(departmentArrayList* l, studentTree* tree, char* n);

/*
 * Function: freeDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * list: array list of departments to be freed
 */
extern void freeDepartmentArrayList(departmentArrayList* list);

#endif