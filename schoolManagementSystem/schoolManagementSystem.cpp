
/*
This is a school management system which looks after
- student information
- faculty information
- library information
- course information
- exam information
*/

#include<bits/stdc++.h>

using namespace std;

class school;
class intro{
    public:
        void mainintro(){   //the first main screen of the management system
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                        WELCOME TO SCHOOL MANAGEMENT SYSTEM"<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"PRESS THE NUMBER TO CONTINUE"<<endl;
        cout<<"1. START EXPLORING."<<endl;
        cout<<"2. ABOUT PROJECT."<<endl;
        cout<<"3. CREDITS FOR THE PROJECT."<<endl;
        cout<<"4. EXIT."<<endl;
        cout<<"Your choice --> "<<endl;
    }

    void about(){    //about school
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      ABOUT school                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"SCHOOL MANAGEMENT SYSTEM , this project looks after all the processes happening in a school and stores information about /n - students /n - faculty /n it facilitates working of school efficiently."<<endl;
        cout<<endl<<"***************************************************************************************************"<<endl<<endl;
    }

    void credits(){    //names of the project group members
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                            CREDITS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"                      This is the Project for CODXO internship gold badge made by -                       "<<endl<<endl;
        cout<<"                      Kartikey Bora                                                           "<<endl<<endl;
        cout<<"                      COLLEGE -   JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY    "<<endl<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
    }

    void main_exit(){                  //end screen of the game
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                       THANKS FOR VISITING                                        "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        exit(0);
    }

    void exploremain(){
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                             WELCOME TO THE school MANAGEMENT SYSTEM "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"WHAT INFORMATION DO YOU WANT TO MANAGE -->\nPRESS THE NUMBER TO CONTINUE"<<endl;
        cout<<"1. STUDENT INFORMATION."<<endl;
        cout<<"2. FACULTY INFORMATION."<<endl;
        cout<<"3. COURSE INFORMATION."<<endl;
        cout<<"4. EXAM INFORMATION."<<endl;
        cout<<"5. LIBRARY INFORMATION."<<endl;
        cout<<"6. EXIT."<<endl;
        cout<<"Your choice --> "<<endl;
    }

    int again(){
    string c;
    AGAIN:
    cout<<"\n\nDo you want to explore more(yes/no) : ";
    cin>>c;
    system("CLS");
    if(c=="yes" || c=="Yes" || c=="y" || c=="Y" || c=="YES")
        return 1;
    else if(c=="no" || c=="No" || c=="n" || c=="N" || c=="NO")
        main_exit();
    else {
            cout<<"*****************Please enter a valid input****************"<<endl<<endl;
        goto AGAIN;
    }
    }
};

class Student {
public:
    string name;
    int rollNumber;
    string course;
    double marks;
};

// Faculty class to store faculty information
class Faculty {
public:
    string name;
    string designation;
    string department;
    string contactInfo;
};

//initializing variables
const int MAX_STUDENTS = 100;
const int MAX_FACULTY = 50;
const int MAX_BOOKS = 30;
const string id="root";
const string pass="123";


// Subject class to represent a subject in a linked list
class Subject {
public:
    string name;
    int attendance[MAX_STUDENTS]; // Dynamic array to store attendance information
    Subject* next;
    int temp=0;

    Subject(const string& subjectName) : name(subjectName), next(nullptr) {}

    // Function to mark attendance for a student
    void markAttendance(int rollNumber) {
        // Assuming rollNumber is a valid index in the attendance array
        attendance[temp++] = 1; // Marking attendance
    }

    // Function to calculate attendance percentage
    double calculateAttendancePercentage(int totalStudents) {
        if (totalStudents == 0) {
            return 0.0; // Avoid division by zero
        }

        int presentCount = 0;
        for (int i = 0; i < totalStudents; ++i) {
            if (attendance[i] == 1) {
                presentCount++;
            }
        }

        return static_cast<double>(presentCount) / totalStudents * 100.0;
    }
};

class library{
public:
    string studname;
    string bookname;
    string issuedate;
    int rollno;
};

