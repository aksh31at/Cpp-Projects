#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>

using namespace std;

class Hostel{
    private:
    string Name;
    int Rent, Bed;
    public:
    Hostel(string name, int rent, int bed){
        Name=name;
        Rent=rent;
        Bed=bed;
    }

    string getName(){
        return Name;
    }
    int getRent(){
        return Rent;
    }
    int getBed(){
        return Bed;
    }
};


class Student{
    private:
    string Name, RollNo, Address;
    public:
    Student():Name(""),RollNo(""),Address(""){}

    void setName(string name){
        Name=name;
    }
    void setRollNo(string rollNo){
        RollNo=rollNo;
    }
    void setAddress(string address){
        Address=address;
    }
    string getName(){
        return Name;
    }
    string getRollNo(){
        return RollNo;
    }
    string getAddress(){
        return Address;
    }
};



int main(){
    Hostel h("Anantam Hall", 56000, 900);
    Student s;

    bool exit= 0;
    while(!exit){
        system("cls");
        cout<<"\tWelcome To Hostel Accommodation "
    }
}
