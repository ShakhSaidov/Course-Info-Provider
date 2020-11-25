#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseTree.h"
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
 * n: department's name to be given
 */
void setDepartmentName(Department* d, char* n){
  d->name = (char* )calloc(strlen(n) + 1, sizeof(char));
  strcpy(d->name, n);
}

/*
 * Function: addCourseTreeToDept(Department* d, courseTree* c)
 * --------------------
 * Adds a list of courses into given department
 * d: department in focus
 * c: array list of courses to add onto department
 */
void addCourseTreeToDept(Department* d, courseTree* c){
  d->tree = c;
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
  courseTree* courseTree = createCourseTree();
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
    addCourseToTree(courseTree, c);
  }
  addCourseTreeToDept(d, courseTree);
  free(line);
  return d;
}

/*
 * Function: findCourseInDept(Department* d, char* n)
 * --------------------
 * Looks if a given course-name is a part of the department
 * d: department in focus
 * n: course name to be searched for
 * Returns: Course with the given name
 */
Course* findCourseInDept(Department* d, char* n){
  return findCourseInTree(d->tree->root, n);
}

/*
 * Function: int removeCourseFromDept(Department* d, char* n)
 * --------------------
 * Removes the given course from the department requirements and as a course pre-requisite
 * d: department in focus
 * n: course name to be removed
 * Returns: 1 if course was removed, 0 otherwise
 */
int removeCourseFromDept(Department* d, char* n){
  return removeCourseFromDeptReq(d->tree, n);
}

/*
 * Function: printDepartment(Department* d)
 * --------------------
 * Prints the full department information
 * d: department to be printed
 */
void printDepartment(Department* d){
  printf("%s", d->name);
  printCourseTree(d->tree->root);
  printf("\n");
}

/*
 * Function: freeDepartment(Department* d)
 * --------------------
 * Frees the heap space used by a given department
 * d: department to be freed
 */
void freeDepartment(Department* d){
  freeCourseTree(d->tree);
  free(d->name);
  free(d);
}