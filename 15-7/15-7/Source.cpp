#include <iostream>
#include <string>
using namespace std;

// 基本薪資員工類別
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

    // 印支票方法
    virtual void printCheck() const {
        cout << "支付給 " << name << endl;
        cout << "總金額 " << netPay << " 美元" << endl;
        cout << "支票存根：不可轉讓" << endl;
        cout << "員工編號： " << ssn << endl;
        cout << "薪資員工。正常工資： " << salary << endl;
    }

protected:
    string name;       // 姓名
    string ssn;        // 社會安全號碼
    double netPay;     // 實發薪資
    double salary;     // 工資
};

// 管理員類別，繼承自薪資員工類別
class Administrator : public SalariedEmployee {
public:
    Administrator() : SalariedEmployee(), title(""), responsibility(""), supervisor(""), annualSalary(0) {}
    Administrator(string theName, string theSSN, double theAnnualSalary,
        string theTitle, string theResponsibility, string theSupervisor)
        : SalariedEmployee(theName, theSSN, theAnnualSalary / 52), // 假設基類的工資是按周計算
        title(theTitle), responsibility(theResponsibility), supervisor(theSupervisor), annualSalary(theAnnualSalary) {}

    // 設定上級
    void setSupervisor(string newSupervisor) { supervisor = newSupervisor; }

    // 從鍵盤讀取數據
    void readData() {
        cout << "輸入姓名: ";
        getline(cin, name);
        cout << "輸入社會安全號碼: ";
        getline(cin, ssn);
        cout << "輸入職位: ";
        getline(cin, title);
        cout << "輸入責任範圍: ";
        getline(cin, responsibility);
        cout << "輸入上級: ";
        getline(cin, supervisor);
        cout << "輸入年薪: ";
        cin >> annualSalary;
        salary = annualSalary / 52; // 將年薪轉換為周薪
        cin.ignore(); // 忽略剩餘的換行符
    }

    // 印出信息
    void print() const {
        cout << "管理員信息:" << endl;
        cout << "姓名: " << name << endl;
        cout << "社會安全號碼: " << ssn << endl;
        cout << "職位: " << title << endl;
        cout << "責任範圍: " << responsibility << endl;
        cout << "上級: " << supervisor << endl;
        cout << "年薪: " << annualSalary << endl;
        cout << "周薪: " << salary << endl;
    }

    // 重寫印支票方法
    void printCheck() const override {
        cout << "支付給 " << name << endl;
        cout << "總金額 " << netPay << " 美元" << endl;
        cout << "支票存根：不可轉讓" << endl;
        cout << "員工編號： " << ssn << endl;
        cout << "管理員。職位： " << title << endl;
        cout << "責任範圍： " << responsibility << endl;
        cout << "上級： " << supervisor << endl;
        cout << "年薪： " << annualSalary << endl;
        cout << "周薪： " << salary << endl;
    }

protected:
    string title;           // 職位
    string responsibility;  // 責任範圍
    string supervisor;      // 上級
    double annualSalary;    // 年薪
};

// 主函數
int main() {
    Administrator admin;
    admin.readData();
    admin.print();
    admin.setNetPay(admin.getSalary()); // 為簡單起見，將實發薪資設置為周薪
    admin.printCheck();
    return 0;
}
