#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <regex>
using namespace std;

const char* setColor(const string& color) {
    if (color == "reset") return "\033[0m";
    else if (color == "cyan") return "\033[36m";
    else if (color == "green") return "\033[32m";
    else if (color == "yellow") return "\033[33m";
    else if (color == "red") return "\033[31m";
    else if (color == "purple") return "\033[35m";
    else return "";
}


struct Car {
    int Car_id;
    string Brand, Model, Color, Country, Description;
    double Price;
    int Year;
    int status;
};

struct Node {
    Car data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
    int n;
};

List* createList() {
    List* ls = new List();
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
    return ls;
}

//To take an unique car's ID
int getNextCarID(List* ls) {
    int maxID = -1;
    Node* e = ls->head;
    while (e != nullptr) {
        if (e->data.Car_id > maxID)
            maxID = e->data.Car_id;
        e = e->next;
    }
    return maxID + 1;
}

void addBegin(string Brand, string Model, string color, double price, string country, string description, int year, List* ls) {
    Node* e = new Node();
    e->data.Brand = Brand;
    e->data.Model = Model;
    e->data.Color = color;
    e->data.Price = price;
    e->data.Car_id = getNextCarID(ls);
    e->data.Country = country;
    e->data.Description = description;
    e->data.Year = year;
    e->prev = nullptr;
    e->next = ls->head;
    if (ls->n == 0) ls->tail = e;
    else ls->head->prev = e;
    ls->head = e;
    ls->n++;
}

void addEnd(int id, string Brand, string Model, string color, double price, string country, string description, int year, List* ls) {
    Node* e = new Node();
    e->data.Brand = Brand;
    e->data.Model = Model;
    e->data.Color = color;
    e->data.Price = price;
    e->data.Car_id = id;
    e->data.Country = country;
    e->data.Description = description;
    e->data.Year = year;
    e->next = nullptr;
    e->prev = ls->tail;
    if (ls->n == 0) ls->head = e;
    else ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}

void SaveData(List* ls) {
    if (ls->n == 0) return;
    ofstream outputFile("CarInfo.csv");
    Node* e = ls->head;
    while (e != nullptr) {
        outputFile << e->data.Car_id << "," << e->data.Brand << "," << e->data.Model << "," << e->data.Color << "," << e->data.Price << "," << e->data.Country << "," << e->data.Description << "," << e->data.Year << endl;
        e = e->next;
    }
    outputFile.close();
}

void deleteBeg(List* ls) {
    if (ls->n == 0) return;
    Node* e = ls->head;
    ls->head = e->next;
    if (ls->head != nullptr) {
        ls->head->prev = nullptr;
    }
    else {
        ls->tail = nullptr;
    }
    delete e;
    ls->n--;
}

void deleteEnd(List* ls) {
    if (ls->n == 0) return;
    Node* e = ls->tail;
    ls->tail = e->prev;
    if (ls->tail != nullptr) {
        ls->tail->next = nullptr;
    }
    else {
        ls->head = nullptr;
    }
    delete e;
    ls->n--;
}

// void deletPos(List* ls, int pos) {
//     if (pos < 0 || pos > ls->n - 1) return;
//     if (pos == 0) {
//         deleteBeg(ls);
//         return;
//     }
//     if (pos == ls->n - 1) {
//         deleteEnd(ls);
//         return;
//     }
//     Node* current = ls->head;
//     for (int i = 0; i < pos - 1; i++) {
//         current = current->next;
//     }
//     Node* temp = current->next;
//     current->next = temp->next;
//     if (temp->next != nullptr) {
//         temp->next->prev = current;
//     }
//     delete temp;
//     ls->n--;
// }

void deletPos(List* ls, int pos) {
    Node* e = ls->head;
    while (e != nullptr) {
        if (e->data.Car_id == pos) {
            if (e == ls->head) deleteBeg(ls);
            else if (e == ls->tail) deleteEnd(ls);
            else {
                e->prev->next = e->next;
                e->next->prev = e->prev;
                delete e;
                ls->n--;
            }
            cout << "Car deleted successfully!\n";
            return;
        }
        e = e->next;
    }
    cout << "Car with ID " << pos << " not found.\n";
}

