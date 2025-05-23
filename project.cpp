#include <iostream>
#include <fstream>
#include "classes.h"
#include "managementsystem.h"
#include "system.h"
#include "validation.h"
#include "color.h"
#include<limits>

using namespace std;

Student::Student() : name(""), studentID(0) {}
Student::Student(string _name, int id)
{
	name = _name;
	studentID = id;
}

Course::Course() :courseName(""), enrolled(false) {}
Course::Course(string cname)
{
	courseName = cname;
	enrolled = false;
}

Attendance::Attendance() : studentID(0), daysPresent(0), daysAbsent(0) {}
Attendance::Attendance(int id, string cname, int present, int absent)
{
	studentID = id;
	courseName = cname;
	daysPresent = present;
	daysAbsent = absent;
}

Marks::Marks() : studentID(0), marks(0.0) {}
Marks::Marks(int id, string cname, float m)
{
	studentID = id;
	courseName = cname;
	marks = m;
}

void managementsystem::displayMainMenu()
{
	cout << ANSI_WHITE << "Main Menu\n" << ANSI_RESET << endl;
	cout << ANSI_ORANGE << "1- Enroll a student\n";
	cout << "2- Course Registration\n";
	cout << "3- Attendance\n";
	cout << "4- Marks\n";
	cout << "5- Course Withdraw\n";
	cout << "6- Take Feedback\n"; // New option for feedback
	cout << "7- Exit\n" << ANSI_RESET; // Adjusted for the new option
	cout << ANSI_WHITE << "\nPress 1 to 7 to select an option:\n " << ANSI_RESET;
}



void managementsystem::run()
{
	int choice;
	do
	{
		displayMainMenu();
		cout << endl;
		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number." << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice between 1 and 7: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			enrolledStudentMenu();
			break;
		case 2:
			courseRegistrationMenu();
			break;
		case 3:
			attendanceMenu();
			break;
		case 4:
			marksMenu();
			break;
		case 5:
			courseWithdrawMenu();
			break;
		case 6:
			takeFeedback(); // New case for feedback
			break;
		case 7:
			cout << ANSI_TEAL << endl << "Exiting the system.\n" << ANSI_RESET;
			break;
		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 7.\n" << ANSI_RESET << endl;
		}

	} while (choice != 7);
}


void managementsystem::enrolledStudentMenu()
{
	int choice;

	do
	{
		cout << ANSI_ORANGE << "\n1: Display already enrolled students" << endl;
		cout << "2: Add a Student" << endl;
		cout << "3: Remove a Student" << endl;
		cout << "4: Edit Student Detail" << endl;
		cout << "5: Back\n" << ANSI_RESET << endl;

		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number between 1 and 5: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayEnrolledStudents();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			removeStudent();
			break;
		case 4:
			editStudentDetails();
			break;
		case 5:
			void run();
			return;

		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 5.\n" << ANSI_RESET;
		}

	} while (choice != 5);
}


void managementsystem::courseRegistrationMenu()
{
	int choice;
	do
	{
		cout << ANSI_ORANGE << "\n1: Display Available Courses" << endl;
		cout << "2: Register Course" << endl;
		cout << "3. Display Registered courses" << endl;
		cout << "4: Back\n" << ANSI_RESET << endl;

		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number between 1 and 4: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayAvailableCourses();
			break;
		case 2:
			registerCourse();
			break;
		case 3:
			displayEnrolledCourses();
			break;
		case 4:
			void run();// No need to explicitly call run() function here
			return;

		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 4.\n" << ANSI_RESET;
		}

	} while (choice != 4);
}


void managementsystem::courseWithdrawMenu()
{
	int choice;
	do
	{
		cout << ANSI_ORANGE << "\n1: Enrolled Courses" << endl;
		cout << "2: Drop a Course" << endl;
		cout << "3: Back\n" << ANSI_RESET << endl;

		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number between 1 and 3: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayEnrolledCourses();
			break;
		case 2:
			dropCourse();
			break;
		case 3:
			// No need to explicitly call run() function here
			return;
		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 3.\n" << ANSI_RESET;
		}

	} while (choice != 3);
}


void managementsystem::attendanceMenu()
{
	int choice;
	do
	{
		cout << ANSI_ORANGE << "\n1: Display Attendance (Subject wise)" << endl;
		cout << "2: Mark Attendance" << endl;
		cout << "3: Back\n" << ANSI_RESET << endl;

		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a numberbetweeen 1 and 3: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayAttendance();
			break;
		case 2:
			markAttendance();
			break;
		case 3:
			// No need to explicitly call run() function here
			return;
		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 3.\n" << ANSI_RESET;
		}

	} while (choice != 3);
}


