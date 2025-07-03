#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <regex>
using namespace std;

struct Car {
    int Car_id;
    string Brand ;
    string Model ;
    string Color;
    double Price ;
    string Country ;
    int Year;
    string Description; 
    int status;
};
struct Node{
    Car data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
    int n;
};
List *createList (){
    List *ls = new List();
    ls -> head = nullptr;
    ls -> tail = nullptr;
    ls -> n = 0;
    return ls ;
}
void addBegin  (string Brand, string Model , string color, double price, string country, string description, int year, List *ls){
    Node *e = new Node ();
    e -> data.Brand = Brand;
    e -> data.Model = Model;
    e -> data.Color = color;
    e -> data.Price = price;    
    e -> data.Car_id = ls -> n;
    e -> data.Country = country;
    e -> data.Description = description;
    e -> data.Year = year;
    e -> prev = nullptr;
    e -> next = ls -> head;
    if (ls -> n ==  0) ls -> tail = e;
    else ls -> head -> prev = e;
   
    ls -> head = e;
    ls -> n++;
   
}
void addEnd  (string Brand, string Model , string color, double price, string country, string description, int year, List *ls){
    Node *e = new Node ();
    e -> data.Brand = Brand;
    e -> data.Model = Model;
    e -> data.Color = color;
    e -> data.Price = price;    
    e -> data.Car_id = ls -> n;
    e -> data.Country = country;
    e -> data.Description = description;
    e -> data.Year = year;
    e -> next = nullptr;
    e -> prev = ls -> tail;
    if (ls -> n == 0) ls -> head = e;
    else ls -> tail -> next = e;
    ls -> tail = e;
    ls -> n++;

}
void SaveData (List *ls) {
    if (ls ->n == 0) return ;
    ofstream outputFile("CarInfo.csv");
    Node *e = ls -> head;
    while (e != nullptr){
        outputFile << e -> data.Car_id  << "," << e -> data.Brand<< "," << e -> data.Model << ","<<e ->data.Color<< "," << e -> data.Price<<","<<e ->data.Country<< ","<< e -> data.Description << ","<< e -> data.Year << endl;
        e = e -> next;
    }
    outputFile.close ();
}

