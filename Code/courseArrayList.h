#ifndef COURSE_ARRAY_LIST_H
#define COURSE_ARRAY_LIST_H
#include "course.h"

typedef struct courseArrayList{
	Course** courses;
	int size;
	int capacity;
} courseArrayList;

/*
 * Function: createCourseArrayList(int s)
 * --------------------
 * Creates an array list of courses to be used by the caller
 * s: size of array list
 * Returns: array list of courses
 */
extern courseArrayList* createCourseArrayList(int s);

/*
 * Function: getCourse(courseArrayList* list, int index)
 * --------------------
 * Gets the course at the given index in the array list
 * list: array list of courses
 * index: the index in array list
 * Returns: Course in given index of list
 */
extern Course* getCourse(courseArrayList* list, int index);

/*
 * Function: expandCourseArrayList(courseArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of courses
 * length: the new size of array list
 * Returns: updated array list with new size
 */
extern courseArrayList* expandCourseArrayList(courseArrayList* list, int length);

/*
 * Function: findCourseInList(courseArrayList* list, char* n)
 * --------------------
 * Searches for a course with given name in the array list
 * list: array list of courses
 * n: course name to be searched for
 * Returns: Course with matching name
 */
extern Course* findCourseInList(courseArrayList* list, char* n);

/*
 * Function: findCourseWithPrereq(reqLinkedList* l, courseArrayList* list, char* n)
 * --------------------
 * Searches for a course with given name in the array list and finds what courses open up after taking the found course. Adds the courses that now can be taken into the passed linked list
 * l: linked list of courses
 * list: array list of courses
 * n: course name to be searched for
 */
extern void findCourseWithPrereq(reqLinkedList* l, courseArrayList* list, char* n);

/*
 * Function: addCourseToArrayList(courseArrayList* list, Course* c)
 * --------------------
 * Adds the given course into the given list
 * list: array list of courses
 * c: course to be added
 */
extern void addCourseToArrayList(courseArrayList* list, Course* d);

/*
 * Function: printCourseArrayList(courseArrayList* list)
 * --------------------
 * Prints each course information in array list
 * list: array list of courses
 */
extern void printCourseArrayList(courseArrayList* list);

/*
 * Function: printCourseOnlyArrayList(courseArrayList* list)
 * --------------------
 * Prints each course name in array list
 * list: array list of courses
 */
extern void printCourseOnlyArrayList(courseArrayList* list);

/*
 * Function: freeCourseArrayList(courseArrayList* list)
 * --------------------
 * Frees heap space used by the array list
 */
extern void freeCourseArrayList(courseArrayList* list);

#endif