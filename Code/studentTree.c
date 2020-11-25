#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "studentTree.h"
#include "courseTree.h"
#include "degree.h"
#include "degreeArrayList.h"

/*
 * Function: createStudentTree()
 * --------------------
 * Creates a binary tree of students to be used by the caller
 * Returns: binary tree of students
 */
studentTree* createStudentTree(){
	studentTree* tree = (studentTree* )malloc(sizeof(studentTree));
	tree->root = NULL;
  tree->size = 0;
	return tree;
}

/*
 * Function: findStudentInTree(StudentNode* root, char* n)
 * --------------------
 * Searches for a student with given name in the tree
 * root: root of a binary tree of students
 * n: student name
 * Returns: Student with matching name
 */
Student* findStudentInTree(StudentNode* root, char* n){
  if (root != NULL){
    int diff = strcmp(n, root->student->name);    
    if(diff == 0){ 
      return root->student;
    } else if(diff < 0){                       //note change to strcmp.
      return findStudentInTree(root->left , n);
    } else {
      return findStudentInTree(root->right, n);
    }
  } else { 
    return NULL;
  }
}

/*
 * Function: makeStudentNode(Student* s)
 * --------------------
 * Creates a student node
 * s: student to be created
 */
StudentNode* makeStudentNode(Student* s){
  StudentNode* node = (StudentNode*)malloc(sizeof(StudentNode));
  node->student = s;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*
 * Function: addStudentToTree(studentTree* tree, Student* s)
 * --------------------
 * Adds the given student into the given tree
 * tree: binary tree of students
 * s: student to be added
 */
void addStudentToTree(studentTree* tree, Student* s){
  if(tree->root == NULL){
     tree->root = makeStudentNode(s);
   } else {  
     StudentNode* temp = tree->root;    //tracking current node
     StudentNode* parent;             //tracking parent node
     while(temp != NULL){          
       parent = temp;
       if(strcmp(s->name, temp->student->name) < 0){
         temp = temp->left;
       } else {
         temp = temp->right;
       }
     }
    
     if(strcmp(s->name, parent->student->name) < 0){
       parent->left = makeStudentNode(s);
     } else{
       parent->right = makeStudentNode(s);
     } 
  }
  tree->size++;
}

/*
 * Function: printStudentOnlyTree(StudentNode* root)
 * --------------------
 * Prints each student name in tree
 * root: root of a binary tree of students
 */
void printStudentOnlyTree(StudentNode* root){
  if(root == NULL) return;
  printStudentOnlyTree(root->left);
  printStudentOnly(root->student);
  printStudentOnlyTree(root->right);
}

/*
 * Function: void printStudentInfo(studentTree* tree, char* name)
 * --------------------
 * Prints the major and courses taken by a student
 * stuTree: binary tree of students
 * name: name of student
 */
void printStudentInfo(studentTree* tree, char* name){
  Student* s = findStudentInTree(tree->root, name);
  if(s == NULL) printf("NOT FOUND!\n");
  else {
    printStudentMajor(s);
    printStudentCourses(s);
  } 
}

/*
 * Function: printCoursesHaveToTake(degreeArrayList* list, studentTree* tree, char* name)
 * --------------------
 * Prints the courses the student still needs to take to meet his/her degree requirements
 * list: array list of degrees
 * stuTree: binary tree of students
 * name: name of student
 */
void printCoursesHaveToTake(degreeArrayList* list, studentTree* tree, char* name){
  Student* s = findStudentInTree(tree->root, name);
  if(s == NULL) printf("STUDENT NOT FOUND!\n");
  else{
    char* major = (char* )calloc(strlen(s->major) + 2, sizeof(char));
    strcpy(major, s->major);
    strcat(major, "\n");
    Degree* deg = findDegree(list, major);
    if(deg == NULL) printf("DEGREE NOT FOUND!\n");
    else{
      printCoursesStillNeeded(deg, s);
    }
    
    free(major);
  }
}

/*
 * Function: freeStudentNodes(StudentNode* r)
 * --------------------
 * Frees each of the nodes of the binary tree
 * r: student node of a binary tree of students
 */
void freeStudentNodes(StudentNode* r){
	if (r == NULL) return;
  //recursive calls
  freeStudentNodes(r->left);
  freeStudentNodes(r->right);
  
  freeStudent(r->student);
  free(r);
}

/*
 * Function: freeStudentTree(studentTree* tree)
 * --------------------
 * Frees heap space used by the tree
 */
void freeStudentTree(studentTree* tree){
	freeStudentNodes(tree->root);	
	free(tree);
}