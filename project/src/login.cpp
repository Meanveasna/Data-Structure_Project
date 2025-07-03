#include <iostream>
#include<fstream>
#include<sstream>
// #include "../include/car.h"
#include "../include/admin.h"
#include "../include/user.h"
#include "admin.cpp"

//#include "admin.cpp"
using namespace std;
bool adminlogin(){
    admin a;
    cout<<"Please Enter Usersame: ";
    cin >>  a.name;
    cout<<"Please Enter password: ";
    cin >> a.password;
    if(a.name=="admin" && a.password=="admin123"){
        cout<<"Login successful"<<endl;
        return true;
    }
    cout<<"Login failed."<<endl;
    return false;
}
bool userLogin(){
    string line;
    user u;
    cout << "\nEnter username: ";
    cin.ignore();
    getline(cin, u.name);
    cout << "Enter password: ";
    cin >> u.password;

    ifstream file("../Data/User.csv");
    if(!file){
        cout << "User.csv file not found.\n";
        return false;
    }
    while (getline(file, line)){
        stringstream ss(line);
        string storeduser, storedpass;
        getline(ss, storeduser, ',');
        getline(ss, storedpass, '\n');

        if(storeduser == u.name && storedpass == u.password){
            cout << "Login successful as " << ". \n";
            return true;
        }
    }
    cout << "Login failed. Invalid credentials.\n";
    return false;
}
void registerUser(){
    user u;
    cout << "\nRegister New User\n";
    cout << "Enter username: ";
    cin.ignore();
    getline(cin, u.name);
    cout << "Enter password: ";
    cin >> u.password;

    ofstream file("../Data/User.csv", ios::app); //ios::app is used with ofstream to append mode not overwrite
    file << u.name << "," << u.password << "\n";
    cout << "Registeration successful. You can now login.\n";
}
void login(userlist *uls, adminlist *alist){
    list *carls = CreateEmptyCarList();
    int opt;
    string name,password;
    while(true){
        cout << "╔════════════════════════════════════╗\n";
        cout << "║            Login Menu              ║\n";
        cout << "╠════════════════════════════════════╣\n";
        cout << "║ 1. Login as Admin                  ║\n";
        cout << "║ 2. Login as User                   ║\n";
        cout << "║ 3. Register New User               ║\n";
        cout << "║ 4. Exit                            ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Please select an option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            if (adminlogin()){
                mainadmin(carls);
                return;
            }
            
            break;
        case 2:
            if (userLogin()){
                return;
            }
            break;
        case 3:
            registerUser();
            break;
        case 4:
            return;
        default:
            cout<<"Please try again. "<<endl;
        }
    }
}