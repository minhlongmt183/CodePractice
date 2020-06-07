#include <iostream>
#include <cstring>
using namespace std;

enum ETypes{officer, productor, nope};

class Employees{
private:
    string  name;
    string  date_of_birth;
    long    salary;
    ETypes  etypes;
public:

    Employees(){}
    ~Employees(){}

    void setName(string name){
        this->name = name;
    }
    void getName(){
        cout << this->name << '\n';
    }

    void setDate(string date){
        this->date_of_birth = date;
    }
    void getDate(){
        cout << this->date_of_birth << '\n';
    }

    void setEtype(ETypes etype){
        this->etypes = etypes;
    }
    ETypes getEtype(){
        if (this->etypes == officer){
            cout << "Nhan vien van phong\n";
        }
        else if (this->etypes == productor){
            cout << "Nhan vien san xuat\n";
        }
        return this->etypes;
    }

    void setSalary(long salary){
        this->salary = salary;
    }
    long getSalary(){
        return this->salary;
    }

};

class Officer : virtual public Employees{
private:
    int num_days = 0;
public:
    Officer(){}
    ~Officer(){}
    void setOfficer(int numdays){
        this->num_days = numdays;
    }

    int getNumdayWorking(){
        return this->num_days;
    }

}; 

class Productor : virtual public Employees{
private:
    int basic_salary = 0;
    int num_product = 0;
public:
    Productor(){}
    ~Productor(){}
    void setProducer(int basic_salary, int num_product){
        this->basic_salary = basic_salary;
        this->num_product = num_product;
    }
    int getBasicSalary(){
        return this->basic_salary;
    }
    int getNumProduct(){
        return this->num_product;
    }
};

class Managers : public Officer, public Productor{
private:
    int Enum = 0; // num of employees
    void *employess;
public:
    Managers(){
        Enum = 0;
        employess = NULL;
    }
    Managers(int Enum){
        this->Enum = Enum;
        (Employees*)employess = new (Employees*)[Enum];
    }
    ~Managers(){
        if (this->employess != NULL)
            delete[] employess;
    }

    void setEnum(int num){
        this->Enum = num;
    }
    int getEnum(){
        return this->Enum;
    }

    void setEmployee(string name, string date_of_birth, ETypes type, int index){
        long salary = 0;

        if (type == officer){

            int num_days = 0;
            do
            {
                cout << "\n -------------------------------------------- \n";
                cout << "Nhan vien van phong: \n";
                cout << "Nhap so ngay lam viec n > 0: \n";
                cin >> num_days;
            }while(num_days < 0);

            salary = num_days*100000;
            ((Officer*)(this->employess + index))->setName(name);
            ((Officer*)(this->employess + index))->setEtype(type);
            ((Officer*)(this->employess + index))->setDate(date_of_birth);
            ((Officer*)(this->employess + index))->setOfficer(num_days);
            ((Officer*)(this->employess + index))->setSalary(salary);
        }
        else if (type == productor){
            int basic_salary = 0;
            int num_product = 0;
            do
            {
                cout << "\n -------------------------------------------- \n";
                cout << "Nhan vien san xuat\n";
                cout << "Nhap luong can ban > 0: \n";
                cin >> basic_salary;
                cout << "Nhap so san pham > 0: \n";
                cin >> num_product;
            } while (basic_salary < 0 || num_product < 0);
            salary = basic_salary + num_product * 5000;
            ((Productor*)(this->employess + index))->setName(name);
            ((Productor*)(this->employess + index))->setEtype(type);
            ((Productor*)(this->employess + index))->setDate(date_of_birth);
            ((Productor*)(this->employess + index))->setProducer(basic_salary, num_product);
            ((Productor*)(this->employess + index))->setSalary(salary);

        }



    }
    void getEmployee(){
        for(int index = 0; index < this->Enum; ++index){
            if (((Employees*)(employess + index))->getEtype() == officer){
                cout << "Name: ";
                ((Officer*)(this->employess + index))->getName();

                cout << "Type: ";
                ((Officer*)(this->employess + index))->getEtype();                

                cout << "So ngay lam viec: " << ((Officer*)(this->employess + index))->getNumdayWorking();

                cout << "Date Of Birth: ";
                ((Officer*)(this->employess + index))->getDate();
                cout << "Salary: " << ((Officer*)(this->employess + index))->getSalary() << '\n';
            }
            else if (((Employees*)(employess + index))->getEtype() == productor){
                cout << "Name: ";
                ((Productor*)(this->employess + index))->getName();

                cout << "Type: ";
                ((Productor*)(this->employess + index))->getEtype();

                cout << "Luong co ban: " << ((Productor*)(this->employess + index))->getBasicSalary();
                cout << "So san pham: " << ((Productor*)(this->employess + index))->getNumProduct();

                cout << "Date Of Birth: ";
                ((Productor*)(this->employess + index))->getDate();
                cout << "Salary: " << ((Productor*)(this->employess + index))->getSalary() << '\n';
            }

        }
    }
};

int main(int argc, char *argv[]){
    int n;
    cout << "Nhap so nhan vien\n";
    cin >> n;

    Managers managers(n);
    int idx = 0;
    string name;
    string date_of_birth;
    ETypes etype;
    while (idx < n){
        cout << "nhan vien thu " << idx << '\n';
        cin.ignore();
        cout << "Nhap ten: \n";
         
        getline(cin, name);
        cout << "Nhap ngay thang nam sinh \n";
        getline(cin, date_of_birth);

        int choice;
        do{
            cout << "\n -------------------------------------------- \n";
            cout << "Loai nhan vien:\n";
            cout << "1. Nhan vien van phong\n";
            cout << "2. Nhan vien san xuat\n";
            cin >> choice;
            if (choice == 1){
                etype = officer;
            }
            else if (choice == 2){
                etype = productor;
            }
            else
                etype = nope;
        }while(etype != officer && etype != productor);
        managers.setEmployee(name,date_of_birth,etype,idx);
        ++idx;
    }
    managers.getEmployee();
    return 0;

}