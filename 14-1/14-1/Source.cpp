#include <iostream>
#include <string>
using namespace std;

class SalariedEmployee {
public:
    SalariedEmployee() : name(""), ssn(""), netPay(0), salary(0) {}
    SalariedEmployee(string theName, string theSSN, double theWeeklySalary)
        : name(theName), ssn(theSSN), netPay(0), salary(theWeeklySalary) {}
    string getName() const { return name; }
    string getSSN() const { return ssn; }
    double getNetPay() const { return netPay; }
    double getSalary() const { return salary; }
    void setName(string newName) { name = newName; }
    void setSSN(string newSSN) { ssn = newSSN; }
    void setNetPay(double newNetPay) { netPay = newNetPay; }
    void setSalary(double newSalary) { salary = newSalary; }
    virtual void printCheck() const {
        cout << "Pay to the order of " << name << endl;
        cout << "The sum of " << netPay << " Dollars" << endl;
        cout << "Check Stub: NOT NEGOTIABLE" << endl;
        cout << "Employee Number: " << ssn << endl;
        cout << "Salaried Employee. Regular Pay: " << salary << endl;
    }
protected:
    string name;
    string ssn;
    double netPay;
    double salary;
};

class Administrator : public SalariedEmployee {
public:
    Administrator() : SalariedEmployee(), title(""), responsibility(""), supervisor(""), annualSalary(0) {}
    Administrator(string theName, string theSSN, double theAnnualSalary,
        string theTitle, string theResponsibility, string theSupervisor)
        : SalariedEmployee(theName, theSSN, theAnnualSalary / 52), // Assume weekly salary for base class
        title(theTitle), responsibility(theResponsibility), supervisor(theSupervisor), annualSalary(theAnnualSalary) {}

    void setSupervisor(string newSupervisor) { supervisor = newSupervisor; }
    void readData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter SSN: ";
        getline(cin, ssn);
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter responsibility: ";
        getline(cin, responsibility);
        cout << "Enter supervisor: ";
        getline(cin, supervisor);
        cout << "Enter annual salary: ";
        cin >> annualSalary;
        salary = annualSalary / 52; // Convert annual to weekly salary
        cin.ignore(); // Ignore the remaining newline character
    }
    void print() const {
        cout << "Administrator Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "SSN: " << ssn << endl;
        cout << "Title: " << title << endl;
        cout << "Responsibility: " << responsibility << endl;
        cout << "Supervisor: " << supervisor << endl;
        cout << "Annual Salary: " << annualSalary << endl;
        cout << "Weekly Salary: " << salary << endl;
    }
    void printCheck() const override {
        cout << "Pay to the order of " << name << endl;
        cout << "The sum of " << netPay << " Dollars" << endl;
        cout << "Check Stub: NOT NEGOTIABLE" << endl;
        cout << "Employee Number: " << ssn << endl;
        cout << "Administrator. Title: " << title << endl;
        cout << "Responsibility: " << responsibility << endl;
        cout << "Supervisor: " << supervisor << endl;
        cout << "Annual Salary: " << annualSalary << endl;
        cout << "Weekly Salary: " << salary << endl;
    }
protected:
    string title;
    string responsibility;
    string supervisor;
    double annualSalary;
};

int main() {
    Administrator admin;
    admin.readData();
    admin.print();
    admin.setNetPay(admin.getSalary()); // For simplicity, netPay is set to weekly salary
    admin.printCheck();
    return 0;
}
