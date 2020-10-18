#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reqLinkedList.h"
#include "course.h"
#include "courseArrayList.h"

/*
 * Function: createCourseArrayList(int s)
 * --------------------
 * Creates an array list of courses to be used by the caller
 * s: size of array list
 * Returns: array list of courses
 */
courseArrayList* createCourseArrayList(int s){
	courseArrayList* list = (courseArrayList* )malloc(sizeof(courseArrayList));
	list->courses = (Course** )calloc(s, sizeof(Course* ));
  list->size = 0;
	list->capacity = s;
  
  for(int i = 0; i < s; i++){
		list->courses[i] = NULL;
  }
  
	return list;
}

/*
 * Function: getCourse(courseArrayList* list, int index)
 * --------------------
 * Gets the course at the given index in the array list
 * list: array list of courses
 * index: the index in array list
 * Returns: Course in given index of list
 */
Course* getCourse(courseArrayList* list, int index){
	return list->courses[index];
}

/*
 * Function: expandCourseArrayList(courseArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of courses
 * length: the new size of array list
 * Returns: updated array list with new size
 */
courseArrayList* expandCourseArrayList(courseArrayList* list, int length){
	Course** c = (Course** )calloc(length, sizeof(Course* ));
	if(length <= list->capacity){                  //if expansion if unnecessary
		return list;
  }

	for(int i = 0; i < list->capacity; i++){
		if(list->courses[i] != NULL){
			c[i] = list->courses[i];
    } else{
			c[i] = NULL;
    }
	}

	for(int i = list->capacity; i < length; i++){
		c[i] = NULL;
  }
  
 	free(list->courses);
	list->courses = c;
	list->capacity = length;
	return list;
}

/*
 * Function: findCourseInList(courseArrayList* list, char* n)
 * --------------------
 * Searches for a course with given name in the array list
 * list: array list of courses
 * n: course name to be searched for
 * Returns: Course with matching name
 */
Course* findCourseInList(courseArrayList* list, char* n){
  for(int i = 0; i < list->size; i++){
    if(strcmp(n, list->courses[i]->name) == 0){
      return list->courses[i];
    }
  }
  return NULL;
}

/*
 * Function: findCourseWithPrereq(reqLinkedList* l, courseArrayList* list, char* n)
 * --------------------
 * Searches for a course with given name in the array list and finds what courses open up after taking the found course. Adds the courses that now can be taken into the passed linked list
 * l: linked list of courses
 * list: array list of courses
 * n: course name to be searched for
 */
void findCourseWithPrereq(reqLinkedList* l, courseArrayList* list, char* n){
  for(int i = 0; i < list->size; i++){
    for(int j = 0; j < list->courses[i]->list->size; j++){
      RNode* iter = list->courses[i]->list->head;            //Course pre-requisite
      while(iter != NULL){
        if(strcmp(iter->name, n) == 0){ 
          if(existsInReqLinkedList(l, list->courses[i]->name) == 0){          
            insertReqLinkedList(l, list->courses[i]->name);
          }
        }
        iter = iter->next;
      }
    }
  }
}

/*
 * Function: addCourseToArrayList(courseArrayList* list, Course* c)
 * --------------------
 * Adds the given course into the given list
 * list: array list of courses
 * c: course to be added
 */
void addCourseToArrayList(courseArrayList* list, Course* c){
	if(list->capacity == list->size){
		list = expandCourseArrayList(list, list->capacity * 2 + 1);
	}
 
	int index = list->size;
  list->courses[index] = c;
	list->size++;
}

/*
 * Function: printCourseArrayList(courseArrayList* list)
 * --------------------
 * Prints each course information in array list
 * list: array list of courses
 */
void printCourseArrayList(courseArrayList* list){
  for(int i = 0; i < list->size; i++){
    printCourse(list->courses[i]);
  }
}

/*
 * Function: printCourseOnlyArrayList(courseArrayList* list)
 * --------------------
 * Prints each course name in array list
 * list: array list of courses
 */
void printCourseOnlyArrayList(courseArrayList* list){
  for(int i = 0; i < list->size; i++){
    printCourseOnly(list->courses[i]);
  }
}

/*
 * Function: freeCourseArrayList(courseArrayList* list)
 * --------------------
 * Frees heap space used by the array list
 */
void freeCourseArrayList(courseArrayList* list){
	int length = list->size;
	for(int i = 0; i < length; i++){
		if(list->courses[i] != NULL){
			freeCourse(list->courses[i]);
    }
  }
	free(list->courses);
	free(list);
}