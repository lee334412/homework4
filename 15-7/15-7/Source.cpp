#include <iostream>
#include <string>
using namespace std;

// ���~����u���O
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

    // �L�䲼��k
    virtual void printCheck() const {
        cout << "��I�� " << name << endl;
        cout << "�`���B " << netPay << " ����" << endl;
        cout << "�䲼�s�ڡG���i����" << endl;
        cout << "���u�s���G " << ssn << endl;
        cout << "�~����u�C���`�u��G " << salary << endl;
    }

protected:
    string name;       // �m�W
    string ssn;        // ���|�w�����X
    double netPay;     // ��o�~��
    double salary;     // �u��
};

// �޲z�����O�A�~�Ӧ��~����u���O
class Administrator : public SalariedEmployee {
public:
    Administrator() : SalariedEmployee(), title(""), responsibility(""), supervisor(""), annualSalary(0) {}
    Administrator(string theName, string theSSN, double theAnnualSalary,
        string theTitle, string theResponsibility, string theSupervisor)
        : SalariedEmployee(theName, theSSN, theAnnualSalary / 52), // ���]�������u��O���P�p��
        title(theTitle), responsibility(theResponsibility), supervisor(theSupervisor), annualSalary(theAnnualSalary) {}

    // �]�w�W��
    void setSupervisor(string newSupervisor) { supervisor = newSupervisor; }

    // �q��LŪ���ƾ�
    void readData() {
        cout << "��J�m�W: ";
        getline(cin, name);
        cout << "��J���|�w�����X: ";
        getline(cin, ssn);
        cout << "��J¾��: ";
        getline(cin, title);
        cout << "��J�d���d��: ";
        getline(cin, responsibility);
        cout << "��J�W��: ";
        getline(cin, supervisor);
        cout << "��J�~�~: ";
        cin >> annualSalary;
        salary = annualSalary / 52; // �N�~�~�ഫ���P�~
        cin.ignore(); // �����Ѿl�������
    }

    // �L�X�H��
    void print() const {
        cout << "�޲z���H��:" << endl;
        cout << "�m�W: " << name << endl;
        cout << "���|�w�����X: " << ssn << endl;
        cout << "¾��: " << title << endl;
        cout << "�d���d��: " << responsibility << endl;
        cout << "�W��: " << supervisor << endl;
        cout << "�~�~: " << annualSalary << endl;
        cout << "�P�~: " << salary << endl;
    }

    // ���g�L�䲼��k
    void printCheck() const override {
        cout << "��I�� " << name << endl;
        cout << "�`���B " << netPay << " ����" << endl;
        cout << "�䲼�s�ڡG���i����" << endl;
        cout << "���u�s���G " << ssn << endl;
        cout << "�޲z���C¾��G " << title << endl;
        cout << "�d���d��G " << responsibility << endl;
        cout << "�W�šG " << supervisor << endl;
        cout << "�~�~�G " << annualSalary << endl;
        cout << "�P�~�G " << salary << endl;
    }

protected:
    string title;           // ¾��
    string responsibility;  // �d���d��
    string supervisor;      // �W��
    double annualSalary;    // �~�~
};

// �D���
int main() {
    Administrator admin;
    admin.readData();
    admin.print();
    admin.setNetPay(admin.getSalary()); // ��²��_���A�N��o�~��]�m���P�~
    admin.printCheck();
    return 0;
}
