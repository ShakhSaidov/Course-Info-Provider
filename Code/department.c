#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseArrayList.h"
#include "reqLinkedList.h"
#include "department.h"
#include "course.h"

/*
 * Function: createDepartment()
 * --------------------
 * Creates a Department to be used by the caller
 * Returns: Department with uninitialized contents
 */
Department* createDepartment(){
  Department* d = (Department* )malloc(sizeof(Department));
  return d;
}

/*
 * Function: setDepartmentName(Department* d, char* n)
 * --------------------
 * Mallocs a space for a name and sets the name of the Department
 * d: department in focus
 * n: string name
 */
void setDepartmentName(Department* d, char* n){
  d->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  strcpy(d->name, n);
}

/*
 * Function: addCourseListToDept(Department* d, courseArrayList* c)
 * --------------------
 * Adds a list of courses into given department
 * d: department in focus
 * c: array list of courses
 */
void addCourseListToDept(Department* d, courseArrayList* c){
  d->list = c;
}

/*
 * Function: readDepartmentFile(FILE* f)
 * --------------------
 * Reads a 'department.txt' file and stores the relevant course information
 * f: file to be read
 * Returns: Department with all information stored
 */
Department* readDepartmentFile(FILE* f){
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  
  Department* d = createDepartment();
  courseArrayList* courseList = createCourseArrayList(1);
  read = getline(&line, &len, f);                         //reads file line-by-line. line now has DEPARTMENT
  if(line[0] != '\n') line[strlen(line)-1] = 0;           //getting rid of '\n'
  setDepartmentName(d, line);
  Course* c;
  
  while(read >= 0){
    c = createCourse();
    read = getline(&line, &len, f);                       //line now holds course name
    if(line[0] != '\n') line[strlen(line)-1] = 0;         //getting rid of '\n'
    if((read < 0) || (strcmp(line, "\n") == 0)){
      free(c); 
      break;
    } 
    setCourseName(c, line);
    
    read = getline(&line, &len, f);                       //line now holds course title
    if(line[0] != '\n') line[strlen(line)-1] = 0;         //getting rid of '\n'
    setCourseTitle(c, line);
    
    read = getline(&line, &len, f);                       //line now holds pre-requisites
    reqLinkedList* reqList = createReqLinkedList();
    if(line[0] == '\n'){
      addReqListToCourse(reqList, c, line); 
    } else {
      line[strlen(line)-1] = 0;                           //getting rid of '\n'
      addReqListToCourse(reqList, c, line); 
    }
    addCourseToArrayList(courseList, c);
  }
  addCourseListToDept(d, courseList);
  free(line);
  return d;
}

/*
 * Function: findCourseInDept(Department* d, char* n)
 * --------------------
 * Looks if a given course-name is a part of the department
 * d: department in focus
 * n: course name
 * Returns: Course with the given name
 */
Course* findCourseInDept(Department* d, char* n){
  return findCourseInList(d->list, n);
}

/*
 * Function: printDepartment(Department* d)
 * --------------------
 * Prints the full department information
 * d: department in focus
 */
void printDepartment(Department* d){
  printf("%s", d->name);
  printCourseArrayList(d->list);
  printf("\n");
}

/*
 * Function: freeDepartment(Department* d)
 * --------------------
 * Frees the heap space used by a given department
 * d: department in focus
 */
void freeDepartment(Department* d){
  freeCourseArrayList(d->list);
  free(d->name);
  free(d);
}