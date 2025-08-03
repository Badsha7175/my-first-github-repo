#include<iostream>
using namespace std;

class islami_bank;

class sonali_bank{
private:
    string name,acc_no;
    double balance;

public:
    void Sgetdata(){
        cout<<"\ncreate account for Sonali bank:\n";
        getline(cin,name);
        cin>>acc_no>>balance;
        cin.ignore();
    }

    void Sdisplay(){
        cout<<"\nSonali Bank\n"<<"Name: "<<name;
        cout<<"\nAccount: "<<acc_no;
        cout<<"\nBalance: "<<balance;
    }

    friend void balance_transfer(sonali_bank &s, islami_bank &is);
};

class islami_bank{
private:
    string name,acc_no;
    double balance;

public:
    void Isgetdata(){
        cout<<"\n\ncreate account for Islami bank:\n";
        getline(cin,name);
        cin>>acc_no>>balance;
        cin.ignore();
    }

    void Isdisplay(){
        cout<<"\nIslami Bank\n"<<"Name: "<<name;
        cout<<"\nAccount: "<<acc_no;
        cout<<"\nBalance: "<<balance;
    }
    friend void balance_transfer(sonali_bank &s, islami_bank &is);
};


void balance_transfer(sonali_bank &s, islami_bank &is){
    s.balance = s.balance + is.balance*0.1;
    is.balance = is.balance - is.balance*0.1;
}

main(){
    sonali_bank s1;
    s1.Sgetdata();
    //s1.Sdisplay();

    islami_bank is1;
    is1.Isgetdata();
    //is1.Isdisplay();
    cout<<"\ncalling friend function...\n";
    balance_transfer(s1,is1);
    cout<<"After balance transfer\n";
    s1.Sdisplay();
    is1.Isdisplay();

}
