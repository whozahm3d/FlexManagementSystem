# 🎓 Student Course Management System

This is a modular, menu-driven **C++ console application** for managing students, courses, attendance, and marks. It provides a simple yet structured solution for small academic institutions or test environments to handle student and course-related operations.

---

## 📌 Features

### 👤 Student Enrollment
- Add new students with unique IDs and names.
- View already enrolled students.

### 📚 Course Registration
- Register students in various courses.
- Each student can enroll in multiple courses.

### 🗓️ Attendance Management
- Record attendance for each student per course.
- View attendance records.
- Supports marking present days per student per course.

### 🧮 Marks Management
- Enter marks for each student in each course.
- View student marks.
- Basic grading data structure supported via `Marks` class.

### ❌ Course Withdrawal
- Students can be withdrawn from courses.
- The system updates registration and related records.

### 💾 File Handling (Persistence)
- Data for students, courses, attendance, and marks are stored in `.txt` files:
  - `student_data.txt`, `course_data.txt`, `save.txt`
- Allows reloading and saving the state across program runs.

---

## 🗂️ File Structure

| File | Description |
|------|-------------|
| `FileName.cpp` | Main driver code for the system |
| `classes.h` | Contains definitions for `Student`, `Course`, `Attendance`, and `Marks` classes |
| `managementsystem.h` | Manages core functions and menus |
| `system.h`, `global.h` | Support functions and global variables |
| `validation.h` | Handles input validation logic |
| `*.txt` | Text files used for data storage |

---

## 🛠️ How to Compile and Run

### 🔹 Using g++ (Linux/Windows)

```bash
g++ FileName.cpp -o StudentManagement
./StudentManagement
