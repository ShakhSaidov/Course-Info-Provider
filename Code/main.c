#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reqLinkedList.h"
#include "degreeReqLinkedList.h"
#include "degree.h"
#include "degreeArrayList.h"
#include "course.h"
#include "courseArrayList.h"
#include "department.h"
#include "departmentArrayList.h"

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
 *
 *  Author: Shakh Saidov
 */

degreeArrayList* degreeList;
departmentArrayList* departmentList;

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
      } else {  
        printf("INVALID FIRST LINE IN FILE!\n");            //if first line invalid
      }
    }
    fclose(file);
  }  
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
    } else if(command == 'd'){
      performCommandD(commandLine);
    } else if(command == 'c'){
      performCommandC(commandLine);
    } else if(command == 'p'){
      performCommandP(commandLine);
    } else if(command == 's'){
      performCommandS(commandLine);
    }
      else {
      printf("INVALID command!\n\n");
    }
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