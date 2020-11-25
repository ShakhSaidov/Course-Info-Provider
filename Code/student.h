#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include "courseTree.h"
#include "degreeArrayList.h"
#include "degree.h"
#include "degreeReqLinkedList.h"

typedef struct Student{
  char* name;
  char* major;
  courseTree* coursesTaken;
} Student;    

/*
 * Function: createStudent()
 * --------------------
 */
extern Student* createStudent(); 

/*
 * Function: setStudentName(Student* s, char* n)
 * --------------------
 * s: student whose name will be set
 * n: name to be given to student
 */
extern void setStudentName(Student* s, char* n);

/*
 * Function: setStudentMajor(Student* s, char* m)
 * --------------------
 * s: student whose major will be set
 * m: major to be given to student
 */
extern void setStudentMajor(Student* s, char* m);

/*
 * Function: addCourseTreeToStudent(Student* s, courseTree* c)
 * --------------------
 * Adds a list of courses into given department
 * s: student in focus
 * c: array list of courses
 */
extern void addCourseTreeToStudent(Student* s, courseTree* c);

/*
 * Function: readStudentFile(FILE* f)
 * --------------------
 * f: file to be read
 */
extern Student* readStudentFile(FILE* f);

/*
 * Function: printStudentOnly(Student* s)
 * --------------------
 * s: student to be printed
 */
extern void printStudentOnly(Student* s);

/*
 * Function: void printStudentMajor(Student* s)
 * --------------------
 * s: student in focus
 */
extern void printStudentMajor(Student* s);

/*
 * Function: void printStudentCourses(Student* s)
 * --------------------
 * s: student in focus
 */
extern void printStudentCourses(Student* s);

/*
 * Function: void printCoursesStillNeeded(Degree* d, Student* s)
 * --------------------
 * d: degree in focus
 * s: student in focus
 */
extern void printCoursesStillNeeded(Degree* d, Student* s);

/*
 * Function: freeStudent(Student* s)
 * --------------------
 * s: student to be freed
 */
extern void freeStudent(Student* s);

#endif 