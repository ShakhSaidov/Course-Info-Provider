#ifndef COURSE_TREE_H
#define COURSE_TREE_H
#include "course.h"

typedef struct courseTree{
	struct CourseNode* root;
  int size;
} courseTree;

typedef struct CourseNode {
  struct CourseNode* left;
  struct CourseNode* right;
  Course* course;
} CourseNode;

/*
 * Function: createCourseTree()
 * --------------------
 */
extern courseTree* createCourseTree();

/*
 * Function: findCourseInTree(CourseNode* root, char* n)
 * --------------------
 * root: root of a course binary tree
 * n: course name to be searched for
 */
extern Course* findCourseInTree(CourseNode* root, char* n);

/*
 * Function: findCourseWithPrereq(reqLinkedList* l, CourseNode* root, char* n)
 * --------------------
 * l: linked list of courses
 * root: root of a course binary tree
 * n: course name to be searched for
 */
extern void findCourseWithPrereq(reqLinkedList* l, CourseNode* root, char* n);

/*
 * Function: findCourseWithPrereqTree(reqLinkedList* l, CourseNode* deptRoot, CourseNode* stuRoot)
 * --------------------
 * l: linked list of courses
 * deptRoot: the root of the tree of courses in the department
 * stuRoot: the root of the tree of courses that student has taken
 */
extern void findCourseWithPrereqTree(reqLinkedList* l, CourseNode* deptRoot, CourseNode* stuRoot);

/*
 * Function: deleteTakenCourses(reqLinkedList* l, CourseNode* root)
 * --------------------
 * l: linked list of courses
 * root: root of a course binary tree
 */
extern void deleteTakenCourses(reqLinkedList* l, CourseNode* root);

/*
 * Function: makeNode(Course* c)
 * --------------------
 * c: course to be created
 */
extern CourseNode* makeCourseNode(Course* c);

/*
 * Function: addCourseToTree(courseTree* tree, Course* c)
 * --------------------
 * tree: binary tree of courses
 * c: course to be added onto the tree
 */
extern void addCourseToTree(courseTree* tree, Course* c);

/*
 * Function: CourseNode* findMin(CourseNode* root)
 * --------------------
 * root: root of the course binary tree
 */
extern CourseNode* findMin(CourseNode* root);

/*
 * Function: CourseNode* deleteCourseNode(CourseNode* root, char* n)
 * --------------------
 * root: root of the course binary tree
 * n: course name to be deleter from tree
 */
extern CourseNode* deleteCourseNode(CourseNode* root, char* n);

/*
 * Function: removeCourseFromDeptReq(courseTree* tree, char* n)
 * --------------------
 * tree: binary tree of courses
 * n: course name to be removed from tree
 */
extern int removeCourseFromDeptReq(courseTree* tree, char* n);

/*
 * Function: removeCourseAsPrereqFromDept(courseTree* tree, char* n)
 * --------------------
 * tree: binary tree of courses
 * n: course name to be removed from tree
 */
extern void removeCourseAsPrereqFromDept(courseTree* tree, char* n);

/*
 * Function: deleteCourseAsPrereq(CourseNode* root, char* n)
 * --------------------
 * root: root of the course binary tree
 * n: course name to be deleted as a prerequisite
 */
extern void deleteCourseAsPrereq(CourseNode* root, char* n);

/*
 * Function: printCourseTree(CourseNode* root)
 * --------------------
 * root: root of the course binary tree
 */
extern void printCourseTree(CourseNode* root);

/*
 * Function: printCourseOnlyTree(CourseNode* root)
 * --------------------
 * root: root of the course binary tree
 */
extern void printCourseOnlyTree(CourseNode* root);

/*
 * Function: printCourseOnlyTreeLine(CourseNode* root)
 * --------------------
 * root: root of the course binary tree
 */
extern void printCourseOnlyTreeLine(CourseNode* root);

/*
 * Function: freeNodes(CourseNode* r)
 * --------------------
 * r: node to be freed
 */
extern void freeCourseNodes(CourseNode* r);

/*
 * Function: freeCourseTree(courseTree* tree)
 * --------------------
 * tree: binary tree of courses to be freed
 */
extern void freeCourseTree(courseTree* tree);

#endif