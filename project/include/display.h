#include "car.h"
#include <iostream>
using namespace std;
void display(list *ls){
    Element *e=ls->head;
    while (e!=nullptr){
        cout<<e->data.id<<" "<<e->data.brand<<" "<<e->data.model<<" "<<e->data.color<<" "<<e->data.price<<" "<<e->data.country<<" "<<e->data.year<<" "<<e->data.description<<" "<<e->data.status<<endl;
        e=e->next;
    }
    cout<<endl;
}