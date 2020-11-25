CFLAGS = -g -Wall

project : main.o reqLinkedList.o degreeReqLinkedList.o degree.o degreeArrayList.o courseTree.o course.o department.o departmentArrayList.o student.o studentTree.o
	cc -o project main.o reqLinkedList.o degreeReqLinkedList.o degree.o degreeArrayList.o course.o courseTree.o department.o departmentArrayList.o student.o studentTree.o

main.o : main.c degree.h degreeReqLinkedList.h reqLinkedList.h courseTree.h course.h department.h departmentArrayList.h
departmentArrayList.o : departmentArrayList.c degreeArrayList.h department.h course.h
department.o : department.c department.h courseTree.h reqLinkedList.h course.h
degreeArrayList.o : degreeArrayList.c degreeArrayList.h degree.h 
degree.o : degree.c degree.h degreeReqLinkedList.h reqLinkedList.h
degreeReqLinkedList.o : degreeReqLinkedList.c degreeReqLinkedList.h reqLinkedList.h
courseTree.o : courseTree.c courseTree.h course.h reqLinkedList.h
course.o : course.c course.h reqLinkedList.h
reqLinkedList.o : reqLinkedList.c reqLinkedList.h
student.o : student.c student.h
studentTree.o: studentTree.c studentTree.h