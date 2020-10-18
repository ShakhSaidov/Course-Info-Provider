#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "department.h"
#include "departmentArrayList.h"

/*
 * Function: createDepartmentArrayList(int s)
 * --------------------
 * Creates an array list of departments to be used by the caller
 * s: size of array list
 * Returns: array list of departments
 */
departmentArrayList* createDepartmentArrayList(int s){
	departmentArrayList* list = (departmentArrayList* )malloc(sizeof(departmentArrayList));
	list->departments = (Department** )calloc(s, sizeof(Department* ));
	list->size = 0;
	list->capacity = s;
  
  for(int i = 0; i < s; i++){
		list->departments[i] = NULL;
  }
 
	return list;
}

/*
 * Function: getDepartment(departmentArrayList* list, int index)
 * --------------------
 * Gets the department at the given index in the array list
 * list: array list of departments
 * index: the index in array list
 * Returns: Department in given index of list
 */
Department* getDepartment(departmentArrayList* list, int index){
	return list->departments[index];
}

/*
 * Function: expandDepartmentArrayList(departmentArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of departments
 * length: the new size of array list
 * Returns: updated array list with new size
 */
departmentArrayList* expandDepartmentArrayList(departmentArrayList* list, int length){
	Department** d = (Department** )calloc(length, sizeof(Department* ));
	if(length <= list->capacity){                             //if expansion is unnecessary
		return list;
  }

	for(int i = 0; i < list->capacity; i++){
		if(list->departments[i] != NULL){
			d[i] = list->departments[i];
    } else{
			d[i] = NULL;
    }
	}

	for(int i = list->capacity; i < length; i++){
		d[i] = NULL;
  }

	free(list->departments);
	list->departments = d;
	list->capacity = length;
	return list;
}

/*
 * Function: findDept(departmentArrayList* list, char* n)
 * --------------------
 * Searches for a department with given name in the array list
 * list: array list of departments
 * name: department name to be searched for
 * Returns: Department with matching name
 */
Department* findDept(departmentArrayList* list, char* n){
  for(int i = 0; i < list->size; i++){
    if(strcmp(list->departments[i]->name, n) == 0){
      return list->departments[i];
    }
  }
  return NULL;
}

/*
 * Function: addDepartmentToArrayList(departmentArrayList* list, Department* d)
 * --------------------
 * Adds the given department into the given list
 * list: array list of departments
 * d: department with course info
 */
void addDepartmentToArrayList(departmentArrayList* list, Department* d){
	if(list->capacity == list->size){
		list = expandDepartmentArrayList(list, list->capacity * 2 + 1);
	}
	
	int index = list->size;
	list->departments[index] = d;
	list->size++;
}

/*
 * Function: printDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Prints each department information in array list
 * list: array list of departments
 */
void printDepartmentArrayList(departmentArrayList* list){
  for(int i = 0; i < list->size; i++){
    printDepartment(list->departments[i]);
  }
}

/*
 * Function: printDepartmentsInArrayList(departmentArrayList* list)
 * --------------------
 * Prints each department name in array list
 * list: array list of departments
 */
void printDepartmentsInArrayList(departmentArrayList* list){
  printf("department: ");
  for(int i = 0; i < list->size; i++){
    printf("%s", list->departments[i]->name);
    if(i != (list->size - 1)){
      printf(", ");
    }
  }
  printf("\n");
}

/*
 * Function: getCourseTitleAndPrereq(departmentArrayList* l, char* n)
 * --------------------
 * Finds a course with matching name with the passed string and displays its title and pre-requisites
 * l: array list of departments
 * n: course name
 */
void getCourseTitleAndPrereq(departmentArrayList* l, char* n){
  Course* c;
  for(int i = 0; i < l->size; i++){
    c = findCourseInDept(l->departments[i], n);
    if(c != NULL){
      break;
    }
  }
  printf("%s\n", c->title);
  if(strcmp(c->list->head->name, "\n") == 0){
    printf("NOT FOUND\n");                              //if course has no pre-requisites
  } else{
    printRequirements(c->list);
  }
}

/*
 * Function: getCoursesInDepartment(departmentArrayList* l, char* n)
 * --------------------
 * Prints the courses of a department with matching names with passed string. 
 * The format matches the user comman "p d "
 * l: array list of departments
 * n: department name
 */
void getCoursesInDepartment(departmentArrayList* l, char* n){
  Department* d = findDept(l, n);
  printCourseOnlyArrayList(d->list);
}

/*
 * Function: getCourseDepartment(departmentArrayList* l, char* n)
 * --------------------
 * Prints the department names that a course with matching names with the passed string is included in. 
 * The format matches the first output of user command "p c "
 * l: array list of departments
 * n: course name
 */
void getCourseDepartment(departmentArrayList* l, char* n){
  for(int i = 0; i < l->size; i++){
    if(findCourseInDept(l->departments[i], n) != NULL){
      printf("department: %s\n", l->departments[i]->name);
    }
  }
}

/*
 * Function: getCoursePrerequisites(departmentArrayList* l, char* n)
 * --------------------
 * Prints the pre-requisites of a course with matching names with the passed string. 
 * The format matches the second output of user command "p c "
 * l: array list of departments
 * n: course name
 */
void getCoursePrerequisites(departmentArrayList* l, char* n){
  Course* c;
  for(int i = 0; i < l->size; i++){
    if(findCourseInList(l->departments[i]->list, n) != NULL){
      c = findCourseInList(l->departments[i]->list, n);
    }
  }
  printf("pre-requisites: ");
  if(strcmp(c->list->head->name, "\n") == 0){
    printf("NOT FOUND\n");                               //if course has no pre-requisites
  } else{
    printPrerequisites(c);
  }
}

/*
 * Function: getCoursesAvailableNow(departmentArrayList* l, char* n)
 * --------------------
 * Prints courses that can be taken after taking a course with matching names with the passed string.
 * The format matches the first output of user command "s "
 * l: array list of departments
 * n: course name
 */
void getCoursesAvailableNow(departmentArrayList* l, char* n){
  reqLinkedList* courses = createReqLinkedList();
  for(int i = 0; i < l->size; i++){
    findCourseWithPrereq(courses, l->departments[i]->list, n);
  }
  if(courses->size != 0){
    printRequirements(courses);
  }
  freeReqLinkedList(courses);
}

/*
 * Function: freeDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Frees heap space used for the array list
 * list: array list of departments
 */
void freeDepartmentArrayList(departmentArrayList* list){
	int length = list->size;
	for(int i = 0; i < length; i++){
		if(list->departments[i] != NULL){
			freeDepartment(list->departments[i]);
    }
  }
	free(list->departments);
	free(list);
}