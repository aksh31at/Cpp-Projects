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

    void reserve(){
        ifstream in("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hostel.txt");
        ofstream out("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hosteltemp.txt");

        string line;

        while(getline(in, line)){
            int pos=line.find("Anantam Hall");
            if(pos!=string::npos){
                int bed=Bed-1;
                Bed=bed;

                stringstream ss;
                ss<<bed;
                string strBed= ss.str();

                int bedPos=line.find_last_of(':');
                line.replace(bedPos+1, string::npos, strBed);
            }
            out<<line<<endl;
        }
        out.close();
        in.close();
        remove("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hostel.txt");
        rename("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hosteltemp.txt","C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hostel.txt");
        cout<<"\tBed Reserved Succesfully";
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
    ofstream out("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/hostel.txt");
    out<<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<endl<<endl;
    cout<<"Hostel Data Saved."<<endl;
    out.close();

    Student s;

    bool exit= 0;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome To Hostel Accommodation System"<<endl;
        cout<<"\t**************************************"<<endl;
        cout<<"\t1.Reserve a Bed"<<endl;
        cout<<"\t2.Exit"<<endl;
        cout<<"\tEnter Choice: "<<endl;
        cin>>val;

        if(val==1){
            system("cls");
            string name, rollno, address;
            cout<<"\tEnter Name of Student: "<<endl;
            cin>>name;
            s.setName(name);
            cout<<"\tEnter Roll Number of Student: "<<endl;
            cin>>rollno;
            s.setRollNo(rollno);
            cout<<"\tEnter Address of Student: "<<endl;
            cin>>address;
            s.setAddress(address);
            if(h.getBed()>0){
                h.reserve();
            }
            else if(h.getBed()==0){
                cout<<"\tSorry! Bed Not Available"<<endl;
            }

            ofstream outFile("C:/Users/as625/OneDrive/Desktop/C++Projects/Hostel Accommodation System/students.txt", ios::app);
            outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
            cout<<"Student Data Saved."<<endl; 
            outFile.close();          

        }
    }
}
