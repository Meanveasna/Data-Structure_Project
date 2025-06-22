#include "car.h"
#include <iostream>
using namespace std;
void update(list *ls, int id, const car &newdata){
    Element *e=ls->head;
    bool isFound = false;
   
    while (e!=nullptr){
        if (e->data.id == id){
            e->data=newdata;
            isFound = true;
            break;
        }
        e=e->next;
    }
    if(isFound){
        cout<<"Car with this ID "<<id<<" is already updated."<<endl;
    }else{
        cout<<"No Car found with ID "<<id<<". Update cancelled"<<endl;
    }
}