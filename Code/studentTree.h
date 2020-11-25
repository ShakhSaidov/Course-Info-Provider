#ifndef STUDENT_TREE_H
#define STUDENT_TREE_H
#include "student.h"
#include "courseTree.h"
#include "degreeArrayList.h"

typedef struct studentTree{
	struct StudentNode* root;
  int size;
} studentTree;

typedef struct StudentNode {
  struct StudentNode* left;
  struct StudentNode* right;
  Student* student;
} StudentNode;

/*
 * Function: createStudentTree()
 * --------------------
 */
extern studentTree* createStudentTree();

/*
 * Function: findStudentInTree(StudentNode* root, char* n)
 * --------------------
 * root: root of a binary tree of students
 * n: student name 
 */
extern Student* findStudentInTree(StudentNode* root, char* n);

/*
 * Function: makeStudentNode(Student* s)
 * --------------------
 * s: student to be created
 */
extern StudentNode* makeStudentNode(Student* s);

/*
 * Function: addStudentToTree(studentTree* tree, Student* s)
 * --------------------
 * tree: binary tree of students
 * s: student to be added
 */
extern void addStudentToTree(studentTree* tree, Student* s);

/*
 * Function: printStudentOnlyTree(StudentNode* root)
 * --------------------
 * root: root of a binary tree of students
 */
extern void printStudentOnlyTree(StudentNode* root);


/*
 * Function: void printStudentInfo(studentTree* tree, char* name)
 * --------------------
 * stuTree: binary tree of students
 * name: name of student
 */
extern void printStudentInfo(studentTree* tree, char* name);

/*
 * Function: printCoursesHaveToTake(degreeArrayList* list, studentTree* tree, char* name)
 * --------------------
 * list: array list of degrees
 * stuTree: binary tree of students
 * name: name of student
 */
extern void printCoursesHaveToTake(degreeArrayList* list, studentTree* tree, char* name);

/*
 * Function: freeNodes(StudentNode* r)
 * --------------------
 * r: student node of a binary tree of students
 */
extern void freeStudentNodes(StudentNode* r);

/*
 * Function: freeStudentTree(studentTree* tree)
 * --------------------
 * tree: binary tree of students
 */
extern void freeStudentTree(studentTree* tree);

#endif