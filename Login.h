#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <limits> 
#include <cctype>
#include <conio.h>
#include "LinkList.h"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidMenuChoice(int minOption, int maxOption) {
    int choice;
    while (true) {
        if (cin >> choice && choice >= minOption && choice <= maxOption) {
            clearInput();
            return choice;
        } else {
            cout << setColor("red") << "Invalid input! Please enter a number between " << minOption << " to " << maxOption << ": " << setColor("reset");
            clearInput();
        }
    }
}


// Validate Brand and Description: must have at least one letter, allow digits & spaces
bool isValidBrandDesc(const string& input) {
    if (input.empty()) return false;
    bool hasLetter = false;
    for (char c : input) {
        if (!(isalnum(c) || c == ' ')) return false; 
        if (isalpha(c)) hasLetter = true;           
    }
    return hasLetter;
}

// Validate Model, Color, Country: only letters and spaces allowed, no digits
bool isValidAlphaOnly(const string& input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

string validString(const string& label, bool (*validator)(const string&), bool required = true, int maxLength = 200) {
    string input;
    do{
        setColor("blue");
        cout << "[*] ";
        setColor("reset");
        cout << label << ": ";
        setColor("green");
        getline(cin, input);
        setColor("reset");
        if (!required && input.empty()) return input;
        if (input.empty()) {
            cout << label << " cannot be empty.\n";
        } else if (input.length() > maxLength) {
            cout << label << " too long (max " << maxLength << " characters).\n";
        } else if (!validator(input)) {
            cout << "Invalid." << label <<"\n";
        } else {
            break;
        }
    } while (true);
    return input;
}

//Year validation
int validYear() {
    int Year;
    cout << "Please input Year (1800 - 2025): ";
    setColor("blue");
    cout << "[*] ";
    setColor("reset");
    cout << "Year: ";
    while (!(cin >> Year) || Year < 1800 || Year > 2025) {
        clearInput();
        cout << "Please input the year of car from 1800 to 2025. Please re-enter: ";
    }
    clearInput();
    return Year;
}

//Price validation
double validPrice() {
    double Price;
    setColor("blue");
    cout << "[*] ";
    setColor("reset");
    cout << "Price:$ ";
    while (!(cin >> Price) || Price < 1000.0 || Price > 9999999.99) {
        clearInput();
        cout << "Invalid Price. Please re-enter: $";
    }
    clearInput();
    return Price;
}

string hashPassword(const string& password) {
    return to_string(hash<string>{}(password));
}

bool userLogin(const string& username, const string& password) {
    ifstream file("User.csv");
    string line;
    string hashed = hashPassword(password);
    while (getline(file, line)) {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, ',');
        getline(ss, pass);
        if (user == username && pass == hashed) return true;
    }
    return false;
}

bool isValidUsername(const string& username) {
    if (username.empty() || isdigit(username[0])) return false;

    bool hasLetter = false;
    for (char c : username) {
        if (!(isalnum(c) || c == '_' || c == ' ')) return false;
        if (isalpha(c)) hasLetter = true;
    }
    return hasLetter;
}