class Course {
public:
    string name;
    Course* left;
    Course* right;
    Subject* subjects; // Linked list of subjects for this course

    Course(const string& courseName) : name(courseName), left(nullptr), right(nullptr), subjects(nullptr) {}
};


class Question {
public:
    string questionText;
    int marks;

    Question(const string& text, int marks) : questionText(text), marks(marks) {}
};

// Exam class to manage exam-related tasks
class Exam {
private:
    stack<Question> questionPaper; // Stack to organize question papers
    queue<pair<int, int>> examResults; // Queue to record exam results (rollNumber, marks)

public:
    // Function to generate a question paper randomly
    void generateQuestionPaper() {
        // Assuming there are three questions available for the exam
        questionPaper.push(Question("What is the capital of France?", 5));
        questionPaper.push(Question("Who wrote 'Romeo and Juliet'?", 7));
        questionPaper.push(Question("What is the formula for the area of a circle?", 8));

        cout << "Question paper generated successfully.\n\n";
        int i=1;
        while(!questionPaper.empty()){
            Question temp=questionPaper.top();
            questionPaper.pop();
            cout<<i<<"  "<<temp.questionText<<"  "<<temp.marks<<"\n";
            i++;
        }
    }

    // Function to record exam results
    void recordExamResult(int rollNumber, int marksObtained) {
        examResults.push({rollNumber, marksObtained});
        cout << "Exam result recorded for Roll Number " << rollNumber << ".\n";
    }

    // Function to compute grades based on marks obtained
    void computeGrades() {
        while (!examResults.empty()) {
            pair<int, int> result = examResults.front();
            int rollNumber = result.first;
            int marks = result.second;

            char grade;
            if (marks >= 8) {
                grade = 'A';
            } else if (marks >= 6) {
                grade = 'B';
            } else if (marks >= 4) {
                grade = 'C';
            } else {
                grade = 'F';
            }

            cout << "Roll Number " << rollNumber << " obtained " << marks << " marks. Grade: " << grade << "\n";

            examResults.pop();
        }
    }
};

class school:public intro ,public Exam{

public:

    library li[MAX_BOOKS];
    Student students[MAX_STUDENTS];
    Faculty faculty[MAX_FACULTY];
    int studentCount=0;
    int facultyCount=0;
    int bookcount=0;

    //adding a new issued book to system
    void addissue(const library& newli){
        if(bookcount<MAX_BOOKS){
            li[bookcount++]=newli;
            cout<<"Book issued,\n";
        }
        else{
            cout<<"Error : Maximum book issue limit reached\n";
        }
    }

    //total books issued
    int noofbooks(){
        return bookcount;
    }

    // Function to search for a book issue
    void searchbook(int rollNumber) {
        for (int i = 0; i < bookcount; ++i) {
            if (li[i].rollno == rollNumber) {
                cout << "Student found who issued book :\n";
                cout << "Name of student : " << li[i].studname << "\n";
                cout << "Roll Number : " << li[i].rollno << "\n";
                cout << "Book Name : " << li[i].bookname << "\n";
                cout << "Issue date : " << li[i].issuedate << "\n";
                return;
            }
        }
        cout << "Error: Student entry not found.\n";
    }

    //remove a issue book
    void deletebook(int rollNumber) {
        for (int i = 0; i < bookcount; ++i) {
            if (li[i].rollno == rollNumber) {
                for (int j = i; j < bookcount - 1; ++j) {
                    li[j] = li[j + 1];
                }
                --bookcount;
                cout << "Book issue details deleted successfully.\n";
                return;
            }
        }
        cout << "Error: Book issue not found.\n";
    }

