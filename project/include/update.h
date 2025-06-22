#include <car.h>
#include <iostream>
using namespace std;
void update(list *ls, int olddata, int newdata){
    Element *e=ls->head;
    int isFound = 0;
    while (e!=nullptr){
        if (e->data.id == olddata){
            e->data.id=newdata;
            isFound = 1;
        }
        e=e->next;
    }
    if(isFound){
            cout<<"Data is updated."<<endl;
        }else{
            cout<<"No data is updated."<<endl;
        }
}