void managementsystem::marksMenu()
{
	int choice;
	do
	{
		cout << ANSI_ORANGE << "\n1: Display Marks (Subject wise)" << endl;
		cout << "2: Assign Marks" << endl;
		cout << "3: Back\n" << ANSI_RESET << endl;

		cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number between 1 and 3: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayMarks();
			break;
		case 2:
			assignMarks();
			break;
		case 3:
			// No need to explicitly call run() function here
			return;
		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 3.\n" << ANSI_RESET;
		}

	} while (choice != 3);
}


void managementsystem::takeFeedback()
{
	int choice;
	do
	{
		cout << ANSI_ORANGE << "\n1. Display Registered courses" << endl;
		cout << "2. Display Enrolled Students" << endl;
		cout << "3. Course Feedback" << endl;
		cout << "4. Back" << ANSI_RESET << endl;
		cout << ANSI_PINK << "\nEnter choice: " << ANSI_RESET;

		// Input validation for characters
		while (!(cin >> choice))
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << ANSI_RED << "Invalid input. Please enter a number between 1 and 4: " << ANSI_RESET << endl;
			cout << ANSI_PINK << "Enter choice: " << ANSI_RESET;
		}

		switch (choice)
		{
		case 1:
			displayEnrolledCourses();
			break;
		case 2:
			displayEnrolledStudents();
			break;
		case 3:
			enterFeedback();
			break;
		case 4:
			// No need to explicitly call run() function here
			return;
		default:
			cout << ANSI_RED << "\nInvalid choice. Please enter a number between 1 and 4.\n" << ANSI_RESET;
		}

	} while (choice != 4);
}


ofstream write;
void system::addStudent()
{
	string name;
	int studentID;

	write.open("save.txt", ios::app);

	if (studentCount < MAX_STUDENTS)
	{
		cout << "\nEnter student name: ";
		cin >> name;
		write << "Name : ";
		write << name << endl;
		// Assuming student IDs are unique for simplicity
		cout << "Enter student ID: ";
		cin >> studentID;
		write << "ID :";
		write << studentID << endl;
		// Check if the student is not already enrolled
		if (findStudent(studentID) == -1)
		{
			students[studentCount++] = Student(name, studentID);
			cout << ANSI_LIME << "\nStudent added successfully.\n " << ANSI_RESET;
		}
		else
		{
			cout << "Student with ID " << studentID << " is already enrolled.\n";
		}
	}
	else
	{
		cout << "Maximum number of students reached.\n";
	}
	write.close();
}

void system::displayEnrolledStudents() const 
{
	cout << "\nEnrolled Students are:\n" << endl;
	for (int i = 0; i < studentCount; ++i)
	{
		cout << "Student ID: " << ANSI_BLUE << students[i].studentID << ANSI_RESET << "\nName: " << ANSI_BLUE << students[i].name << ANSI_RESET << "\n";
	}
	cout << "\n";
}

void system::removeStudent()
{
	int studentID;

	write.open("save.txt", ios::app);

	cout << "\nEnter student ID to remove: ";
	cin >> studentID;

	int index = findStudent(studentID);

	if (index != -1)
	{
		// Shift elements to remove the student
		for (int i = index; i < studentCount - 1; ++i)
		{
			students[i] = students[i + 1];
		}
		--studentCount;
		cout << ANSI_BLUE << "\nStudent removed successfully.\n" << ANSI_RESET;
	}
	else
	{
		cout << ANSI_RED << "\nStudent with ID " << studentID << " not found.\n" << ANSI_RESET;
	}
	write.close();
}

void system::editStudentDetails()
{
	int studentID;
	write.open("save.txt", ios::app);

	cout << "\nEnter student ID to edit details: ";
	cin >> studentID;

	int index = findStudent(studentID);

	if (index != -1)
	{

		cout << "Enter new name: ";
		cin >> students[index].name;
		write << "Edited Student Name :";
		write << students[index].name << endl;
		cout << ANSI_BLUE << "\nStudent details updated successfully.\n" << ANSI_RESET;
	}
	else
	{
		cout << ANSI_RED << "Student with ID " << studentID << " not found.\n" << ANSI_RESET;
	}
	write.close();
}

