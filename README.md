# CS-300 Project Two: Course Planner

## Overview
This repository contains my final project for CS-300 at Southern New Hampshire University. The project focuses on developing a Course Planner application using different data structures to load, store, and search course data. The final implementation utilizes a hash table for efficient course retrieval and prerequisite lookup.

## Project Summary
The Course Planner application reads course data from a file, stores it into a hash table, and allows users to:
- Load course data into memory.
- Display a sorted list of all courses.
- Search for and display details for a specific course.

The goal was to design a program that efficiently handles course lookups while practicing the implementation and analysis of different data structures.

## Technologies Used
- C++ 
- Standard Template Library (STL): `unordered_map`, `vector`, `algorithm`, `iostream`, `fstream`, `sstream`.

## Data Structures Implemented
- **Vector:** Used for temporary storage during data parsing.
- **Hash Table (unordered_map):** Used for efficient storage and retrieval of course data.
- **Sorting Algorithm:** Courses are sorted using `std::sort()` before displaying.

---

## Runtime Analysis

### Vector-Based Search:

| Code Line                        | Cost | # Times Executes | Total Cost |
|-----------------------------------|------|-------------------|------------|
| FOR EACH course IN courseList     | 1    | n                 | n          |
| IF course.courseNumber == userInput | 1  | n                 | n          |
| FOR EACH prereq IN course.prerequisites | 1 | 1            | 1          |
| PRINT each prereq                | 1    | n                 | n          |

**Total Cost:** 3n + 1  
**Runtime Complexity:** O(n)

### Hash Table-Based Search:
- Lookup operation: O(1) on average
- Insert operation: O(1) on average
- Delete operation: O(1) on average

### Binary Search Tree (Balanced):
- Lookup operation: O(log n)
- Insert operation: O(log n)
- Delete operation: O(log n)

### Binary Search Tree (Unbalanced worst case):
- Lookup operation: O(n)
- Insert operation: O(n)
- Delete operation: O(n)

**Final Recommendation:**  
The hash table was chosen for the final implementation due to its average-case constant time lookup, making it highly efficient for key-based access of course information.

---

## Reflection

**What was the problem you were solving in the projects for this course?**  
The problem was to design a Course Planner program that can efficiently load, store, and retrieve course data, including course prerequisites, from a file. The program needed to handle large sets of data and provide quick access to individual courses for academic advising purposes.

**How did you approach the problem? Consider why data structures are important to understand.**  
I approached the problem by first evaluating multiple data structures: vector, hash table, and binary search tree. Each structure was analyzed for its performance, complexity, and suitability for the problem. Since course numbers serve as unique identifiers, a hash table provided the best balance of simplicity and performance for key-based lookups.

**How did you overcome any roadblocks you encountered while going through the activities or project?**  
One of the main challenges was properly parsing the input file and handling cases with missing or malformed data. I overcame these issues by adding validation checks and informative error messages to ensure that invalid records did not crash the program. Debugging file input/output was also a key learning experience that helped me improve error handling.

**How has your work on this project expanded your approach to designing software and developing programs?**  
This project expanded my understanding of selecting appropriate data structures based on the problem requirements. It taught me the importance of considering both average and worst-case performance when making design choices. Additionally, I gained more experience with modular design by separating file loading, searching, and user interface logic.

**How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**  
I have learned to write cleaner, modular code that separates concerns into distinct functions. Using clear variable names, adding comments, and handling errors gracefully all contribute to code that is easier to maintain and adapt in the future. This project reinforced the value of designing software with scalability and readability in mind.

---
