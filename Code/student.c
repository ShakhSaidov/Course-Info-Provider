#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "courseTree.h"
#include "degreeArrayList.h"
#include "degree.h"
#include "degreeReqLinkedList.h"

/*
 * Function: createStudent()
 * --------------------
 * Creates a student to be used by the caller
 * Returns: a student with uninitialized contents
 */
Student* createStudent(){
  Student* s = (Student* )malloc(sizeof(Course));
  return s;
}

/*
 * Function: setStudentName(Student* s, char* n)
 * --------------------
 * Sets the given student's name with passed string
 * s: student whose name will be set
 * n: name to be given to student
 */
void setStudentName(Student* s, char* n){
  s->name = (char* )calloc(strlen(n) + 1, sizeof(char));   
  strcpy(s->name, n);
}

/*
 * Function: setStudentMajor(Student* s, char* m)
 * --------------------
 * Sets the given student's major with passed string
 * s: student whose major will be set
 * m: major to be given to student
 */
void setStudentMajor(Student* s, char* m){
  s->major = (char* )calloc(strlen(m) + 1, sizeof(char)); 
  strcpy(s->major, m);
}

/*
 * Function: addCourseTreeToStudent(Student* s, courseTree* c)
 * --------------------
 * Adds a list of courses into given department
 * s: student in focus
 * c: array list of courses
 */
void addCourseTreeToStudent(Student* s, courseTree* c){
  s->coursesTaken = c;
}

/*
 * Function: readStudentFile(FILE* f)
 * --------------------
 * Reads a 'student.txt' file and stores the relevant student information
 * f: file to be read
 * Returns: Student with all information stored
 */
Student* readStudentFile(FILE* f){
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  
  Student* s = createStudent();
  courseTree* tree = createCourseTree();
  read = getline(&line, &len, f);                         //reads file line-by-line. line now has DEPARTMENT
  if(line[0] != '\n') line[strlen(line)-1] = 0;           //getting rid of '\n'
  setStudentName(s, line);
  read = getline(&line, &len, f);                         //reads file line-by-line. line now has DEPARTMENT
  if(line[0] != '\n') line[strlen(line)-1] = 0;           //getting rid of '\n'
  setStudentMajor(s, line);
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
    addCourseToTree(tree, c);
  }
  addCourseTreeToStudent(s, tree);
  free(line);
  return s;
}

/*
 * Function: printStudentOnly(Student* s)
 * --------------------
 * Prints the given student's name only
 * s: student to be printed
 */
void printStudentOnly(Student* s){
   printf("%s\n", s->name);
}


/*
 * Function: void printStudentMajor(stuTree, name)
 * --------------------
 * Prints the major of student in the format of "Degree: ______"
 * s: student in focus
 */
void printStudentMajor(Student* s){
  printf("degree: %s\n", s->major);
}

/*
 * Function: printStudentCourses(Student* s)
 * --------------------
 * Prints the courses that student has taken in each new line
 * s: student in focus
 */
void printStudentCourses(Student* s){
  printf("completed: ");
  printCourseOnlyTreeLine(s->coursesTaken->root);
  printf("\n");
}


/*
 * Function: void printCoursesStillNeeded(Degree* d, Student* s)
 * --------------------
 * Prints the courses that student still needs to take to meet given degree requirements
 * d: degree in focus
 * s: student in focus
 */
void printCoursesStillNeeded(Degree* d, Student* s){
  degreeReqLinkedList* list = d->list;
  courseTree* tree = s->coursesTaken;
  
  RLNode* iter1 = list->head;            //course in degree list
  while(iter1 != NULL){
    RNode* iter2 = iter1->list->head;    //course in course linked list
    if((iter2->name)[0] == 'O'){                                                    //if course is a disjunct
      int count = 0;
      while(iter2 != NULL){
        char* courseName = (char* )calloc(strlen(iter2->name) + 1, sizeof(char));
        if(count == 0) memcpy(courseName, &((iter2->name)[3]), strlen(iter2->name) - 3);
        else memcpy(courseName, &((iter2->name)[0]), strlen(iter2->name));
        if(findCourseInTree(tree->root, courseName) == NULL) count++;
        if(count == iter1->list->size) printRequirements(iter1->list);
        iter2 = iter2->next;
        free(courseName);
      }
    } else {                                                                        //if course is not disjunct
      char* courseName = (char* )calloc(strlen(iter2->name) + 1, sizeof(char));
      strcpy(courseName, iter2->name);
      if(findCourseInTree(tree->root, courseName) == NULL) printf("%s\n", iter2->name);
      free(courseName);
    }
    iter1 = iter1->next; 
  }
}

/*
 * Function: freeStudent(Student* s)
 * --------------------
 * Frees heap space used by student
 * s: student to be freed
 */
void freeStudent(Student* s){
  freeCourseTree(s->coursesTaken);
  free(s->name);
  free(s->major);
  free(s);
}