void system::enterFeedback()
{
	int studentID;
	ofstream feedbackFile("course_feedback.txt", ios::app); // Open file in append mode

	cout << "\nEnter student ID to add Feedback: ";
	cin >> studentID;
	cout << endl;

	int index = findStudent(studentID);

	if (index != -1)
	{
		string feedback;
		cin.ignore(); // Ignore previous newline character

		cout << ANSI_MAGENTA << "Please provide your feedback: " << ANSI_RESET << endl;
		getline(cin, feedback); // Read the entire line of feedback
		cout << ANSI_LIME << "\nThank you for your feedback:\n" << ANSI_RESET << feedback << endl;

		if (feedbackFile.is_open())
		{
			feedbackFile << feedback << endl; // Write feedback to the file
			cout << ANSI_BLUE << "\nFeedback has been saved!\n " << ANSI_RESET << endl;
		}
		else
		{
			cout << "Unable to open file to save feedback.\n";
		}
		feedbackFile.close(); // Close the file
	}
	else
	{
		cout << ANSI_RED << "Student with ID " << studentID << " not found.\n" << ANSI_RESET << endl;
	}
}

system::system() //:studentCount(0)
{
	courses[0] = Course("Math");
	courses[1] = Course("Physics");
	courses[2] = Course("Chemistry");
	courses[3] = Course("PakistanStudy");
	courses[4] = Course("ComputerScience");
	courses[5] = Course("Islamiat");
	courses[6] = Course("Calculus");
	courses[7] = Course("DLD");
	courses[8] = Course("COAL");
	courses[9] = Course("OOP");

	readStudentData("student_data.txt");  // Replace with your actual file name
	readCourseData("course_data.txt");


	for (int i = 0; i < MAX_STUDENTS; ++i)
	{
		for (int j = 0; j < MAX_COURSES; ++j)
		{
			courseEnrollment[i][j] = false;
		}
	}
	//int k = 0;
	bool k = true;
	for (int i = 0; i < MAX_STUDENTS; ++i)
	{
		for (int j = 0; j < MAX_COURSES; ++j)
		{
			// Check if the course is enrolled
			if (courses[j].enrolled)
			{
				courseEnrollment[i][j] = true;
				//k = false;
				//break;
			/*	if (k == 2)
				{

				break;
				}

			k++;
			   i++;*/

			}

		}
		/*	if (k == 2)
			{
				break;
			}*/
		if (k == false)
		{
			break;
		}
	}

	cout << endl;
}

void system::readStudentData(string filename)
{
	ifstream inputfile(filename);

	if (!inputfile.is_open())
	{
		cout << ANSI_YELLOW << "Error opening the file : " << ANSI_RESET << filename << endl;
		return;
	}

	while (!inputfile.eof() && studentCount < MAX_STUDENTS)
	{
		string name;
		int id;

		inputfile >> name >> id;

		if (inputfile.fail())
		{
			break;
		}

		if (findStudent(id) == -1)
		{
			students[studentCount++] = Student(name, id);
		}
		else
			cout << "Student with ID " << ANSI_BLUE << id << ANSI_RESET << " is already Enrolled" << endl;
	}

	inputfile.close();
}

void system::readCourseData(string filename)
{
	ifstream inputfile(filename);

	if (!inputfile.is_open())
	{
		cout << ANSI_YELLOW << "Error opening the file : " << ANSI_RESET << filename << endl;
		return;
	}

	for (int i = 0; i < MAX_COURSES; ++i)
	{
		string courseName;
		inputfile >> courseName;

		if (inputfile.fail())
		{
			break;
		}

		courses[i] = Course(courseName);
		courses[i].enrolled = true;
		// courseEnrollment[1][0] = true;
		readMarksAndAttendanceData(inputfile, i);
	}
	inputfile.close();
}

void system::readMarksAndAttendanceData(ifstream& inputFile, int courseIndex)
{
	for (int i = 0; i < MAX_STUDENTS && !inputFile.eof(); ++i)
	{
		int studentID;
		string courseName;
		float studentMarks;
		int daysPresent;
		int daysAbsent;

		inputFile >> studentID >> courseName >> studentMarks >> daysPresent >> daysAbsent;

		if (inputFile.fail())
		{
			break;
		}

		int studentIndex = findStudent(studentID);

		if (studentIndex != -1 && courseIndex != -1 && courses[courseIndex].enrolled)
		{
			// Update marks and attendance data for the specific student and course
			marks[studentIndex * MAX_COURSES + courseIndex] = Marks(studentID, courseName, studentMarks);
			attendance[studentIndex * MAX_COURSES + courseIndex] = Attendance(studentID, courseName, daysPresent, daysAbsent);
		}
		else
		{
			cout << ANSI_RED << "Invalid student ID or course name in the file.\n" << ANSI_RESET;
		}
	}
}

