# 🎓 Student Course Management System

This is a C++-based console application designed to manage student enrollments and course data efficiently. It simulates a basic academic management system that handles course registration, student details, and data persistence through text files.

## 🔧 Features
- **Student Management:** Add, view, and manage student records.
- **Course Management:** Input and maintain course-related data.
- **Data Validation:** Ensures proper input formatting and consistency.
- **File Handling:** 
  - Persistent storage via `student_data.txt`, `course_data.txt`, and `save.txt`.
  - Inputs and outputs are handled using file I/O for record retention.
- **Modular Code Structure:**
  - `classes.h` defines core classes.
  - `validation.h` includes data validation utilities.
  - `managementsystem.h` contains the management system logic.

## 📂 File Overview
- `classes.h`, `system.h`, `managementsystem.h`: Core logic and class definitions.
- `FileName.cpp`: Main implementation file.
- `*.txt`: Data files for storing and retrieving student/course information.

## 🛠️ How to Run
1. Compile using a C++ compiler (e.g., g++, Visual Studio).
2. Run the executable in a terminal.
3. Interact via the console-based menu.


## 🧭 Main Menu

```text
Main Menu
1 - Enroll a student
2 - Course Registration
3 - Attendance
4 - Marks
5 - Course Withdraw
6 - Exit

## 🚀 Contribute

Want to add features like a GUI, database integration, or more detailed reports?  
Fork this repository, make your changes, and submit a pull request.  
**Your improvements are welcome!**
