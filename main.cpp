#include <iostream>
#include <ostream>
#include <fstream>
#include "LinkList.h"
using namespace std;
void displayMenu() {

   cout << R"(
 ▗▄▄▖ ▗▄▖ ▗▄▄▖     ▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖ ◂▗▄▖  ▗▄▄▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖     ▗▄▄▖▗▖  ▗▖▗▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖ ▗▖
▐▌   ▐▌ ▐▌▐▌ ▐▌    ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌▐▌   ▐▌   ▐▛▚▞▜▌▐▌   ▐▛▚▖▐▌  █      ▐▌    ▝▚▞▘▐▌     █  ▐▌   ▐▛▚▞▜▌
▐▌   ▐▛▀▜▌▐▛▀▚▖    ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌▐▛▀▜▌▐▌▝▜▌▐▛▀▀▘▐▌  ▐▌▐▛▀▀▘▐▌ ▝▜▌  █       ▝▀▚▖  ▐▌  ▝▀⚚▖  █  ▐▛▀▀▘▐▌  ▐▌
▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌    ▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▐▌ ▐▌▝▚▄▞▘▐▙▄▄▖▐▌  ▐▌▐▙▄▄▖▐▌  ▐▌  █      ▗▄▄▞▘  ▐▌ ▗▄▄▞▘  █  ▐▙▄▄▖▐▌  ▐▌
    )" <<endl;
   cout << R"(
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                           Car Management System                                         │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│                                                                                                         │
│   [1] Add New Car                                                         [4] Modify Car Information    │
│   [2] Delete Car                                                          [5] Search for a Car          │
│   [3] Display Car                                                         [6] about us                  │
│                                           [7] Exit                                                      │
│                                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────┘
)" << endl;
    cout << "Please enter your choice: ";
}
int main () {
    // heart();
    int choice;
    string Brand ;
    string Model ;
    string Color;
    double Price ;
    string Country ;
    int Year;
    string Description; 
    List *ls = createList();
    string Car_name;
    RetrieveData(ls);
    do {
        displayMenu();
        cin >> choice ;
        switch (choice) {
            case 1:
                system("clear");
                bool input_ok;
                cout << " Add Car " << endl;
                cout << "Please input Brand : " ; cin >> Brand;
                cout << "Please input Model : " ; cin >> Model;
                cout << "PLease input color : " ; cin >> Color;
                cout << "Please input Price : " ; cin >> Price ;
                cout << "Please input year : " ; cin >> Year;
                cout << "Please input country : "; cin >> Country;
                cout << "Add description : "; cin >> Description;
                // Brand = "toyota";
                // Model = "supra";
                // Price = 1000000;
                // Color = "Black";
                // Country ="Japan";
                // Year = 2000;
                // Description = "Used condition";
                addEnd(Brand, Model, Color, Price, Country, Description, Year, ls);
                SaveData(ls);
                break;
            case 2:
                system("clear");
                int ID_del;
                cout <<" Delete Car via ID" << endl;
                cout << " Please input ID to delete "; cin >> ID_del;
                deletPos (ls, ID_del);
                SaveData(ls);
                break;
            case 3:
                deleteAll(ls);
                RetrieveData(ls);
                system("clear");
                cout << " Display Car " << endl;
                Display(ls);
                break;
            case 4:
                system("clear");
                int id;
                cout << "Modify Car Information " << endl;
                cout << "Please input Car's ID "; cin >> id;
                cout << "Please input Brand : " ; cin >> Brand;
                cout << "Please input Model : " ; cin >> Model;
                cout << "PLease input color : " ; cin >> Color;
                cout << "Please input Price : " ; cin >> Price ;
                cout << "Please input year : " ; cin >> Year;
                cout << "Please input country : "; cin >> Country;
                cout << "Add description : "; cin >> Description;
                update(ls,id,Brand, Model, Color, Price, Country, Description, Year);
                SaveData(ls);
                break;
            case 5:
                system("clear");
                cout << " Search for a car " << endl;
                cout << "Please input Car's name : "; cin >> Car_name;
                searchCar(ls, Car_name);
                break;
            case 6:
                system("clear");
                cout << "  ABout us " << endl;
                cout << R"(
                1. Meas Ratanakviphou
                2. Dim Ponhakvontey
                3. Thoun Meanveasna
                )";
                break;
            case 7:
                system("clear");
                cout << " Bye BYe babe" << endl;
                break;
            default:
                cout << " Invalid Input " << endl;
        }
    }while (choice != 7);
    SaveData(ls);
    return 0;
}