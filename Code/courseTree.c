#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reqLinkedList.h"
#include "course.h"
#include "courseTree.h"

/*
 * Function: createCourseTree(int s)
 * --------------------
 * Creates a binary tree of courses to be used by the caller
 * s: size of binary tree
 * Returns: binary tree of courses
 */
courseTree* createCourseTree(){
	courseTree* tree = (courseTree* )malloc(sizeof(courseTree));
	tree->root = NULL;
  tree->size = 0;
	return tree;
}

/*
 * Function: findCourseInTree(CourseNode* root, char* n)
 * --------------------
 * Searches for a course with given name in the tree
 * root: root of a course binary tree
 * n: course name to be searched for
 * Returns: Course with matching name
 */
Course* findCourseInTree(CourseNode* root, char* n){
  if (root != NULL){
    int diff = strcmp(n, root->course->name);    
    if(diff == 0){ 
      return root->course;
    } else if(diff < 0){                       //note change to strcmp.
      return findCourseInTree(root->left , n);
    } else {
      return findCourseInTree(root->right, n);
    }
  } else return NULL; 
}

/*
 * Function: findCourseWithPrereq(reqLinkedList* l, CourseNode* root, char* n)
 * --------------------
 * Searches for a course with given name in the tree and finds what courses open up after taking the found course. Adds the courses that now can be taken into the passed linked list
 * l: linked list of courses
 * root: root of a course binary tree
 * n: course name to be searched for
 */
void findCourseWithPrereq(reqLinkedList* l, CourseNode* root, char* n){
  if(root == NULL) return;
  RNode* iter = root->course->list->head;            //Course pre-requisite
  findCourseWithPrereq(l, root->left, n);
  findCourseWithPrereq(l, root->right, n);
      
  while(iter != NULL){
    char* courseName = (char* )calloc(strlen(iter->name) + 1, sizeof(char));
    if((iter->name)[0] == 'O'){                                          //if course is a disjunct
      memcpy(courseName, &((iter->name)[3]), strlen(iter->name) - 3);
    } else {
      strcpy(courseName, iter->name);
    }
    if(strcmp(courseName, n) == 0){ 
      if(existsInReqLinkedList(l, root->course->name) == 0){          
        insertReqLinkedList(l, root->course->name);
      }
    }
    free(courseName);
    iter = iter->next;
  }   
}

/*
 * Function: findCourseWithPrereqTree(reqLinkedList* l, CourseNode* deptRoot, CourseNode* stuRoot)
 * --------------------
 * iterates through the courses that a student has taken and calls findCourseWithPrereq on it to find which courses open up.
 * l: linked list of courses
 * deptRoot: the root of the tree of courses in the department
 * stuRoot: the root of the tree of courses that student has taken
 */
void findCourseWithPrereqTree(reqLinkedList* l, CourseNode* deptRoot, CourseNode* stuRoot){
  if(stuRoot == NULL) return;
  findCourseWithPrereqTree(l, deptRoot, stuRoot->left);
  findCourseWithPrereq(l, deptRoot, stuRoot->course->name);
  findCourseWithPrereqTree(l, deptRoot, stuRoot->right);
}

/*
 * Function: deleteTakenCourses(reqLinkedList* l, CourseNode* root)
 * --------------------
 * Deletes a node from the list if its data matches the root's data
 * l: linked list of courses
 * root: root of a course binary tree
 */
void deleteTakenCourses(reqLinkedList* l, CourseNode* root){
  if(root == NULL) return;
  deleteTakenCourses(l, root->left);
  deleteNode(l, root->course->name);
  deleteTakenCourses(l, root->right);
}

/*
 * Function: makeCourseNode(Course* c)
 * --------------------
 * Creates a course node
 * c: course to be created
 * Returns: a new Course
 */
