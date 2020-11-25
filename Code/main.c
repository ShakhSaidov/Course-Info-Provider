#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reqLinkedList.h"
#include "degreeReqLinkedList.h"
#include "degree.h"
#include "degreeArrayList.h"
#include "course.h"
#include "courseTree.h"
#include "department.h"
#include "departmentArrayList.h"
#include "studentTree.h"

/*
 * The program:
 * reads "degree.txt" and "department.txt" files
 * stores relevant information in combination of ArrayLists and LinkedLists
 * displays information based on the user command
 * 
 * Commands:
 * "c "
 * "d "
 * "s "
 * "p c "
 * "p d "
 * "p g "
 * "p s "
 * "a "
 * "m "
 * "n "
 * "q "
 * "r "
 *
 *  Author: Shakh Saidov
 */

//global variables
degreeArrayList* degreeList;
departmentArrayList* departmentList;
studentTree* stuTree;

/*
 * Function: setupArrayLists(char** arg, int fileCount)
 * --------------------
 * Reads the file and stores degree & department information
 * arg: arguments in command line
 * fileCount: number of files the user included
 */
void setupArrayLists(char** arg, int fileCount){     
  FILE* file;
  char fileName[50];
  char fileLine[100];
  degreeList = createDegreeArrayList(fileCount);
  departmentList = createDepartmentArrayList(fileCount);  
  stuTree = createStudentTree();
  
  for(int i = 1; i < fileCount; i++){                         
    strcpy(fileName, arg[i]);
    file = fopen(fileName, "r");
    if(fgets(fileLine, sizeof(fileName), file)) {            //checking first line, file type
      if(strcmp(fileLine, "DEGREE\n") == 0){
        Degree* degree = readDegreeFile(file);
        addDegreeToArrayList(degreeList, degree);
      } else if (strcmp(fileLine, "DEPARTMENT\n") == 0){
        Department* department = readDepartmentFile(file);
        addDepartmentToArrayList(departmentList, department);
      } else if (strcmp(fileLine, "STUDENT\n") == 0){
        Student* student = readStudentFile(file);
        addStudentToTree(stuTree, student);
      } else {  
        printf("INVALID FIRST LINE IN FILE!\n");            //if first line invalid
      }
    }
    fclose(file);
  }  
}

/*
 * Function: performCommandN(char* c)
 * --------------------
 * Perform 'n ': shows the courses the specified student can register for, having taken pre-requisites
 * c: degree name
 */