    // Function to add a new student
    void addStudent(const Student& newStudent) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = newStudent;
            cout << "Student added successfully.\n";
        } else {
            cout << "Error: Maximum number of students reached.\n";
        }
    }

    // Function to update student information
    void updateStudent(int rollNumber, const Student& updatedStudent) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].rollNumber == rollNumber) {
                students[i] = updatedStudent;
                cout << "Student information updated successfully.\n";
                return;
            }
        }
        cout << "Error: Student not found.\n";
    }

    // Function to delete a student
    void deleteStudent(int rollNumber) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].rollNumber == rollNumber) {
                for (int j = i; j < studentCount - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --studentCount;
                cout << "Student deleted successfully.\n";
                return;
            }
        }
        cout << "Error: Student not found.\n";
    }

    // Function to search for a student
    void searchStudent(int rollNumber) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].rollNumber == rollNumber) {
                cout << "Student found:\n";
                cout << "Name: " << students[i].name << "\n";
                cout << "Roll Number: " << students[i].rollNumber << "\n";
                cout << "Course: " << students[i].course << "\n";
                cout << "Marks: " << students[i].marks << "\n";
                return;
            }
        }
        cout << "Error: Student not found.\n";
    }

    // Function to add a new faculty member
    void addFaculty(const Faculty& newFaculty) {
        if (facultyCount < MAX_FACULTY) {
            faculty[facultyCount++] = newFaculty;
            cout << "Faculty member added successfully.\n";
        } else {
            cout << "Error: Maximum number of faculty members reached.\n";
        }
    }

    // Function to update faculty information
    void updateFaculty(const string& name, const Faculty& updatedFaculty) {
        for (int i = 0; i < facultyCount; ++i) {
            if (faculty[i].name == name) {
                faculty[i] = updatedFaculty;
                cout << "Faculty member information updated successfully.\n";
                return;
            }
        }
        cout << "Error: Faculty member not found.\n";
    }

    // Function to delete a faculty member
    void deleteFaculty(const string& name) {
        for (int i = 0; i < facultyCount; ++i) {
            if (faculty[i].name == name) {
                for (int j = i; j < facultyCount - 1; ++j) {
                    faculty[j] = faculty[j + 1];
                }
                --facultyCount;
                cout << "Faculty member deleted successfully.\n";
                return;
            }
        }
        cout << "Error: Faculty member not found.\n";
    }

    // Function to search for a faculty member
    void searchFaculty(const string& name) {
        for (int i = 0; i < facultyCount; ++i) {
            if (faculty[i].name == name) {
                cout << "Faculty member found:\n";
                cout << "Name: " << faculty[i].name << "\n";
                cout << "Designation: " << faculty[i].designation << "\n";
                cout << "Department: " << faculty[i].department << "\n";
                cout << "Contact Information: " << faculty[i].contactInfo << "\n";
                return;
            }
        }
        cout << "Error: Faculty member not found.\n";
    }

    Course* coursesRoot; // Root of the binary search tree for courses


    school() : studentCount(0), facultyCount(0) , coursesRoot(nullptr){}

    // Function to add a new course
    void addCourse(const string& courseName) {
        coursesRoot = insertCourse(coursesRoot, courseName);
        cout << "Course added successfully.\n";
    }

    // Function to assign a subject to a course
    void assignSubject(const string& courseName, const string& subjectName) {
        Course* course = findCourse(coursesRoot, courseName);
        if (course) {
            Subject* newSubject = new Subject(subjectName);
            newSubject->next = course->subjects;
            course->subjects = newSubject;
            cout << "Subject assigned to the course successfully.\n";
        } else {
            cout << "Error: Course not found.\n";
        }
    }

    // Function to display course-related information
    void displayCourseInfo(const string& courseName) {
        Course* course = findCourse(coursesRoot, courseName);
        if (course) {
            cout << "Course Name: " << course->name << "\n";
            cout << "Subjects:\n";
            displaySubjects(course->subjects);
        } else {
            cout << "Error: Course not found.\n";
        }
    }

    // Function to mark attendance for a student in a subject
    void markAttendance(const string& courseName, const string& subjectName, int rollNumber) {
        Course* course = findCourse(coursesRoot, courseName);
        if (course) {
            Subject* subject = findSubject(course->subjects, subjectName);
            if (subject) {
                subject->markAttendance(rollNumber);
                cout << "Attendance marked successfully.\n";
            } else {
                cout << "Error: Subject not found.\n";
            }
        } else {
            cout << "Error: Course not found.\n";
        }
    }

    // Function to calculate attendance percentage for a subject
    double calculateAttendancePercentage(const string& courseName, const string& subjectName) {
        Course* course = findCourse(coursesRoot, courseName);
        if (course) {
            Subject* subject = findSubject(course->subjects, subjectName);
            if (subject) {
                return subject->calculateAttendancePercentage(studentCount);
            } else {
                cout << "Error: Subject not found.\n";
            }
        } else {
            cout << "Error: Course not found.\n";
        }
        return 0.0;
    }


    // Helper function to insert a course into the binary search tree
    Course* insertCourse(Course* root, const string& courseName) {
        if (root == nullptr) {
            return new Course(courseName);
        }

        if (courseName < root->name) {
            root->left = insertCourse(root->left, courseName);
        } else if (courseName > root->name) {
            root->right = insertCourse(root->right, courseName);
        }

        return root;
    }

    // Helper function to find a course in the binary search tree
    Course* findCourse(Course* root, const string& courseName) {
        if (root == nullptr || root->name == courseName) {
            return root;
        }

        if (courseName < root->name) {
            return findCourse(root->left, courseName);
        } else {
            return findCourse(root->right, courseName);
        }
    }

    // Helper function to display subjects in a linked list
    void displaySubjects(Subject* head) {
        while (head) {
            cout << "- " << head->name << "\n";
            head = head->next;
        }
    }

    // Helper function to find a subject in a linked list
    Subject* findSubject(Subject* head, const string& subjectName) {
        while (head) {
            if (head->name == subjectName) {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }

    int worklib(){
        mainlibrary:
        int choicelib;
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      MANAGING LIBRARY DETAILS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout << "1. Add a book issue\n";
        cout << "2. Number of books issued\n";
        cout << "3. Delete book issue\n";
        cout << "4. Search for a book issue\n";
        cout << "5. Go Back \n";
        cout << ("******************************************************************************\n");
        cout << "ENTER YOUR CHOICE : \n";
        cin>>choicelib;
        if(choicelib==5){
                system("CLS");
            return 1;
        }
        else if(choicelib==4){
            int rollNumber;
                cout << "\nEnter roll number of the student to search for his book issue: ";
                cin >> rollNumber;
                searchbook(rollNumber);
        }
        else if(choicelib==3){
            int rollNumber;
                cout << "\nEnter roll number of the student to delete his book issue: ";
                cin >> rollNumber;
                deletebook(rollNumber);
        }
        else if(choicelib==2){
            cout<<"\n\nTotal number of book issues for now are "<<noofbooks()<<endl<<endl;
        }
        else if(choicelib==1){
            library templi;
                cout << "\nEnter student name: ";
                getline(cin>>ws,templi.studname);
                cout << "Enter book name: ";
                getline(cin>>ws,templi.bookname);
                cout << "Enter issue date: ";
                getline(cin>>ws,templi.issuedate);
                cout << "Enter roll number: ";
                cin >> templi.rollno;
                addissue(templi);
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto mainlibrary;
        }
        int t3=again();
                if(t3==1)
                    return 1;
    }

    int workStudent(){
        mainstudent:
        int choicestud;
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      MANAGING STUDENT DETAILS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout << "1. Add Student\n";
        cout << "2. Update Student Information\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Go Back \n";
        cout << ("******************************************************************************\n");
        cout << "ENTER YOUR CHOICE : \n";
        cin>>choicestud;
        if(choicestud==5){
                system("CLS");
            return 1;
        }
        else if(choicestud==4){
            int rollNumber;
                cout << "\nEnter roll number of the student to search: ";
                cin >> rollNumber;
                searchStudent(rollNumber);
        }
        else if(choicestud==3){
            int rollNumber;
                cout << "\nEnter roll number of the student to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
        }
        else if(choicestud==2){
            int roll;
                cout << "\nEnter roll number of the student to update: ";
                cin >> roll;
                Student updatedStudent;
                updatedStudent.rollNumber=roll;
                cout << "Enter updated student name: ";
                getline(cin>>ws,updatedStudent.name);
                cout << "Enter updated course: ";
                getline(cin>>ws,updatedStudent.course);
                cout << "Enter updated marks: ";
                cin >> updatedStudent.marks;
                updateStudent(roll, updatedStudent);
        }
        else if(choicestud==1){
            Student newStudent;
                cout << "\nEnter student name: ";
                getline(cin>>ws,newStudent.name);
                cout << "Enter roll number: ";
                cin >> newStudent.rollNumber;
                cout << "Enter course: ";
                getline(cin>>ws,newStudent.course);
                cout << "Enter marks: ";
                cin >> newStudent.marks;
                addStudent(newStudent);
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto mainstudent;
        }
        int t3=again();
                if(t3==1)
                    return 1;
    }

    int workFaculty(){
        mainfaculty:
        int choicefacu;
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      MANAGING FACULTY DETAILS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout << "1. Add Faculty Member\n";
        cout << "2. Update Faculty Information\n";
        cout << "3. Delete Faculty Member\n";
        cout << "4. Search Faculty Member\n";
        cout << "5. Go Back \n";
        cout << ("******************************************************************************\n");
        cout << "ENTER YOUR CHOICE : \n";
        cin>>choicefacu;
        if(choicefacu==5){
                system("CLS");
            return 1;
        }
        else if(choicefacu==4){
            string facultyName;
                cout << "\nEnter name of the faculty member to search: ";
                getline(cin>>ws,facultyName);
                searchFaculty(facultyName);
        }
        else if(choicefacu==3){
            string facultyName;
                cout << "\nEnter name of the faculty member to delete: ";
                getline(cin>>ws,facultyName);
                deleteFaculty(facultyName);
        }
        else if(choicefacu==2){
           string facultyName;
                cout << "\nEnter name of the faculty member to update: ";
                getline(cin>>ws,facultyName);

                Faculty updatedFaculty;
                updatedFaculty.name=facultyName;
                cout << "Enter updated designation: ";
                getline(cin>>ws,updatedFaculty.designation);
                cout << "Enter updated department: ";
                getline(cin>>ws,updatedFaculty.department);
                cout << "Enter updated contact information: ";
                getline(cin>>ws,updatedFaculty.contactInfo);
                updateFaculty(facultyName, updatedFaculty);
        }
        else if(choicefacu==1){
            Faculty newFaculty;
                cout << "\nEnter faculty name: ";
                getline(cin>>ws,newFaculty.name);
                cout << "Enter designation: ";
                getline(cin>>ws,newFaculty.designation);
                cout << "Enter department: ";
                getline(cin>>ws,newFaculty.department);
                cout << "Enter contact information: ";
                getline(cin>>ws,newFaculty.contactInfo);
                addFaculty(newFaculty);
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto mainfaculty;
        }
        int t3=again();
                if(t3==1)
                    return 1;
    }

    int workcourse(){
        maincourse:
        int choicecourse;
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      MANAGING COURSE DETAILS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout << "1. Add Course\n";
        cout << "2. Assign Subject to Course\n";
        cout << "3. Display Course Information\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Calculate attendance percentage \n";
        cout << "6. Go Back \n";
        cout << ("******************************************************************************\n");
        cout << "ENTER YOUR CHOICE : \n";
        cin>>choicecourse;
        if(choicecourse==6){
                system("CLS");
            return 1;
        }
        else if(choicecourse==5){
            // Calculate Attendance Percentage
                string courseName, subjectName;
                cout << "Enter course name: ";
                getline(cin>>ws,courseName);
                cout << "Enter subject name: ";
                getline(cin>>ws,subjectName);
                double attendancePercentage =calculateAttendancePercentage(courseName, subjectName);
                cout << "Attendance Percentage: " << attendancePercentage << "%\n";
        }
        else if(choicecourse==4){
            // Mark Attendance
                string courseName, subjectName;
                int rollNumber;
                cout << "Enter course name: ";
                getline(cin>>ws,courseName);
                cout << "Enter subject name: ";
                getline(cin>>ws,subjectName);
                cout << "Enter roll number of the student: ";
                cin >> rollNumber;
                markAttendance(courseName, subjectName, rollNumber);
        }
        else if(choicecourse==3){
            // Display Course Information
                string courseName;
                cout << "\nEnter course name: ";
                getline(cin>>ws,courseName);
                displayCourseInfo(courseName);
        }
        else if(choicecourse==2){
           // Assign Subject to Course
                string courseName, subjectName;
                cout << "\nEnter course name: ";
                getline(cin>>ws,courseName);
                cout << "Enter subject name: ";
                getline(cin>>ws,subjectName);
                assignSubject(courseName, subjectName);
        }
        else if(choicecourse==1){
            string courseName;
                cout << "\nEnter course name: ";
                getline(cin>>ws,courseName);
                addCourse(courseName);
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto maincourse;
        }
        int t3=again();
                if(t3==1)
                    return 1;
    }

    int workexam(){
        mainexam:
        int choiceexam;
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                      MANAGING EXAM DETAILS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout << "1. Generate Question Paper\n";
        cout << "2. Record Exam Result\n";
        cout << "3. Compute Grades\n";
        cout << "4. Go Back \n";
        cout << ("******************************************************************************\n");
        cout << "ENTER YOUR CHOICE : \n";
        cin>>choiceexam;
        if(choiceexam==4){
                system("CLS");
            return 1;
        }
        else if(choiceexam==3){
            // Compute Grades
                computeGrades();
        }
        else if(choiceexam==2){
           // Record Exam Result
                int rollNumber, marksObtained;
                cout << "Enter roll number of the student: ";
                cin >> rollNumber;
                cout << "Enter marks obtained: ";
                cin >> marksObtained;
                recordExamResult(rollNumber, marksObtained);
        }
        else if(choiceexam==1){
            // Generate Question Paper
                generateQuestionPaper();
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto mainexam;
        }
        int t3=again();
                if(t3==1)
                    return 1;
    }
};

int main() {
  int seccount=3;
  SECURITY:
  string a,b;
  cout<<"***************************************************************************************************"<<endl;
  cout<<"                            SCHOOL MANAGEMENT SYSTEM"<<endl;
  cout<<"***************************************************************************************************"<<endl<<endl;
  if(seccount<3){
    cout<<endl<<"**********************ERROR IN LOGIN DETAILS************************"<<endl<<endl;
  }
  cout<<"\nYou have "<<seccount<<" tries left \n\n";
  cout<<"Enter username : ";
  cin>>a;
  cout<<endl<<"Enter password : ";
  cin>>b;
  if(a==id && b==pass){
    system("CLS");
  }
  else{
    if(seccount==1){
        cout<<endl<<"**********************YOU ARE AN INTRUDER.GOODBYE !!!!!!!!!!************************"<<endl<<endl;
        exit(0);
    }
    else{
        system("CLS");
        seccount--;
        goto SECURITY;
    }
  }
  int choice1,choice2,Temp,t;
  intro i;
  school u;
  MAINMENU:         //main menu label
      i.mainintro();
      cin>>choice1;
      system("cls");
      if(choice1==4)              //choice for exiting
        i.main_exit();
      else if(choice1==3){
        i.credits();
        goto MAINMENU;
      }
      else if(choice1==2){
        i.about();
        goto MAINMENU;
      }
      else if(choice1==1){
        SUBMENU:
            i.exploremain();
            cin>>choice2;
            system("cls");
            if(choice2==6){                              //exiting the sub menu
                goto MAINMENU;
            }
            else if(choice2==1){
                Temp=u.workStudent();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==2){
                Temp=u.workFaculty();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==3){
                Temp=u.workcourse();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==4){
                Temp=u.workexam();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==5){
                Temp=u.worklib();
                if(Temp==1)
                    goto SUBMENU;
            }
            else{
                cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
                goto SUBMENU;
            }
      }
      else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto MAINMENU;
        }

    return 0;
}
