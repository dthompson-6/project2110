# Campus Exploration & Student Resource Management System

## Group Members
- Mufaro Ngwenya
- Dariga Thompson
- Teesha Talreja
- Charite Nzambi

---

## Milestone 1 Status

This submission covers the **Milestone 1 requirements**:
- Campus map loading
- Map display
- Linked list student insertion
- Student search
- Basic menu system
- Successful multi-file compilation

---

## Compilation

```bash
g++ main.cpp CampusMap.cpp StudentList.cpp FileManager.cpp -o project
```

or simply:

```bash
g++ *.cpp -o project
```

Requires a C++11-capable compiler (g++, clang++).

---

## Execution

```bash
./project
```

You will be prompted to enter the campus map filename at startup (e.g. `campus_map.txt`). No filenames are hardcoded.

---

## Input File Formats

### Campus Map (`campus_map.txt`)
```
<rows> <cols>
<symbol> <symbol> ...   (one row per line)
```

**Symbols:**
    Symbol     Meaning      
    R          Road         
    B          Building     
    C          Classroom    
    L          Library      
    P          Parking Lot  
    X          Blocked Area 

### Student Records (`students.txt`)
Space-separated, one student per line:
```
id name major gpa
```
Example:
```
3001 Aiden EE 3.79
3002 Bella CE 3.60
```
*(Note: this milestone adds students interactively through the menu; reading `students.txt` directly into the linked list is part of the file-processing requirement we'll finish for the final submission.)*

---

## Features Implemented (Milestone 1)

- **Campus Map (`CampusMap`)** — loads a map from file into a 2D grid, displays it, identifies location type at given coordinates, detects blocked areas, and shows up/down/left/right neighbors (no diagonal movement)
- **Student List (`StudentList`)** — singly linked list of `Student` records; supports adding a student and searching by ID
- **Menu System (`main.cpp`)** — text menu with input validation for all options

## Not Yet Implemented (planned for final submission, due 7/4)
- Student removal
- Sorting algorithm (bubble/selection/insertion) and full searching requirement
- Advising request queue
- Campus statistics module
- Loading student records directly from `students.txt` into the linked list (currently `FileManager::loadCampusMap` only loads the map; student file loading still needs to be added and wired into `main.cpp`)

---

## File Structure

File                     Responsibility                              

`main.cpp`               Entry point, menu loop, user interaction     
`CampusMap.h/.cpp`       2D grid map loading, display, exploration    
`StudentList.h/.cpp`     Linked list of students, add, search         
`FileManager.h/.cpp`     File I/O helper (map loading)                
`campus_map.txt`         Sample campus map input                      
`students.txt`           Sample student records (not yet auto-loaded) 

---

## Menu Options (Milestone 1)

```
1. Display Campus Map
2. Explore Location
3. Add Student
4. Search Student
5. Display All Students
6. Exit
```

---

## Known Bugs / Limitations
- Student records must currently be entered manually through the menu; file-based student loading is not yet wired into `main.cpp`
- Names/majors with spaces in `students.txt` won't be parsed correctly once file-loading is added, since the file uses space-separated fields — this needs to be addressed before the final submission
- No duplicate student ID check yet
- No removal, sorting, or statistics yet (planned for final submission)
- Other bugs have been fixed

---

## Data Structures Used So Far

Structure       |   Used For

Linked List        Student records (`StudentList`)
2D Vector          Campus map grid (`CampusMap`)  