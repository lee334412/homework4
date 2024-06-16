#include <iostream>
#include <string>
using namespace std;

// Definition of the UniversityStaff class
class UniversityStaff {
public:
    UniversityStaff() : name("") {}
    UniversityStaff(string theName) : name(theName) {}
    UniversityStaff(const UniversityStaff& theObject) : name(theObject.name) {}
    string getName() const { return name; }
    UniversityStaff& operator=(const UniversityStaff& rtSide) {
        if (this != &rtSide) {
            name = rtSide.name;
        }
        return *this;
    }
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
        inStream >> staffObject.name;
        return inStream;
    }
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
        outStream << staffObject.name;
        return outStream;
    }
private:
    string name;
};

// Definition of the Student class
class Student {
public:
    Student() : universityName(""), registrationNumber(0), proctor() {}
    Student(string uniName, int regNumber, UniversityStaff theProctor)
        : universityName(uniName), registrationNumber(regNumber), proctor(theProctor) {}
    Student(const Student& theStudent)
        : universityName(theStudent.universityName),
        registrationNumber(theStudent.registrationNumber),
        proctor(theStudent.proctor) {}

    string getUniversityName() const { return universityName; }
    int getRegistrationNumber() const { return registrationNumber; }
    UniversityStaff getProctor() const { return proctor; }

    void setUniversityName(string uniName) { universityName = uniName; }
    void setRegistrationNumber(int regNumber) { registrationNumber = regNumber; }
    void setProctor(UniversityStaff theProctor) { proctor = theProctor; }

    Student& operator=(const Student& rtSide) {
        if (this != &rtSide) {
            universityName = rtSide.universityName;
            registrationNumber = rtSide.registrationNumber;
            proctor = rtSide.proctor;
        }
        return *this;
    }
private:
    string universityName;
    int registrationNumber;
    UniversityStaff proctor;
};

// Definition of the ScienceStudent class derived from Student
class ScienceStudent : public Student {
public:
    ScienceStudent() : Student(), discipline(""), courseType("") {}
    ScienceStudent(string uniName, int regNumber, UniversityStaff theProctor, string theDiscipline, string theCourseType)
        : Student(uniName, regNumber, theProctor), discipline(theDiscipline), courseType(theCourseType) {}
    ScienceStudent(const ScienceStudent& theScienceStudent)
        : Student(theScienceStudent), discipline(theScienceStudent.discipline), courseType(theScienceStudent.courseType) {}

    string getDiscipline() const { return discipline; }
    string getCourseType() const { return courseType; }

    void setDiscipline(string theDiscipline) { discipline = theDiscipline; }
    void setCourseType(string theCourseType) { courseType = theCourseType; }

    ScienceStudent& operator=(const ScienceStudent& rtSide) {
        if (this != &rtSide) {
            Student::operator=(rtSide);
            discipline = rtSide.discipline;
            courseType = rtSide.courseType;
        }
        return *this;
    }
private:
    string discipline;
    string courseType;
};

// Driver program to test the classes
int main() {
    // Create UniversityStaff objects
    UniversityStaff staff1("Dr. Smith");
    UniversityStaff staff2("Dr. Johnson");

    // Test Student class
    Student student1("University A", 12345, staff1);
    Student student2(student1); // Test copy constructor
    student2.setUniversityName("University B");
    student2.setRegistrationNumber(67890);
    student2.setProctor(staff2);

    cout << "Student 1:" << endl;
    cout << "University: " << student1.getUniversityName() << endl;
    cout << "Registration Number: " << student1.getRegistrationNumber() << endl;
    cout << "Proctor: " << student1.getProctor().getName() << endl;

    cout << "Student 2:" << endl;
    cout << "University: " << student2.getUniversityName() << endl;
    cout << "Registration Number: " << student2.getRegistrationNumber() << endl;
    cout << "Proctor: " << student2.getProctor().getName() << endl;

    // Test ScienceStudent class
    ScienceStudent sciStudent1("University C", 11223, staff1, "Physics", "Undergraduate");
    ScienceStudent sciStudent2 = sciStudent1; // Test copy constructor
    sciStudent2.setDiscipline("Chemistry");
    sciStudent2.setCourseType("Postgraduate");

    cout << "Science Student 1:" << endl;
    cout << "University: " << sciStudent1.getUniversityName() << endl;
    cout << "Registration Number: " << sciStudent1.getRegistrationNumber() << endl;
    cout << "Proctor: " << sciStudent1.getProctor().getName() << endl;
    cout << "Discipline: " << sciStudent1.getDiscipline() << endl;
    cout << "Course Type: " << sciStudent1.getCourseType() << endl;

    cout << "Science Student 2:" << endl;
    cout << "University: " << sciStudent2.getUniversityName() << endl;
    cout << "Registration Number: " << sciStudent2.getRegistrationNumber() << endl;
    cout << "Proctor: " << sciStudent2.getProctor().getName() << endl;
    cout << "Discipline: " << sciStudent2.getDiscipline() << endl;
    cout << "Course Type: " << sciStudent2.getCourseType() << endl;

    return 0;
}
