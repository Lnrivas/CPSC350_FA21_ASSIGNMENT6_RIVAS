## Identifying Information:
0. USING A LATE DAY
1. Name: Luis Rivas
2. Student ID: 2365948
3. Email: lrivas@chapman.edu
4. Class: CPSC-350-03
5. Assignment 6: Building a Database with Binary Search Trees

## Files
1. BST.h
2. GenStack.h
3. main.cpp
4. Simulation.h
5. Simulation.cpp
6. Student.h
7. Student.cpp
8. Faculty.h
9. Faculty.cpp
10. GenLinkedList.h

## Known Errors
When a student is deleted, sometimes the incorrect ID is removed from their advisor's list of advisees. Undoing a deleted faculty doesn't recover their old advisees. When faculty is deleted, sometimes its advisees don't get a new advisor. When database is saved to facultyTable, list of advisees is not printed correctly

## References
https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-14-17-c was used to learn how to check if a file exists in the current directory.
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm was used to learn how to overload operators.
Worked alone.

## Instructions
1. g++ *.cpp
2. ./a.out

# Application Purpose
If facultyTable and or studentTable files exist, read them to create a database. If not, make new empty database. Gives the user 14 menu options for manipulating the database. Saves database back to those 2 files at the end.
