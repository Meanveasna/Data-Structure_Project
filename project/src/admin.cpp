#include"../include/car.h"
#include"../include/addCar.h"
#include"../include/deleteCar.h"
#include"../include/modify.h"
#include"../include/display.h"
#include<iostream>
using namespace std;
void addcar(list *ls){
    car c;
    cout<<"Please enter id:  ";
    cin>>c.id;
    cout<<"Please enter brand: ";
    cin>>c.brand;
    cout<<"Please enter model: ";
    cin>>c.model;
    cout<<"Please enter color: ";
    cin>>c.color;
    cout<<"Please enter price: ";
    cin>>c.price;
    cout<<"Please enter contry: ";
    cin>>c.country;
    cout<<"Please enter description: ";
    cin>>c.description;
    cout<<"Please enter status(in stock, Used or not): ";
    cin>>c.status;
    int option;
    cout<<"\nInsert at: \n";
    cout<<"1. Beginning\n";
    cout<<"2. End\n";
    cout<<"Choose option: ";
    cin>>option;
    switch (option){
    case 1:
        addBegin(ls,c);
        cout<<"Car added at beginning."<<endl;
        break;
    case 2:
        addEnd(ls, c);
        cout<<"Car added at End."<<endl;
        break;
    default:
        cout<<"Invalid option. "<<endl;
        break;
    }
}
void deleteCar(list *ls){
    int choice;
    cout<<"\nDelete at: \n";
    cout<<"1. Beginning. "<<endl;
    cout<<"2. End. "<<endl;
    cout<<"3. Position. "<<endl;
    cout<<"Choose option: ";
    cin>>choice;
    switch (choice){
    case 1:
        deleteBegin(ls);
        cout<<"Car have been delete from the begin."<<endl;
        break;
    case 2:
        deleteEnd(ls);
        cout<<"Car have been delete from the End. "<<endl;
        break;
    case 3:
        int pos;
        cout<<"Please enter position you want to delete: ";
        cin>>pos;
        
        deleteAtPos(ls,pos);
        if(pos>ls->n-1){
            cout<<"No Car in this position."<<endl;
        }else{
            cout<<"Car have been delete from "<<pos<<"."<<endl;
        }
        
        break;
    default:
        cout<<"Invalid option."<<endl;
        break;
    }
}
void updatecar(list *ls){
    int id;
    cout<<"Please enter new data ID you want to update: ";
    cin>>id;
    car newdata;
    newdata.id=id;
    cout<<"Please enter new brand: ";
    cin>>newdata.brand;
    cout<<"Please enter new model: ";
    cin>>newdata.model;
    cout<<"Please enter new color: ";
    cin>>newdata.color;
    cout<<"Please enter new price($): ";
    cin>>newdata.price;
    cout<<"Please enter new contry: ";
    cin>>newdata.country;
    cout<<"Please enter new description: ";
    cin>>newdata.description;
    cout<<"Please enter new status(in stock, Used or not): ";
    cin>>newdata.status;
    update(ls,id,newdata);
}

void mainadmin(list *ls){
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
            addcar(ls);
            break;
        
        case 2:
            deleteCar(ls);
            break;
        case 3:
            updatecar(ls);
            break;
        case 5:
            display(ls);
            break;
        default:
            break;
        }
    }
}