#include<../include/car.h>
#include<iostream>
using namespace std;
void mainadmin(list *ls, car c){
    int choice;
    while (true){
        cout << "\n╔══════════════════════════════════════════════╗\n";
        cout << "║                Car Managerment               ║\n";
        cout << "╠══════════════════════════════════════════════╣\n";
        cout << "║ 1. Add new Car                               ║\n";
        cout << "║ 2. Delete Cars                               ║\n";
        cout << "║ 3. Modify Car's info                         ║\n";
        cout << "║ 4. Search Cars                               ║\n";
        cout << "║ 5. Display                                   ║\n";
        cout << "║ 6. About us                                  ║\n";
        cout << "║ 7. Logout                                    ║\n";
        cout << "╚══════════════════════════════════════════════╝\n";
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Add Car."<<endl;
            break;
        
        case 2:
            cout<<"Delete Car."<<endl;
            break;
        case 3:
            cout<<"Modify Car's info."<<endl;
            break;
        default:
            break;
        }
    }
}