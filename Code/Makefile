CFLAGS = -g -Wall

project : main.o reqLinkedList.o degreeReqLinkedList.o degree.o degreeArrayList.o courseArrayList.o course.o department.o departmentArrayList.o
	cc -o project main.o reqLinkedList.o degreeReqLinkedList.o degree.o degreeArrayList.o course.o courseArrayList.o department.o departmentArrayList.o

main.o : main.c degree.h degreeReqLinkedList.h reqLinkedList.h courseArrayList.h course.h department.h departmentArrayList.h
departmentArrayList.o : departmentArrayList.c degreeArrayList.h department.h course.h
department.o : department.c department.h courseArrayList.h reqLinkedList.h course.h
degreeArrayList.o : degreeArrayList.c degreeArrayList.h degree.h 
degree.o : degree.c degree.h degreeReqLinkedList.h reqLinkedList.h
degreeReqLinkedList.o : degreeReqLinkedList.c degreeReqLinkedList.h reqLinkedList.h
courseArrayList.o : courseArrayList.c courseArrayList.h course.h reqLinkedList.h
course.o : course.c course.h reqLinkedList.h
reqLinkedList.o : reqLinkedList.c reqLinkedList.h