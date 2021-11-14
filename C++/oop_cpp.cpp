#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    Employee(string name, int salary, int sp)
    {
        this->name = name;
        this->salary = salary;
        this->secretPassword = sp;
    }

    void printDetails()
    {
        cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << endl;
    }

    void getSecretPass()
    {
        cout << "The secret password of employee " << this->name << " is " << this->secretPassword << endl;
    }

private:
    int secretPassword;
};


class Programmer : public Employee
{
    public:
        int errors;
};

int main()
{

    Employee rohit("Rohit using constructor", 100, 4537);
    // rohit.name ="Rohit";
    // rohit.salary = 100;
    rohit.printDetails();
    // cout<<rohit.secretPassword<<endl;
    rohit.getSecretPass();

    // Programmer rohit2("Rohit");
    // rohit2.printDetails();
    // rohit2.getSecretPass();

    return 0;
}
