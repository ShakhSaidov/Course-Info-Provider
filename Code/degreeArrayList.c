#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "degree.h"
#include "degreeArrayList.h"


/*
 * Function: createDegreeArrayList(int s)
 * --------------------
 * Creates an array list of degrees to be used by the caller
 * s: size of array list
 * Returns: array list of degrees
 */
degreeArrayList* createDegreeArrayList(int s){
	degreeArrayList* list = (degreeArrayList* )malloc(sizeof(degreeArrayList));
	list->degrees = (Degree** )calloc(s, sizeof(Degree* ));
	list->size = 0;
	list->capacity = s;
  
  for(int i = 0; i < s; i++){
		list->degrees[i] = NULL;
  }
 
	return list;
}

/*
 * Function: getDegree(degreeArrayList* list, int index)
 * --------------------
 * Gets the degree at the given index in the array list
 * list: array list of degrees
 * index: the index in array list
 * Returns: Degree in given index of list
 */
Degree* getDegree(degreeArrayList* list, int index){
	return list->degrees[index];
}

/*
 * Function: expandDegreeArrayList(degreeArrayList* list, int length)
 * --------------------
 * Increases the given array list size to 'length'
 * list: array list of degrees
 * length: the new size of array list
 * Returns: updated array list with new size
 */
degreeArrayList* expandDegreeArrayList(degreeArrayList* list, int length){
	Degree** d = (Degree** )calloc(length, sizeof(Degree* ));
	if(length <= list->capacity){            //if expansion unnecessary
		return list;
  }

	for(int i = 0; i < list->capacity; i++){
		if(list->degrees[i] != NULL){
			d[i] = list->degrees[i];
    } else{
			d[i] = NULL;
    }
	}

	for(int i = list->capacity; i < length; i++){
		d[i] = NULL;
  }

  free(list->degrees);
	list->degrees = d;
	list->capacity = length;
	return list;
}

/*
 * Function: findDegree(degreeArrayList* list, char* name)
 * --------------------
 * Searches for a degree with given name in the array list
 * list: array list of degrees
 * name: degree name to be searched for
 * Returns: Degree with matching name
 */
Degree* findDegree(degreeArrayList* list, char* name){
  for(int i = 0; i < list->size; i++){
    if(strcmp(name, list->degrees[i]->name) == 0){
      return list->degrees[i];
    }
  }
  return NULL;
}

/*
 * Function: addDegreeToArrayList(degreeArrayList* list, Degree* d)
 * --------------------
 * Adds the given degree into the given list
 * list: array list of degrees
 * d: degree with course info
 */
void addDegreeToArrayList(degreeArrayList* list, Degree* d){
	if(list->capacity == list->size){
		list = expandDegreeArrayList(list, list->capacity * 2 + 1);
	}
	
	int index = list->size;
	list->degrees[index] = d;

	list->size++;
}

/*
 * Function: printDegreeArrayList(degreeArrayList* list)
 * --------------------
 * Prints each degree information in array list
 * list: array list of degrees
 */
void printDegreeArrayList(degreeArrayList* list){
  for(int i = 0; i < list->size; i++){
    printDegree(list->degrees[i]);
  }
}

/*
 * Function: printDegreeNameArrayList(degreeArrayList* list)
 * --------------------
 * Prints each degree name in array list
 * list: array list of degrees
 */
void printDegreeNameArrayList(degreeArrayList* list){
  for(int i = 0; i < list->size; i++){
    printDegreeName(list->degrees[i]);
  }
}

/*
 * Function: printDegreeRequirements(degreeArrayList* list, char* degName)
 * --------------------
 * Prints the full information of given degree in list
 * list: array list of degrees
 * degName: degree name 
 */
void printDegreeRequirements(degreeArrayList* list, char* degName){
  Degree* d = findDegree(list, degName);
  printDegreeReq(d);
}

/*
 * Function: printDegreesRequiringCourse(degreeArrayList* list, char* name)
 * --------------------
 * Prints the Degrees that require the given course-name in the format required by the command "s "
 * list: array list of degrees 
 * degName: degree name 
 */
void printDegreesRequiringCourse(degreeArrayList* list, char* name){
  degreeArrayList* degs = createDegreeArrayList(1);
  for(int i = 0; i < list->size; i++){
    if(findCourseInDegree(list->degrees[i], name) == 1){
      addDegreeToArrayList(degs, list->degrees[i]);
    }
  }
  printDegreeNameArrayList(degs);
  free(degs->degrees);
  free(degs);
}

/*
 * Function: printDegreesWithCourse(degreeArrayList* list, char* name)
 * --------------------
 * Prints the Degrees that require the given course-name in the format required by the command "p c "
 * list: array list of degrees 
 * degName: degree name 
 */
void printDegreesWithCourse(degreeArrayList* list, char* name){
  reqLinkedList* degreeNames = createReqLinkedList();
  printf("degrees: ");
  for(int i = 0; i < list->size; i++){
    if(findCourseInDegree(list->degrees[i], name) == 1){
      addDegreeNameToLinkedList(list->degrees[i], degreeNames);
    }
  }
  printRequirements(degreeNames);
  freeReqLinkedList(degreeNames);
}

/*
 * Function: freeDegreeArrayList(degreeArrayList* list)
 * --------------------
 * frees heap space used for the array list
 * list: array list of degrees
 */
void freeDegreeArrayList(degreeArrayList* list){
	int length = list->size;
	for(int i = 0; i < length; i++){
		if(list->degrees[i] != NULL){
			freeDegree(list->degrees[i]);
    }
  }
	free(list->degrees);
	free(list);
}