# Campus Exploration & Student Resource Management System

## Group Members

* Mufaro Ngwenya
* Dariga Thompson
* Teesha Talreja
* Charite Nzambi

---

# Project Overview

The **Campus Exploration & Student Resource Management System** is a modular C++ application that allows users to explore a campus map, manage student records using a linked list, process advising requests using a queue, and analyze campus data. The program follows an object-oriented design with separate classes responsible for map management, student management, file operations, and queue processing.

---

# Features Implemented

## Campus Map

* Load a campus map from an input file.
* Display the campus map.
* Explore any campus location using row and column coordinates.
* Identify the type of location.
* Detect blocked locations.
* Display neighboring locations (up, down, left, and right).
* Count campus objects, including:

  * Roads
  * Buildings
  * Classrooms
  * Libraries
  * Parking Lots
  * Blocked Areas

## Student Management

* Store student records using a **singly linked list**.
* Load student records from a file.
* Add a new student.
* Save newly added students to the student file.
* Remove students by ID.
* Search for students by ID.
* Display all student records.
* Sort students by student ID.

## Advising Queue

* Manage advising requests using a **queue (FIFO)**.
* Add advising requests.
* Process the next advising request.
* Display all pending advising requests.

## File Management

* Choose campus map and student record files at runtime.
* Load campus maps from text files.
* Load student records from text files.
* Reload student records without restarting the program.

## Campus Statistics

* Display statistics about the campus map, including counts of each map object.

---

# Compilation

Compile the project using:

```bash
g++ main.cpp CampusMap.cpp FileManager.cpp StudentList.cpp QueueSystem.cpp -o my_program
```

or simply:

```bash
g++ *.cpp -o my_program
```

The project requires a C++11 (or newer) compatible compiler such as **g++** or **clang++**.

---

# Execution

Run the program with:

```bash
./my_program
```

At runtime, choose:

* Campus map file (for example: `campus_map.txt`)
* Student records file (for example: `students.txt`)

No filenames are hardcoded.

---

# Input File Formats

## Campus Map (`campus_map.txt`)

Format:

```text
<rows> <cols>
<symbol> <symbol> ...
```

Example:

```text
5 5
P R R B B
R R R R B
L R C C R
R R R R R
C C R L R
```

### Campus Map Symbols

| Symbol | Meaning      |
| ------ | ------------ |
| R      | Road         |
| B      | Building     |
| C      | Classroom    |
| L      | Library      |
| P      | Parking Lot  |
| X      | Blocked Area |

---

## Student Records (`students.txt`)

Format:

```text
id name major gpa
```

Example:

```text
2001 Sophia CS 3.91
2002 Liam IT 3.42
2003 Olivia CE 3.78
2004 Noah CS 2.95
2005 Ava SE 3.67
2006 Mason IT 3.11
```

---

# Project Structure

| File                 | Responsibility                                           |
| -------------------- | -------------------------------------------------------- |
| `main.cpp`           | Program entry point, menu system, and user interaction   |
| `CampusMap.h/.cpp`   | Campus map loading, display, exploration, and statistics |
| `StudentList.h/.cpp` | Linked list implementation for student records           |
| `QueueSystem.h/.cpp` | Queue implementation for advising requests               |
| `FileManager.h/.cpp` | Loading campus maps and student records from files       |
| `campus_map.txt`     | Sample campus map input                                  |
| `students.txt`       | Sample student records                                   |

---

# Menu Options

```
CAMPUS MANAGEMENT SYSTEM 
0. Choose Files (Map + Students)

---- CAMPUS MAP ----
1. Display Map
2. Explore Location
3. Show Neighbors
4. Count Campus Objects

---- STUDENTS ----
5. Add Student (Save to File)
6. Remove Student
7. Search Student
8. Display All Students
9. Sort Students by ID

---- ADVISOR QUEUE ----
10. Add Advising Request
11. Process Request
12. Display Queue

---- SYSTEM ----
13. Load Students Again
14. Campus Statistics
15. Exit

```

---

# Data Structures Used

## Singly Linked List

Used for storing student records.

Operations:

* Add Student
* Remove Student
* Search Student
* Display Students
* Sort Students

---

## Queue (FIFO)

Used for managing advising requests.

Operations:

* Enqueue advising request
* Dequeue advising request
* Display queue

---

## Two-Dimensional Vector

Used for storing the campus map.

Operations:

* Load map
* Display map
* Explore locations
* Count campus objects

---

# Design Overview

The application is organized into independent modules:

* **CampusMap** handles all campus map functionality.
* **StudentList** manages student records using a linked list.
* **QueueSystem** manages advising requests using a FIFO queue.
* **FileManager** manages reading data from files.
* **main.cpp** provides the menu interface and coordinates all program components.

---

# Testing

The following functionality has been tested:

* Loading campus maps
* Loading student records
* Displaying campus maps
* Exploring campus locations
* Displaying neighboring locations
* Counting campus objects
* Adding students
* Removing students
* Searching for students
* Displaying student records
* Sorting students by ID
* Adding advising requests
* Processing advising requests
* Displaying the advising queue
* Reloading student records
* Displaying campus statistics

---

# Known Limitations

* Student names and majors must be single words because student records are stored as space-separated values.
* Duplicate student IDs are not automatically prevented unless checked by the program.
* The program assumes correctly formatted input files.

---

# Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Linked Lists
* Queues (FIFO)
* Two-Dimensional Vectors
* File Input/Output (ifstream / ofstream)
* Modular Programming

---

# Conclusion

This project showcases the implementation of fundamental data structures and algorithms in C++. It integrates linked lists, queues, vectors, and file processing within a modular object-oriented design to create an interactive campus management system. The project focuses on efficient data organization, reusable code, and user-friendly interaction, while meeting the requirements of the Campus Exploration and Student Resource Management System assignment.
