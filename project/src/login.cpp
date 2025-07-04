#include <iostream>
#include<fstream>
#include<sstream>
// #include "../include/car.h"
#include "../include/admin.h"
#include "../include/user.h"
#include "admin.cpp"

//#include "admin.cpp"
using namespace std;
bool adminlogin(const string &name,const string &password){
    if(name=="admin" && password=="admin123"){
        cout<<"Login successful"<<endl;
        return true;
    }else{
        cout<<"Login failed."<<endl;
        return false;
    }
    
}
bool userLogin(const  string&name, const string &password){
    string line;
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

        if(storeduser == name && storedpass == password){
            cout << "Login successful." <<endl;
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
    string username,password;
    while(true){
        cout << "╔════════════════════════════════════╗\n";
        cout << "║            Login Menu              ║\n";
        cout << "╠════════════════════════════════════╣\n";
        cout << "║ 1. Login                           ║\n";
        cout << "║ 2. Register                        ║\n";
        cout << "║ 3. Exit                            ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Please select an option: ";
        cin >> opt;
        switch (opt){
        case 1:
            cout<<"Please Enter Usersame: ";
            cin.ignore();
            getline(cin, username);
            cout<<"Please Enter password: ";
            cin >> password;
            if (username == "admin" ) {
                if(password =="admin123"){
                cout << "Login successful as Admin\n";
                mainadmin(carls);
                return;
                }else {
                    cout<<"Login failed."<<endl;
                }
            }else if(userLogin(username, password)){
                cout<<"Login as User"<<endl;
                return;
            }else{
                cout<<"Invalid login."<<endl;
            }
            break;
        case 2:
            registerUser();
            break;
        case 3:
            
            return;
        default:
            cout<<"Please try again. "<<endl;
        }
    }
}