# CS-300 Final Project: Course Planner

## Overview

This project was developed as part of the CS-300 Data Structures and Algorithms course at Southern New Hampshire University (SNHU). The application simulates a simple **Course Planner System** that allows users to load course data, view all courses, and display individual course details including prerequisites.

## Features

- **Load Course Data:** Read course information from a CSV file.
- **Display All Courses:** List all courses in alphanumeric order.
- **Search Course:** View details for a specific course, including prerequisites.

## Files Included

- `ProjectTwo.cpp` — The main C++ source code implementing the course planner application.
- `README.md` — This documentation file.

## Program Details

- The program uses:
  - C++ Standard Library (`iostream`, `fstream`, `sstream`, `unordered_map`, `vector`, `algorithm`).
  - A `Course` struct to store course number, title, and prerequisites.
  - A hash map (`unordered_map`) for efficient course lookup.
  - File parsing to load data from a CSV file into the course structure.
  - Sorting and searching capabilities for user interaction.

### Menu Options
