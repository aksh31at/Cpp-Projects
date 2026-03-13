#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Bill{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill():Item(""), Rate(0), Quantity(0){ }

    void setItem(string item){
        Item=item;
    }

    void setRate(int rate){
        Rate=rate;
    }

    void setQuantity(int quantity){
        Quantity=quantity;
    }

    string getItem(){
        return Item;
    }

    int getRate(){
        return Rate;
    }

    int getQuantity(){
        return Quantity;
    }
};

void PrintBill(){
    system("cls");

    int count=0;
    bool close=0;

    while(!close){

        int choice;
        cout<<"\t1.Add Bill"<<endl;
        cout<<"\t2.Close Session"<<endl;
        cout<<"\tEnter Choice: ";
        cin>>choice;

        system("cls");

        if(choice==1){

            string item;
            int quant;

            cout<<"\tEnter Item: ";
            cin>>item;

            cout<<"\tEnter Quantity: ";
            cin>>quant;

            ifstream in("C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Bill.txt");
            ofstream out("C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Billtemp.txt");

            string line;
            bool found=0;

            while(getline(in,line)){

                stringstream ss;
                ss<<line;

                string itemName;
                int itemRate;
                int itemQuant;
                char delimiter;

                ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;

                if(item==itemName){

                    found=true;

                    // FIXED CONDITION
                    if(quant <= itemQuant){

                        int amount=itemRate*quant;

                        // FIXED HEADER
                        cout<<"\tItem | Rate | Quantity | Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;

                        int newQuant=itemQuant-quant;
                        itemQuant=newQuant;

                        count+=amount;

                        // FIXED FILE WRITE (rate was missing before)
                        out<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl;

                    }
                    else{
                        cout<<"\tSorry, "<<item<<" is not available"<<endl;
                        out<<line<<endl;
                    }
                }

                else{
                    out<<line<<endl;
                }
            }

            if(!found){
                cout<<"\tItem Not Available!"<<endl;
            }

            out.close();
            in.close();

            remove("C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Bill.txt");

            rename(
            "C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Billtemp.txt",
            "C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Bill.txt"
            );
        }

        else if(choice==2){

            close=true;
            cout<<"\tCounting Total Bill"<<endl;
        }

        Sleep(3000);
    }

    system("cls");

    cout<<endl<<endl;
    cout<<"\tTotal Bill ------------------ : "<<count<<endl<<endl;
    cout<<"\tThanks for Shopping!"<<endl;
}

void addItem(Bill b){

    bool close=0;

    while(!close){

        int choice;

        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Close"<<endl;
        cout<<"\tEnter Choice: ";
        cin>>choice;

        if(choice==1){

            system("cls");

            string item;
            int rate, quantity;

            cout<<"\tEnter Item Name: ";
            cin>>item;

            b.setItem(item);

            cout<<"\tEnter Rate: ";
            cin>>rate;

            b.setRate(rate);

            cout<<"\tEnter Quantity: ";
            cin>>quantity;

            b.setQuantity(quantity);

            ofstream out("C:/Users/as625/OneDrive/Desktop/C++Projects/Supermarket/Bill.txt", ios::app);

            if(!out){
                cout<<"\tError: Can't Open File"<<endl;
            }

            else{

                out<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl;
            }

            out.close();

            cout<<"Item added successfully"<<endl;

            Sleep(3000);
        }

        else if(choice==2){

            system("cls");

            close=1;

            cout<<"\tBack to Main Menu"<<endl;

            Sleep(3000);
        }
    }
}

int main(){

    Bill b;

    bool exit=0;

    while(!exit){

        system("cls");

        int val;

        cout<<"\tWelcome To Super Market Billing System"<<endl;
        cout<<"\t**************************************"<<endl;

        cout<<"\t\t1.Add Item"<<endl;
        cout<<"\t\t2.Print Bill"<<endl;
        cout<<"\t\t3.Exit"<<endl;

        cout<<"\t\tEnter Choice: ";
        cin>>val;

        if(val==1){

            system("cls");

            addItem(b);
        }

        else if(val==2){

            PrintBill();
        }

        else if(val==3){

            system("cls");

            exit=1;

            cout<<"\tGood Luck!"<<endl;

            Sleep(3000);
        }
    }
}