void deleteBeg(List *ls) {
    Node *e = ls -> head;
    if (ls -> n == 0) return;
    ls -> head = e -> next;
    if (ls -> head != nullptr){
        ls -> head -> prev = nullptr;
    }else {
        ls -> tail = nullptr;
    }
    delete e;
    ls -> n--;
}
void deleteEnd(List *ls) {
    Node *e = ls -> tail;
    if (ls -> n == 0) return ;
    ls -> tail = e -> prev;
    if (ls -> tail != nullptr){
        ls -> tail -> next = nullptr;
    }
    else {
        ls -> head = nullptr;
    }
    delete e;
    ls -> n--;
}
void deletPos (List *ls, int pos){
    Node *current = ls -> head;
    if (pos < 0 || pos > ls -> n -1 ) return ;
    if (pos == 0) {
        deleteBeg (ls); 
        return ;}
    if (pos == ls -> n -1 ){ 
        deleteEnd(ls); 
        return ;
    }
    for (int i = 0; i < pos - 1 ; i ++){
        current = current -> next;
    }
    Node *temp = current -> next;
    current -> next = temp -> next;
    if (temp -> next != nullptr){
        temp -> next -> prev = current;
    }
    delete temp;
    ls -> n --;
  
}
void deleteAll(List *ls) {
    Node* current = ls->head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    ls->head = nullptr;
    ls->n = 0;
}
bool Checkupdate(List *ls, int id) {
    Node *e = ls->head;
    
    while (e != nullptr) {
        if (e->data.Car_id == id) {
            // e->data.Brand = Brand;
            // e->data.Model = Model;
            // e->data.Color = color;
            // e->data.Price = price;
            // e->data.Country = country;
            // e->data.Description = description;
            // e->data.Year = year;
            return true; 
        }
        e = e->next;
    }
    cout << "Invalid ID: " << id << endl;
    return false;
}
void update(List *ls, int id,string Brand, string Model, string Color, double Price, string Country, string Description, int Year){
    Node *e = ls -> head;
    bool isfound = false;
    while (e != nullptr){
        if (e->data.Car_id == id){
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
        e = e-> next;
    }
    if (isfound){
        cout << "Update complete" << endl;
    }
    else {
        cout << "Invalid ID !! not found.";
    }
}

void Display(List *ls) {
    Node *e = ls->head;

    cout << left
         << setw(8)  << "ID"
         << setw(12) << "Brand"
         << setw(12) << "Model"
         << setw(10) << "Color"
         << setw(12) << "Country"
         << setw(6) << "year"
         << setw(10) << "Price"
         << setw(20)  << "Description" << endl;

    cout << string(90, '-') << endl;  

    while (e != nullptr) {
        cout << left
             << setw(8)  << e->data.Car_id
             << setw(12) << e->data.Brand
             << setw(12) << e->data.Model
             << setw(10) << e->data.Color
             << setw(12) << e->data.Country
             << setw(6) << e->data.Year
             << setw(10) << fixed << setprecision(2) << e->data.Price
             << setw(20)  << e->data.Description << endl;
        e = e->next;
    }
}

void searchCar ( List *ls, string name){
    Node *e = ls -> head;
    regex car_name(name+"[a-zA-Z]+");
    cout << left
         << setw(8)  << "ID"
         << setw(12) << "Brand"
         << setw(12) << "Model"
         << setw(10) << "Color"
         << setw(12) << "Country"
         << setw(6) << "year"
         << setw(10) << "Price"
         << setw(20)  << "Description" << endl;

    while (e!= nullptr){
        if (e->data.Brand == name){
            cout << left
             << setw(8)  << e->data.Car_id
             << setw(12) << e->data.Brand
             << setw(12) << e->data.Model
             << setw(10) << e->data.Color
             << setw(12) << e->data.Country
             << setw(6) << e->data.Year
             << setw(10) << fixed << setprecision(2) << e->data.Price
             << setw(20)  << e->data.Description << endl;
        }
        else if(regex_match(e->data.Brand.begin(), e->data.Brand.end(), car_name)){
            cout << left
             << setw(8)  << e->data.Car_id
             << setw(12) << e->data.Brand
             << setw(12) << e->data.Model
             << setw(10) << e->data.Color
             << setw(12) << e->data.Country
             << setw(6) << e->data.Year
             << setw(10) << fixed << setprecision(2) << e->data.Price
             << setw(20)  << e->data.Description << endl;
        }
        e = e -> next;
    }
}

void RetrieveData(List *ls) {
   
    ifstream inputFile("CarInfo.csv");

    if (!inputFile.is_open()) {
        cerr << "Cannot open file." << endl;
        return ;
    }

    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cerr << "File is empty." << endl;
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
      

        addEnd(Brand, Model, Color, Price, Country, Description, Year, ls);
    }

    inputFile.close();
}
// void heart(){
//      int i, j;
//     int size = 6;
//     cout << "I love you babe ><" << endl;
//     // Upper part of the heart
//     for (i = size / 2; i <= size; i += 2) {
//         for (j = 1; j < size - i; j += 2)
//             cout << " ";
//         for (j = 1; j <= i; j++)
//             cout << "*";
//         for (j = 1; j <= size - i; j++)
//             cout << " ";
//         for (j = 1; j <= i; j++)
//             cout << "*";
//         cout << endl;
//     }

//     // Lower part of the heart
//     for (i = size; i >= 1; i--) {
//         for (j = 0; j < size - i; j++)
//             cout << " ";
//         if (i == 3) {
//             // Center line with text
//             cout << "*****";
//         } else {
//             for (j = 1; j <= (i * 2) - 1; j++)
//                 cout << "*";
//         }
//         cout << endl;
//     }

// }