void system::displayAvailableCourses()const
{
	cout << "\nAvailable Courses:\n" << endl;
	for (int i = 0; i < MAX_COURSES; ++i)
	{
		cout << i + 1 << "- " << courses[i].courseName;
		if (courses[i].enrolled)
		{
			cout << ANSI_PINK << " (Enrolled)" << ANSI_RESET;
		}
		cout << "\n";
	}
	cout << "\n";
}

void system::registerCourse()
{
	int courseIndex;
	int sid;
	write.open("save.txt", ios::app);

	cout << "\nEnter the student ID: ";
	cin >> sid;
	int studentIndex = findStudent(sid);

	if (studentIndex != -1)
	{
		cout << "Enter the number of the course to register: ";
		cin >> courseIndex;

		if (courseIndex >= 1 && courseIndex <= MAX_COURSES)
		{
			Course& selectedCourse = courses[courseIndex - 1];

			// Check if the course is enrolled
			if (!(selectedCourse.enrolled))
			{
				selectedCourse.enrolled = true;
				// Assuming each student can register for a course only once
				if (!courseEnrollment[studentIndex][courseIndex - 1])
				{
					courseEnrollment[studentIndex][courseIndex - 1] = true;
					cout << ANSI_BLUE << "\nCourse registration successful.\n";

					write << "Register Course for Student " << ANSI_BLUE << sid << ANSI_RESET << " :" << endl;
					write << courseIndex << endl;

				}
				else
				{
					cout << "\nYou are already enrolled in this course.\n";
				}
			}
			else
			{
				cout << "\nCourse not found or not enrolled.\n";
			}
		}
		else
		{
			cout << ANSI_RED << "Invalid course number.\n" << ANSI_RESET;
		}
	}
	else
		cout << ANSI_RED << "The Student ID you Entered is not registered\n" << ANSI_RESET << endl;
	cout << endl;
	write.close();
}

void system::displayEnrolledCourses()const
{
	int studentID;

	cout << "\nEnter student ID to display registered courses: ";
	cin >> studentID;
	cout << endl;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Registered courses for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << ":\n" << endl;

		bool has = false;

		for (int i = 0; i < MAX_COURSES; ++i)
		{
			if (courseEnrollment[studentIndex][i])
			{
				if (courses[i].enrolled)
				{  // Check if the course is still enrolled
					cout << courses[i].courseName << "\n";
					has = true;
				}
				else
				{
					cout << courses[i].courseName << " (Dropped)\n";
				}
			}
		}

		if (!has)
		{
			cout << "No enrolled courses found.\n";
		}
	}
	else
	{
		cout << ANSI_RED << "Student not found.\n" << ANSI_RESET;
	}
	cout << endl;
}

void system::displayAttendance()const
{
	int studentID;
	cout << "\nEnter student ID to display attendance: ";
	cin >> studentID;
	cout << endl;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Attendance for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << ":\n";



		for (int i = 0; i < MAX_COURSES; ++i)
		{

			int attendanceIndex = studentIndex * MAX_COURSES + i;

			// Check if the course is enrolled before displaying attendance
			if (courseEnrollment[studentIndex][i])
			{
				cout << "\nCourse: " << courses[i].courseName << "\nDays Present: " << attendance[attendanceIndex].daysPresent << "\nDays Absent: " << attendance[attendanceIndex].daysAbsent << "\n";
			}

		}

	}
	else
	{
		cout << ANSI_PINK << "Student not found.\n" << ANSI_RESET;
	}
}

