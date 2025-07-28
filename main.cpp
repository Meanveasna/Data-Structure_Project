#include <iostream>
#include <string>
#include "LinkList.h"
#include "Login.h"
using namespace std;

void displayLoginMenu() {
    cout << R"(
 ▗▄▄▖ ▗▄▖ ▗▄▄▖     ▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖ ◂▗▄▖  ▗▄▄▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖     ▗▄▄▖▗▖  ▗▖▗▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖ ▗▖
▐▌   ▐▌ ▐▌▐▌ ▐▌    ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌▐▌   ▐▌   ▐▛▚▞▜▌▐▌   ▐▛▚▖▐▌  █      ▐▌    ▝▚▞▘▐▌     █  ▐▌   ▐▛▚▞▜▌
▐▌   ▐▛▀▜▌▐▛▀▚▖    ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌▐▛▀▜▌▐▌▝▜▌▐▛▀▀▘▐▌  ▐▌▐▛▀▀▘▐▌ ▝▜▌  █       ▝▀▚▖  ▐▌  ▝▀⚚▖  █  ▐▛▀▀▘▐▌  ▐▌
▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌    ▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▐▌ ▐▌▝▚▄▞▘▐▙▄▄▖▐▌  ▐▌▐▙▄▄▖▐▌  ▐▌  █      ▗▄▄▞▘  ▐▌ ▗▄▄▞▘  █  ▐▙▄▄▖▐▌  ▐▌
    )" << endl;
    cout << "╔══════════════════════════════════════════════════════════╗\n";
    cout << "║" << setColor("cyan") << "                     Login/Register                   " << setColor("reset") << "    ║\n";
    cout << "╠══════════════════════════════════════════════════════════╣\n";
    cout << "║" << setColor("green") << "                       1. Login                       " << setColor("reset") << "    ║\n";
    cout << "║" << setColor("green") << "                       2. Register                    " << setColor("reset") << "    ║\n";
    cout << "║" << setColor("green") << "                       3. Exit                        " << setColor("reset") << "    ║\n";
    cout << "╚══════════════════════════════════════════════════════════╝\n";
    cout << "Please select an option (1-3) " << setColor("red") << "➤  " <<setColor("reset"); 
}

int main() {
    int choice;
    string username, password;
    string Brand, Model, Color, Country, Description, Car_name;
    double Price;
    int Year, id;
    int opt;

    List* ls = createList();
    RetrieveData(ls);

     do {
        displayLoginMenu();
        opt = getValidMenuChoice(1, 3); 
        switch (opt) {
        case 1:
            cout <<  setColor("cyan") << "Username: " << setColor("reset");
            cin >> username;
            cout << setColor("cyan") << "Password: " << setColor("reset");
            cin >> password;
            if (username == "admin" && password == "admin") {
                adminMenu(ls);
            } else if (userLogin(username, password)) {
                clientMenu(ls);
            } else {
                cout << "Invalid credentials!\n";
            }
            break;
        case 2:
            registerUser();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (opt != 3);

    SaveData(ls);
    deleteAll(ls);
    delete ls;
    return 0;
}