bool userExists(const string& username) {
    ifstream file("User.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, ',');
        if (user == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    do {
        cout <<  setColor("cyan") << "Username: " << setColor("reset");
        cin >> username;
        if (!isValidUsername(username)) {
            cout << "Invalid username! Try again.\n";
            continue;
        }
        cout << setColor("cyan") << "Password: " << setColor("reset");
        cin >> password;
        if (userExists(username)) {
            cout << setColor("red") << "Username already exists. Please login." << setColor("reset") <<endl;
            return;
        }
        break;
    }while (true);
    ofstream file("User.csv", ios::app);
    file << username << "," << hashPassword(password) << endl;
    cout << setColor("green") << "Registration successful!" << setColor("reset") << endl;
}
void adminMenu(List* ls){
    int choice;
    string Brand, Model, Color, Country, Description, keyword;
    double Price;
    int Year, id;

    do {
        cout << setColor("purple") << R"(                                                                 
           .---.            ,--,                                ____           
          /. ./|          ,--.'|                              ,'  , `.         
      .--'.  ' ;          |  | :               ,---.       ,-+-,.' _ |         
     /__./ \ : |          :  : '              '   ,'\   ,-+-. ;   , ||         
 .--'.  '   \' .   ,---.  |  ' |      ,---.  /   /   | ,--.'|'   |  || ,---.   
/___/ \ |    ' '  /     \ '  | |     /     \.   ; ,. :|   |  ,', |  |,/     \  
;   \  \;      : /    /  ||  | :    /    / ''   | |: :|   | /  | |--'/    /  | 
 \   ;  `      |.    ' / |'  : |__ .    ' / '   | .; :|   : |  | ,  .    ' / | 
  .   \    .\  ;'   ;   /||  | '.'|'   ; :__|   :    ||   : |  |/   '   ;   /| 
   \   \   ' \ |'   |  / |;  :    ;'   | '.'|\   \  / |   | |`-'    '   |  / | 
    :   '  |--" |   :    ||  ,   / |   :    : `----'  |   ;/        |   :    | 
     \   \ ;     \   \  /  ---`-'   \   \  /          '---'          \   \  /  
      '---"       `----'             `----'                           `----'   
                                                                               
    )" << setColor("reset") << endl;
    cout << R"(
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                           Car Management System                                         │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│                                                                                                         │
│   [1] Add New Car                                                         [4] Modify Car Information    │
│   [2] Delete Car                                                          [5] Search for a Car          │
│   [3] Display Car                                                         [6] About us                  │
│                                           [7] Exit                                                      │
│                                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────┘
)" << endl;
        cout << "Please enter your choice (1-7): ";
        choice = getValidMenuChoice(1, 7);

        switch (choice) {
        case 1:{
            cout << "\n-- Add Car --\n";
            cin.ignore();
            Brand = validString("Brand", isValidBrandDesc);
            Model = validString("Model", isValidBrandDesc);
            Color = validString("Color", isValidAlphaOnly);
            Price = validPrice();
            Year = validYear();
            Country = validString("Country", isValidAlphaOnly);
            Description = validString("Description", isValidBrandDesc, true, 200);

            int id = getNextCarID(ls);
            addEnd(id, Brand, Model, Color, Price, Country, Description, Year, ls);
            SaveData(ls);
            break;
        }
        case 2: {
            cout << "\n-- Delete Car via ID --\n";
            cout << "Please input ID to delete: "; cin >> id;
            if (Checkupdate(ls, id)) {
                deletPos(ls, id);  
                SaveData(ls);
            } else {
                cout << setColor("red") << "No car with ID " << id << " found. Deletion cancelled." << setColor("reset") << endl;
            }
            break;
        }
        case 3: {
            cout << "╭──────────────────────────────────────────────────────────────────────────────────────╮\n";
            cout << "│                      Car Management System — Inventory Overview                      │\n";
            cout << "╰──────────────────────────────────────────────────────────────────────────────────────╯\n";
            Display(ls);
            cout << setColor("yellow") << "\nPress any key to return to the menu...\n" << setColor("reset");
            _getch();
            break;
        }
        case 4:{
            cout << "\n-- Modify Car --\n";
            cout << "Please input Car's ID: "; cin >> id; 
            clearInput();
            if (!Checkupdate(ls, id)) {
                cout << setColor("yellow") << "\nPress any key to return to the menu...\n" << setColor("reset");
                _getch();  
                break;   
            }
            //clearInput();
            Brand = validString("Brand", isValidBrandDesc);
            Model = validString("Model", isValidBrandDesc);
            Color = validString("Color", isValidAlphaOnly);
            Price = validPrice();
            Year = validYear();
            Country = validString("Country", isValidAlphaOnly);
            Description = validString("Description", isValidBrandDesc, true, 200);
            update(ls, id, Brand, Model, Color, Price, Country, Description, Year);
            SaveData(ls);
            break;
        }
        case 5:{
            cout << "\n-- Search for a car --\n";
            cout << "Enter any keywords: "; cin.ignore(); getline(cin, keyword);
            searchCar(ls, keyword);
            cout << setColor("yellow") << "\nPress any key to return to the menu...\n" << setColor("reset");
            _getch();
            break;
        }
        case 6:{
            cout << "\n-- About us --\n";
            cout << R"(
                1. Meas Ratanakviphou
                2. Dim Ponhakvontey
                3. Thoun Meanveasna
                )" << endl;
            break;
        }
        case 7:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (choice != 7);
}
void clientMenu(List* ls) {
    int choice;
    string keyword;
    do {
        cout << setColor("purple") << R"(                                                                 
           .---.            ,--,                                ____           
          /. ./|          ,--.'|                              ,'  , `.         
      .--'.  ' ;          |  | :               ,---.       ,-+-,.' _ |         
     /__./ \ : |          :  : '              '   ,'\   ,-+-. ;   , ||         
 .--'.  '   \' .   ,---.  |  ' |      ,---.  /   /   | ,--.'|'   |  || ,---.   
/___/ \ |    ' '  /     \ '  | |     /     \.   ; ,. :|   |  ,', |  |,/     \  
;   \  \;      : /    /  ||  | :    /    / ''   | |: :|   | /  | |--'/    /  | 
 \   ;  `      |.    ' / |'  : |__ .    ' / '   | .; :|   : |  | ,  .    ' / | 
  .   \    .\  ;'   ;   /||  | '.'|'   ; :__|   :    ||   : |  |/   '   ;   /| 
   \   \   ' \ |'   |  / |;  :    ;'   | '.'|\   \  / |   | |`-'    '   |  / | 
    :   '  |--" |   :    ||  ,   / |   :    : `----'  |   ;/        |   :    | 
     \   \ ;     \   \  /  ---`-'   \   \  /          '---'          \   \  /  
      '---"       `----'             `----'                           `----'   
                                                                               
    )" << setColor("reset") << endl;
cout << "╭──────────────────────────────────────────────────────────╮\n";
cout << "│                 Welcome to Car Management                │\n";
cout << "├──────────────────────────────────────────────────────────┤\n";
cout << "│  1. Display Cars                                         │\n";
cout << "│  2. Search Cars                                          │\n";
cout << "│  3. About Us                                             │\n";
cout << "│  4. Exit                                                 │\n";
cout << "╰──────────────────────────────────────────────────────────╯\n";

cout << setColor("green") << "> " << setColor("reset");
choice = getValidMenuChoice(1, 4);
        switch (choice) {
            case 1:
                cout << "╭──────────────────────────────────────────────────────────────────────────────────────╮\n";
                cout << "│                      Car Management System — Inventory Overview                      │\n";
                cout << "╰──────────────────────────────────────────────────────────────────────────────────────╯\n";

                Display(ls);
                cout << setColor("yellow") << "\nPress any key to return to the menu...\n" << setColor("reset");
                _getch();
                break;
            case 2: 
                cout << "Enter keyword: ";
                cin.ignore();
                getline(cin, keyword);
                searchCar(ls, keyword);
                cout << setColor("yellow") << "\nPress any key to return to the menu...\n" << setColor("reset");
                _getch();
                break;
            case 3:
                cout << "\n-- About us --\n";
                cout << R"(
                    1. Meas Ratanakviphou
                    2. Dim Ponhakvontey
                    3. Thoun Meanveasna
                    )" << endl;
                break;
            case 4:
                cout << setColor("red") << "Logout\n" << setColor("reset");
                break;
            default:
                cout << setColor("red") << "Invalid choice. Please try again.\n" <<setColor("reset");
        }
    } while (choice != 4);
}

void adminLogin(List* ls){
    string username, password;
    cout <<  setColor("cyan") << "Username: " << setColor("reset");
    cin >> username;
    cout << setColor("cyan") << "Password: " << setColor("reset");
    cin >> password;
    if (username == "admin" && hashPassword(password)== "3288171798096025883") {
        adminMenu(ls);
    } else if (userLogin(username, password)) {
        clientMenu(ls);
    } else {
        cout << setColor("red") << "Invalid credentials!\n" << setColor("reset");
    }
}

#endif