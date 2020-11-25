#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "courseTree.h"
#include "department.h"
#include "departmentArrayList.h"
#include "reqLinkedList.h"
#include "studentTree.h"
#include "student.h"

/*
 * Function: createDepartmentArrayList(int s)
 * --------------------
 * Creates an array list of departments to be used by the caller
 * s: wanted size for array list
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
 * index: the index of the element to be retrieved
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
 * d: department to be added
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
 * Function: addToDepartment(departmentArrayList* list, char* n)
 * --------------------
 * Adds a course with its information onto the specified Department
 * list: array list of departments
 * n: information to be added, given in the format "department, courseName, courseTitle, coursePreReq"
*/
void addToDepartment(departmentArrayList* list, char* n){
  Department* dept = NULL;
  Course* course = createCourse();
  reqLinkedList* reqList = createReqLinkedList();
  int count = 0;
  char* preReqs = (char* )calloc(strlen(n) + 1, sizeof(char)); 
  char* token = strtok(n, ",");                       
  while(token != NULL){
    if (count == 0) {
      dept = findDept(list, token);
    } else if (count == 1 || count == 2) {
      char* string = (char* )calloc(strlen(token) + 1, sizeof(char));
      memcpy(string, &token[1], strlen(token) - 1);
      if(count == 1) setCourseName(course, string);
      if(count == 2) setCourseTitle(course, string);
      free(string);
    } else{
      strcat(preReqs, token); 
    }
    token = strtok(NULL, ",");
    count++;
  }
  addReqListToCourse(reqList, course, preReqs);
  addCourseToTree(dept->tree, course);
  free(preReqs);
  free(token);
}

/*
 * Function: printDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Prints each department information in array list
 * list: array list of departments to be printed
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
 * list: array list of departments to be printed
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
  if(c != NULL) printf("%s\n", c->title);
  if(c != NULL){
    if(strcmp(c->list->head->name, "\n") == 0){
      printf("NOT FOUND\n");                              //if course has no pre-requisites
    } else{
      printRequirements(c->list);
    }
  } else {
    printf("NOT FOUND\n");  
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
  if(d != NULL){
    printCourseOnlyTree(d->tree->root);
  } else {
    printf("NOT FOUND\n");
  }
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
  int found = 0;
  for(int i = 0; i < l->size; i++){
    if(findCourseInDept(l->departments[i], n) != NULL){
      printf("department: %s\n", l->departments[i]->name);
      found = 1;
      break;
    }
  }
  if(found == 0) printf("NOT FOUND\n");
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
  Course* c = NULL;
  for(int i = 0; i < l->size; i++){
    if(findCourseInTree(l->departments[i]->tree->root, n) != NULL){
      c = findCourseInTree(l->departments[i]->tree->root, n);
      break;
    }
  }
  printf("pre-requisites: ");
  if(c != NULL && c->list->size != 0){
    if(strcmp(c->list->head->name, "\n") == 0) printf("NOT FOUND\n");                               //if course has no pre-requisites
    else printPrerequisites(c);
  } else {
    printf("NOT FOUND\n");   
  }
}

/*
 * Function: removeCourseFromDeptInList(departmentArrayList* list, char* name)
 * --------------------
 * Removes the specified course from the specified department requirements
 * list: array list of departments
 * name: department and course name in the format of "departmentName, courseName"
 */
void removeCourseFromDeptInList(departmentArrayList* list, char* name){
  Department* dept = NULL;         
  char* token = strtok(name, ",");               //setting up token
  char* deptName = (char* )calloc(strlen(token) + 2, sizeof(char));        //getting the department name
  strcpy(deptName, token);                     
  dept = findDept(list, deptName);
  token = strtok(NULL, ",");
  char* courseName = (char* )calloc(strlen(token) + 2, sizeof(char));      //getting the course name to remove
  memcpy(courseName, &(token[1]), strlen(token)-1);
  token = strtok(NULL, ",");
  if(dept != NULL) {
    if(removeCourseFromDept(dept, courseName)) printf("%s removed from dept requirements!\n", courseName);
    else printf("NOT FOUND!\n");
  } else {
    printf("NOT FOUND!\n");
  }
  free(token);
  free(courseName);
  free(deptName);
}

/*
 * Function: removeCourseAsPrereqFromDeptList(departmentArrayList* list, char* name)
 * --------------------
 * Removes the specified course as a course pre-requisite for any other course
 * list: array list of departments
 * name: department and course name in the format of "departmentName, courseName"
 */
void removeCourseAsPrereqFromDeptList(departmentArrayList* list, char* name){
  char* token = strtok(name, ",");               //setting up token
  token = strtok(NULL, ",");
  char* courseName = (char* )calloc(strlen(token) + 2, sizeof(char));      //getting the course name to remove
  memcpy(courseName, &(token[1]), strlen(token)-1);
  token = strtok(NULL, ",");
  for(int i = 0; i < list->size; i++){
    removeCourseAsPrereqFromDept(list->departments[i]->tree, courseName);
  }
  printf("%s removed as a prerequisite!\n", courseName);
  free(token);
  free(courseName);
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
    findCourseWithPrereq(courses, l->departments[i]->tree->root, n);
  }
  if(courses->size != 0){
    printRequirements(courses);
  } else {
    printf("NOT FOUND\n");
  }
  freeReqLinkedList(courses);
}

/*
 * Function: printCoursesCanTake(departmentArrayList* l, studentTree* tree, char* n)
 * --------------------
 * Prints the courses that the specified student can take now
 * l: array list of departments
 * tree: binary tree of students
 * n: course name
 */
void printCoursesCanTake(departmentArrayList* l, studentTree* tree, char* n){
  Student* s = findStudentInTree(tree->root, n);
  if(s == NULL){
    printf("STUDENT NOT FOUND!\n");
    return;
  }
  reqLinkedList* courses = createReqLinkedList();
  
  for(int i = 0; i < l->size; i++){
    findCourseWithPrereqTree(courses, l->departments[i]->tree->root, s->coursesTaken->root);
  }
  
  deleteTakenCourses(courses, s->coursesTaken->root);
  
  if(courses->size != 0){
    printRequirementsInNewLine(courses);
  } else {
    printf("NOT FOUND!\n");
  }
  freeReqLinkedList(courses);
}

/*
 * Function: freeDepartmentArrayList(departmentArrayList* list)
 * --------------------
 * Frees heap space used for the array list
 * list: array list of departments to be freed
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