void deleteAll(List* ls) {
    Node* current = ls->head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
}

bool Checkupdate(List* ls, int id) {
    Node* e = ls->head;
    while (e != nullptr) {
        if (e->data.Car_id == id) {
            return true;
        }
        e = e->next;
    }
    cout << setColor("red") << "No car found with this ID." << setColor("reset") << endl;
    return false;
}
void update(List* ls, int id, string Brand, string Model, string Color, double Price, string Country, string Description, int Year) {
    Node* e = ls->head;
    bool isfound = false;
    while (e != nullptr) {
        if (e->data.Car_id == id) {
            e->data.Brand = Brand;
            e->data.Model = Model;
            e->data.Color = Color;
            e->data.Price = Price;
            e->data.Country = Country;
            e->data.Description = Description;
            e->data.Year = Year;
            isfound = true;
            break;
        }
        e = e->next;
    }
    if (isfound) {
        cout << "Update complete" << endl;
    }
    else {
        cout << "Invalid ID !! Not found." << endl;
    }
}

void Display(List* ls) {
    Node* e = ls->head;
    cout << left
         << setw(8) << "ID"
         << setw(15) << "Brand"
         << setw(15) << "Model"
         << setw(15) << "Color"
         << setw(15) << "Country"
         << setw(7) << "Year"
         << " " 
         << setw(15) << "Price($)"
         << setw(20) << "Description" << endl;
    cout << string(120, '-') << endl;
    while (e != nullptr) {
        cout << left
             << setw(8) << e->data.Car_id
             << setw(15) << e->data.Brand
             << setw(15) << e->data.Model
             << setw(15) << e->data.Color
             << setw(15) << e->data.Country
             << setw(7) << e->data.Year
             << " " 
             << setw(15) << fixed << setprecision(2) << e->data.Price
             << setw(20) << e->data.Description << endl;
        e = e->next;
    }
}

void searchCar(List* ls, string name) {
    Node* e = ls->head;
    regex car_name(name, regex_constants::icase);
    cout << left
         << setw(8) << "ID"
         << setw(15) << "Brand"
         << setw(15) << "Model"
         << setw(15) << "Color"
         << setw(12) << "Country"
         << setw(5) << "Year"
         << setw(15) << "Price($)"
         << setw(20) << "Description" << endl;
    cout << string(90, '-') << endl;
    bool found = false;
    while (e != nullptr) {
        if (e->data.Brand == name || regex_search(e->data.Brand, car_name)) {
            cout << left
                 << setw(8) << e->data.Car_id
                 << setw(15) << e->data.Brand
                 << setw(15) << e->data.Model
                 << setw(15) << e->data.Color
                 << setw(15) << e->data.Country
                 << setw(7) << e->data.Year
                 << setw(15) << fixed << setprecision(2) << e->data.Price
                 << setw(20) << e->data.Description << endl;
            found = true;
        }
        e = e->next;
    }
    if (!found) {
        cout << "No car found with brand matching \"" << name << "\"" << endl;
    }
}

void RetrieveData(List* ls) {
    ifstream inputFile("CarInfo.csv");
    if (!inputFile.is_open()) {
        cerr << "Cannot open file." << endl;
        return;
    }
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cerr << "File is empty." << endl;
        inputFile.close();
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string Temp_ID, Brand, Model, Color, Temp_Price, Country, Description, Temp_Year;
        double Price;
        int Year, ID;
        getline(ss, Temp_ID, ',');
        getline(ss, Brand, ',');
        getline(ss, Model, ',');
        getline(ss, Color, ',');
        getline(ss, Temp_Price, ',');
        getline(ss, Country, ',');
        getline(ss, Description, ',');
        getline(ss, Temp_Year, ',');
        
        ID = stoi(Temp_ID);
        Price = stod(Temp_Price);
        Year = stoi(Temp_Year);

        addEnd(ID, Brand, Model, Color, Price, Country, Description, Year, ls);
    }
    inputFile.close();
}

#endif