void performCommandN(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  printCoursesCanTake(departmentList, stuTree, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandM(char* c)
 * --------------------
 * Perform 'm ': shows the courses that the specified student still has to take in order to meet his/her degree requirements
 * c: degree name
 */
void performCommandM(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  printCoursesHaveToTake(degreeList, stuTree, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandR(char* c)
 * --------------------
 * Perform 'r ': shows the courses the specified student can register for, having taken pre-requisites
 * c: degree name
 */
void performCommandR(char* c){
  int length = strlen(c);
  char* name1 = (char* )calloc(length, sizeof(char));
  char* name2 = (char* )calloc(length, sizeof(char));
  char* name3 = (char* )calloc(length, sizeof(char));
  memcpy(name1, &c[2], length-3);
  memcpy(name2, &c[2], length-3);
  memcpy(name3, &c[2], length-3);
  removeCourseFromDegreeList(degreeList, name1);
  removeCourseFromDeptInList(departmentList, name2);
  removeCourseAsPrereqFromDeptList(departmentList, name3);
  printf("\n");
  free(name1);
  free(name2);
  free(name3);
}


/*
 * Function: performCommandS(char* c)
 * --------------------
 * Perform 's ': shows courses that can now be taken and the degrees that require the course
 * c: course name
 */
void performCommandS(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  getCoursesAvailableNow(departmentList, name);
  printDegreesRequiringCourse(degreeList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandQ(char* c)
 * --------------------
 * Perform 'q ': 
 * c: degree name
 */
void performCommandQ(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length);
  removeCourseFromDegreeInList(degreeList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandA(char* c)
 * --------------------
 * Perform 'a ': adds the specified course with its relevant information onto the specified department
 * c: degree name
 */
void performCommandA(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length);
  addToDepartment(departmentList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandD(char* c)
 * --------------------
 * Perform 'd ': shows the course requirements for given degree
 * c: degree name
 */
void performCommandD(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length);
  printDegreeRequirements(degreeList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandD(char* c)
 * --------------------
 * Perform 'c ': shows the title and pre-requisites of given course
 * c: course name
 */
void performCommandC(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  if(strcmp(c, "\n") == 0){
    getCourseTitleAndPrereq(departmentList, c);
  } else {
    getCourseTitleAndPrereq(departmentList, name);
  }
  printf("\n");
  free(name);
}

/*
 * Function: performCommandP_D(char* c)
 * --------------------
 * Perform 'p d ': shows all courses provided by the department
 * c: department name
 */
void performCommandP_D(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  getCoursesInDepartment(departmentList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandP_C(char* c)
 * --------------------
 * Perform 'p c ': shows the department the course is under in; the degrees that require the course; and the pre-requisites of the course
 * c: course name
 */
void performCommandP_C(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  getCourseDepartment(departmentList, name);
  printDegreesWithCourse(degreeList, name);
  getCoursePrerequisites(departmentList, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandP_G(char* c)
 * --------------------
 * Perform 'p g ': shows the course requirements for given degree
 * c: degree name
 */
void performCommandP_G(char* c){
  performCommandD(c);
}

/*
 * Function: performCommandP_S(char* c)
 * --------------------
 * Perform 'p s ': shows the deparment and completed courses information for given student
 * c: student name
 */
void performCommandP_S(char* c){
  int length = strlen(c);
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length-3);
  printStudentInfo(stuTree, name);
  printf("\n");
  free(name);
}

/*
 * Function: performCommandP(char* c)
 * --------------------
 * Checks with "p " type command the user wants and performs the right one
 * c: string name
 */
void performCommandP(char* c){
  int length = strlen(c) + 1;
  char* name = (char* )calloc(length, sizeof(char));
  memcpy(name, &c[2], length - 2);
  char command = name[0];
  if(command == 'c'){
    performCommandP_C(name);
  } else if(command == 'd'){
    performCommandP_D(name);
  } else if(command == 'g'){
    performCommandP_G(name);
  } else if(command == 's'){
    performCommandP_S(name);
  } else{
    printf("INVALID 'p' command\n");
  }
  free(name);
}

/*
 * Function: performCommands()
 * --------------------
 * Performs the commands given by user
 */
void performCommands(){
  char commandLine[100];
  int loop = 1;
  while(loop == 1){
    fgets(commandLine, 100, stdin);
    char command = commandLine[0];
    if(command == 'x'){
      printf("Program exit!\n");
      loop = 2;
    } else if(command == 'd') performCommandD(commandLine);
      else if(command == 'c') performCommandC(commandLine);
      else if(command == 'p') performCommandP(commandLine);
      else if(command == 's') performCommandS(commandLine);
      else if(command == 'a') performCommandA(commandLine);
      else if(command == 'm') performCommandM(commandLine);
      else if(command == 'n') performCommandN(commandLine);
      else if(command == 'q') performCommandQ(commandLine);
      else if(command == 'r') performCommandR(commandLine);
      else printf("INVALID command!\n\n");
  }      
}

/*
 * Function: freeLists()
 * --------------------
 * Frees heap space used by array lists of degrees and departments
 */
void freeLists(){
  freeDepartmentArrayList(departmentList);
  freeDegreeArrayList(degreeList); 
  freeStudentTree(stuTree);
}

//main function
int main(int argc, char** argv){
  if (argc < 2){                          //if user input invalid
    printf("Missing Filenames\n");
    return 0;
  } 
  
  setupArrayLists(argv, argc);                    
  performCommands();
  freeLists();                     
}