CourseNode* makeCourseNode(Course* c){
  CourseNode* node = (CourseNode*)malloc(sizeof(CourseNode));
  node->course = c;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*
 * Function: addCourseToTree(courseTree* tree, Course* c)
 * --------------------
 * Adds the given course into the given tree
 * tree: binary tree of courses
 * c: course to be added onto the tree
 */
void addCourseToTree(courseTree* tree, Course* c){
  if(tree->root == NULL){
     tree->root = makeCourseNode(c);
   } else {  
     CourseNode* temp = tree->root;    //tracking current node
     CourseNode* parent;             //tracking parent node
     while(temp != NULL){          
       parent = temp;
       if(strcmp(c->name, temp->course->name) < 0){
         temp = temp->left;
       } else {
         temp = temp->right;
       }
     }
    
     if(strcmp(c->name, parent->course->name) < 0){
       parent->left = makeCourseNode(c);
     } else{
       parent->right = makeCourseNode(c);
     } 
  }
  tree->size++;
}

/*
 * Function: CourseNode* findMin(CourseNode* root)
 * --------------------
 * Returns the node with minimum value (in this case, name)
 * root: root of the course binary tree
 * Returns: CourseNode that has minimum value
 */
CourseNode* findMin(CourseNode* root){
    if(root == NULL) return NULL;
    else if(root->left != NULL) return findMin(root->left); // left most element will be minimum
    return root;
}

/*
 * Function: CourseNode* deleteCourseNode(CourseNode* root, char* n)
 * --------------------
 * Deletes the course with the given name from tree
 * root: root of the course binary tree
 * n: course name to be deleter from tree
 * Returns: CourseNode that was removed
 */
CourseNode* deleteCourseNode(CourseNode* root, char* n){
  if(root == NULL) return NULL;                                                //searching for the CourseNode to be deleted
  if (strcmp(n, root->course->name) > 0) root->right = deleteCourseNode(root->right, n);
  else if(strcmp(n, root->course->name) < 0) root->left = deleteCourseNode(root->left, n);
  else {
    if(root->left == NULL || root->right == NULL) {          //If there is one Child
        CourseNode* temp;
        if(root->left == NULL)  temp = root->right;
        else temp = root->left;
        freeCourse(root->course);
        free(root);
        return temp;
    }
                                                                  //If there are two Children
    CourseNode* temp = findMin(root->right);
    root->course->name = temp->course->name;
    root->right = deleteCourseNode(root->right, temp->course->name);
  }
  return root;
}

/*
 * Function: int removeCourseFromDeptReq(courseTree* tree, char* n)
 * --------------------
 * Removes the given course from courseTree
 * tree: binary tree of courses
 * n: course name to be removed from tree
 * Returns: 1 if successfully removed, 0 otherwise
 */
int removeCourseFromDeptReq(courseTree* tree, char* n){
  Course* c = findCourseInTree(tree->root, n);
  if(c == NULL) return 0;
  if(deleteCourseNode(tree->root, c->name)) return 1;
  else return 0;
}

/*
 * Function: removeCourseAsPrereqFromDept(courseTree* tree, char* n)
 * --------------------
 * Removes the given course as a pre-requisite for other courses
 * tree: binary tree of courses
 * n: course name to be removed from tree
 */
void removeCourseAsPrereqFromDept(courseTree* tree, char* n){
  deleteCourseAsPrereq(tree->root, n); 
}

/*
 * Function: deleteCourseAsPrereq(CourseNode* root, char* n)
 * --------------------
 * Searches for courses that require the passed course, and deletes the passed course as a prerequisite
 * root: root of the course binary tree
 * n: course name to be deleted as a prerequisite
 */
void deleteCourseAsPrereq(CourseNode* root, char* n){
  if(root != NULL) {
    RNode* iter = root->course->list->head;            //Course pre-requisite
    deleteCourseAsPrereq(root->left, n);
    deleteCourseAsPrereq(root->right, n);
        
    while(iter != NULL){
      char* courseName = (char* )calloc(strlen(iter->name) + 1, sizeof(char));
      if((iter->name)[0] == 'O'){                                          //if course is a disjunct
        memcpy(courseName, &((iter->name)[3]), strlen(iter->name) - 3);
      } else {
        strcpy(courseName, iter->name);
      }
      if(strcmp(courseName, n) == 0) deleteNode(root->course->list, iter->name);                //removes the course as a pre-req
      free(courseName);
      iter = iter->next;
    }  
  } 
}

/*
 * Function: printCourseTree(CourseNode* root)
 * --------------------
 * Prints each course information in tree
 * root: root of the course binary tree
 */
void printCourseTree(CourseNode* root){
  if(root == NULL) return;
  printCourseTree(root->left);
  printCourse(root->course);
  printCourseTree(root->right);
}

/*
 * Function: printCourseOnlyTree(CourseNode* root)
 * --------------------
 * Prints each course name in tree in new line
 * root: root of the course binary tree
 */
void printCourseOnlyTree(CourseNode* root){
  if(root == NULL) return;
  printCourseOnlyTree(root->left);
  printCourseOnly(root->course);
  printCourseOnlyTree(root->right);
}

/*
 * Function: printCourseOnlyTreeLine(CourseNode* root)
 * --------------------
 * Prints each course name in tree in one line
 * root: root of the course binary tree
 */
void printCourseOnlyTreeLine(CourseNode* root){
  if(root != NULL) {
    if(root->left != NULL){
      printCourseOnlyTreeLine(root->left); 
      printf(", ");
    }
    
    printf("%s", root->course->name);
    
    if(root->right != NULL){
      printf(", ");
      printCourseOnlyTreeLine(root->right); 
    }
  }
}

/*
 * Function: freeCourseNodes(CourseNode* r)
 * --------------------
 * Frees each of the nodes of the binary tree
 * r: node to be freed
 */
void freeCourseNodes(CourseNode* r){
	if (r == NULL) return;

  //recursive calls
  freeCourseNodes(r->left);
  freeCourseNodes(r->right);

  freeCourse(r->course);
  free(r);
}

/*
 * Function: freeCourseTree(courseTree* tree)
 * --------------------
 * Frees heap space used by the tree
 * tree: binary tree of courses to be freed
 */
void freeCourseTree(courseTree* tree){
	freeCourseNodes(tree->root);	
	free(tree);
}