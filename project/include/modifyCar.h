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
            cout<<"Car data is updated."<<endl;
        }else{
            cout<<"No data is updated."<<endl;
        }
}