void system::markAttendance()
{
	int studentID;
	string courseName;
	int daysPresent;
	int daysAbsent;
	write.open("save.txt", ios::app);

	cout << "\nEnter student ID: ";
	cin >> studentID;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Enter course name: ";
		cin >> courseName;

		int courseIndex = findCourse(courseName);

		if (courseIndex != -1 && courses[courseIndex].enrolled && courseEnrollment[studentIndex][courseIndex])
		{
			cout << "\nEnter days present for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << " in " << courseName << ": ";
			cin >> daysPresent;

			cout << "Enter days Absent for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << " in " << courseName << ": ";
			cin >> daysAbsent;

			// Update only the attendance for the specific course if enrolled
			if (courseEnrollment[studentIndex][courseIndex])
			{
				attendance[studentIndex * MAX_COURSES + courseIndex] = Attendance(studentID, courseName, daysPresent, daysAbsent);
				cout << "\nAttendance marked successfully.\n";

				write << "Attendance of Student with ID " << studentID << " In the course " << courseName << " :";
				write << daysPresent << endl;

				write << "Attendance of student with ID " << studentID << " In the course " << courseName << " :";
				write << daysAbsent << endl;
			}
			else
			{
				cout << ANSI_RED << "Student not enrolled in the specified course.\n" << ANSI_RESET;
			}
		}
		else
		{
			cout << ANSI_RED << "\nCourse not found or not enrolled.\n" << ANSI_RESET;
		}
	}
	else
	{
		cout << "Student not found.\n";
	}
	write.close();
}

void system::displayMarks()
{
	int studentID;
	cout << "\nEnter student ID to display marks: ";
	cin >> studentID;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Marks for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << ":\n" << endl;

		for (int i = 0; i < MAX_COURSES; ++i)
		{
			int markindex = studentIndex * MAX_COURSES + i;

			// Check if the course is enrolled before displaying marks
			if (courses[i].enrolled && courseEnrollment[studentIndex][i])
			{
				cout << "Course: " << courses[i].courseName << "\nMarks: " << marks[markindex].marks << "\n";
			}
		}
	}
	else
	{
		cout << ANSI_RED << "Student not found or studentID is Invalid.\n" << ANSI_RESET;
	}
}

void system::assignMarks()
{
	int studentID;
	string courseName;
	float studentMarks;  // Use a different name for the variable to store marks
	write.open("save.txt", ios::app);

	cout << "\nEnter student ID: ";
	cin >> studentID;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Enter course name: ";
		cin >> courseName;
		cout << endl;

		int courseIndex = findCourse(courseName);

		if (courseIndex != -1 && courses[courseIndex].enrolled && courseEnrollment[studentIndex][courseIndex])
		{
			cout << "Enter marks for " << ANSI_BLUE << students[studentIndex].name << ANSI_RESET << " in " << courseName << ": ";
			cin >> studentMarks;
			cout << endl;

			// Use a different name for the variable to store marks
			marks[studentIndex * MAX_COURSES + courseIndex] = Marks(studentID, courseName, studentMarks);
			cout << "Marks assigned successfully.\n";

			write << "Marks of Student with ID " << studentID << " In the Course " << courseName << " :";
			write << studentMarks << endl;
		}
		else
		{
			cout << ANSI_RED << "Course not found, not enrolled, or marks cannot be assigned for this course.\n" << ANSI_RESET;
		}
	}
	else
	{
		cout << "Student not found.\n";
	}
	write.close();
}

void system::dropCourse()
{
	int studentID;
	string courseName;
	write.open("save.txt", ios::app);

	cout << "\nEnter student ID: ";
	cin >> studentID;

	int studentIndex = findStudent(studentID);

	if (studentIndex != -1)
	{
		cout << "Enter course name to drop: ";
		cin >> courseName;

		int courseIndex = findCourse(courseName);

		if (courseIndex != -1 && courseEnrollment[studentIndex][courseIndex])
		{
			// Unenroll the student from the course
			courseEnrollment[studentIndex][courseIndex] = false;

			// Displaying a message about the dropped course
			cout << "Course " << ANSI_BLUE << courseName << ANSI_RESET << " dropped successfully.\n";
			write << "Student with ID " << ANSI_BLUE << studentID << ANSI_RESET << "Dropped the subject :" << ANSI_BLUE << courseName << ANSI_RESET << endl;
		}
		else
		{
			cout << "Course not found or not enrolled.\n";
		}
	}
	else
	{
		cout << "Student not found.\n";
	}
	write.close();
}


int validation::findStudent(int studentID)const
{
	for (int i = 0; i < studentCount; ++i)
	{
		if (students[i].studentID == studentID)
		{
			return i;
		}
	}
	return -1; // Not found
}

int validation::findCourse(const string& courseName)const
{
	for (int i = 0; i < MAX_COURSES; ++i)
	{
		if (courses[i].courseName == courseName)
		{
			return i;
		}
	}
	return -1; // Not found
}

int main()
{
	cout << "\t\t\t\t\t**STUDENT COURSE/FLEX MANAGEMENT SYSTEM" << endl << endl;

	managementsystem m;
	m.run();

	return 0;
}
