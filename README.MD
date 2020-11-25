**PROJECT TITLE:** Course Info Provider\
**PURPOSE OF PROJECT:** Read in department and degree files, store relevant information and display them upon user command\
**VERSION or DATE:** v1.0\
**HOW TO START THIS PROJECT:** Run in a Linux environment\
**AUTHORS:** Shakh Saidov\
**USER INSTRUCTIONS:** \
Add in "department.txt" and "degree.txt" files in the appropriate format shown by default files. Read the files as shown below:
▸ "./project dept1.txt dept2.txt degree1.txt degree2.txt ..."

Run commands as shown below:
▸ "d DegreeName" - Lists all the courses required to earn the specified degree
▸ "c CourseName" - Shows the title of the course and its prerequisites
▸ "s CourseName" - Shows what courses now can be taken, and the degrees that require it
▸ "p g DegreeName" - Lists all the courses required to earn the specified degree
▸ "p d DepartmentName" - Lists all the courses provided by the department
▸ "p c CourseName" - Shows which department the course falls under, the degrees requiring the course and its prerequisites
▸ "p s StudentName" - Shows the major of student and the courses the student has taken
▸ "m StudentName" - Shows the courses the student still has to take in order to meet the degree requirements
▸ "n StudentName" - Shows the courses the student can take having taken the prerequisites
▸ "a DepartmentName, CourseName, CourseTitle, CoursePrerequisites" - adds the given course information into the department
▸ "r DepartmentName, CourseName" - Removes the given course from the department, degree requirements, and as a prerequisite for other courses
▸ "q DegreeName, CourseName" - Removes the given course from degree requirements

**LEARNED:** 
▸ Reading Files and storing information in relevant data structures listed below
▸ Creating and working with LinkedLists, ArrayLists and BinaryTrees in C
▸ Debugging with Valgrind & Valkyrie
