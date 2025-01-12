#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

struct Student {
    string roll_no;
    string name;
    string age;
    string branch_name;
    string course;
    string admission_year;
    string mobile_no;
    string email_id;
    string cgpa; 
};

vector<Student> students;

void getStudentData(Student &student) {
    while (true) {
        cout << "Enter Roll no: ";
        cin.ignore(); // Clear the newline character
        getline(cin, student.roll_no);
        
        // Check if the input is numeric
        bool isNumeric = !student.roll_no.empty() && all_of(student.roll_no.begin(), student.roll_no.end(), ::isdigit);
        if (isNumeric) {
            break; // Valid input, exit the loop
        } else {
            cout << "Invalid input. Roll no must be a number. Please try again.\n";
        }
    }
    cout << "Enter Name: ";
    getline(cin, student.name);
    while (true) {
        cout << "Enter Age: ";
        getline(cin, student.age);
        
        // Check if the input is numeric
        bool isNumeric = !student.age.empty() && all_of(student.age.begin(), student.age.end(), ::isdigit);
        if (isNumeric) {
            int age = stoi(student.age);

            // Check if the age is within a valid range
            if (age >= 8 && age <= 120) {
                break; // Valid input, exit the loop
            } else {
                cout << "Invalid input. Age must be between 8 and 120. Please try again.\n";
            }
        } else {
            cout << "Invalid input. Age must be a number. Please try again.\n";
        }
    }
    cout << "Enter Branch: ";
    getline(cin, student.branch_name);
    cout << "Enter Course: ";
    getline(cin, student.course);
    while (true) {
        cout << "Enter Admission Year: ";
        getline(cin, student.admission_year);
        
        // Check if the input is numeric
        bool isNumeric = !student.admission_year.empty() && all_of(student.admission_year.begin(), student.admission_year.end(), ::isdigit);
        if (isNumeric) {
            int admissionYear = stoi(student.admission_year);

            // Get the current year
            time_t t = time(0); // Get current time
            tm* now = localtime(&t); // Convert to local time
            int currentYear = now->tm_year + 1900;
    
            // Check if the year is valid
            if (admissionYear > 1900 && admissionYear <= currentYear) {
                break; // Valid input, exit the loop
            } else {
                cout << "Invalid input. Admission year must be between 1900 and " << currentYear << ". Please try again.\n";
            }
        } else {
            cout << "Invalid input. Admission year must be a number. Please try again.\n";
        }
    }
    while (true) {
        cout << "Enter Mobile no: ";
        getline(cin, student.mobile_no);
        
        // Check if the input is numeric
        bool isNumeric = !student.mobile_no.empty() && all_of(student.mobile_no.begin(), student.mobile_no.end(), ::isdigit);
        bool isTenDigit = !student.mobile_no.empty() && student.mobile_no.size() == 10;
        if (isNumeric && isTenDigit) {
            break; // Valid input, exit the loop
        } else {
            cout << "Invalid input. Mobile number must be a ten digit number. Please try again.\n";
        }
    }
    while (true) {
        cout << "Enter Email Id: ";
        cin >> student.email_id;

        // Check if email contains @gmail.com
        if (student.email_id.find("@gmail.com") != string::npos) {
            break; // Valid email, exit the loop
        } else {
            cout << "Invalid input. Email must contain @gmail.com. Please try again.\n";
        }
    }
   while (true) {
        cout << "Enter CGPA: ";
        cin.ignore(); // Clear the newline character
        getline(cin, student.cgpa);
        
        // Check if the input is numeric
        bool isNumeric = !student.cgpa.empty() && all_of(student.cgpa.begin(), student.cgpa.end(), ::isdigit);
        if (isNumeric) {
            break; // Valid input, exit the loop
        } else {
            cout << "Invalid input. CGPA must be a number. Please try again.\n";
        }
    }
}

void enter() {
    int ch;
    cout << "How many students do you want to enter? ";
    cin >> ch;

    if (ch < 0) {
        cout << "Invalid number!" << endl;
        return;
    }

    for (int i = 0; i < ch; i++) {
        cout << "\nEntering data for student " << (students.size() + 1) << endl;
        Student student;
        getStudentData(student);
        students.push_back(student);
    }
}

void show() {
    if (students.empty()) {
        cout << "No Data is Entered" << endl;
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        cout << "\nData of Student " << (i + 1) << endl;
        cout << "Roll NO: " << students[i].roll_no << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Branch: " << students[i].branch_name << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Admission Year: " << students[i].admission_year << endl;
        cout << "Mobile NO: " << students[i].mobile_no << endl;
        cout << "Email Id: " << students[i].email_id << endl;
        cout<<"CGPA: "<< students[i].cgpa<<endl;
    }
}

void search() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student: ";
    cin >> rollno;

    for (const auto& student : students) {
        if (rollno == student.roll_no) {
            cout << "Roll NO: " << student.roll_no << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Branch: " << student.branch_name << endl;
            cout << "Course: " << student.course << endl;
            cout << "Admission Year: " << student.admission_year << endl;
            cout << "Mobile NO: " << student.mobile_no << endl;
            cout << "Email Id: " << student.email_id << endl;
            cout <<"CGPA: " << student.cgpa <<endl;
            return; // Found the student
        }
    }
    cout << "No student found with Roll NO: " << rollno << endl;
}

void update() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student which you want to update: ";
    cin >> rollno;

    for (auto& student : students) {
        if (rollno == student.roll_no) {
            cout << "\nUpdating data for Roll NO: " << student.roll_no << endl;
            getStudentData(student);
            return; // Updated the student
        }
    }
    cout << "No student found with Roll NO: " << rollno << endl;
}

void deleteAll() {
    students.clear();
    cout << "All records deleted!" << endl;
}

int main() { 
      cout<<"student Database managment system ";
    int choice;
    while (true) {
        cout << "\n1. Enter data\n2. Show data\n3. Search data\n4. Update data\n5. Delete all data\n6. Quit\n";
        cin >> choice;

        switch (choice) {
            case 1: enter(); break;
            case 2: show(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteAll(); break;
            case 6: return 0; // exit the program
            default: cout << "Invalid input" << endl; break;
        }
    }
};