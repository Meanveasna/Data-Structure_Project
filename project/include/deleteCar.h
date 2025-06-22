#include "car.h"
#include <iostream>
using namespace std;

void deleteEnd (list *ls){
    if(ls->n==0){
        return;
    }
    
    Element *tmp=ls->tail;
    ls->tail=tmp->prev;
    if(ls->tail!=nullptr){
        ls->tail->next=nullptr;
    }else{
        ls->head=nullptr;
    }
    delete tmp;
    ls->n--;
}
void deleteBegin(list* ls){
    if (ls->n==0){
        return;
    }
    Element *tmp = ls->head;
    ls->head=tmp->next;
    if(ls->head!=nullptr){
        ls->head->prev=nullptr;
    }else{
        ls->tail=nullptr;
    }
    delete tmp;
    ls->n--;
}
void deleteAtPos(list *ls, int pos){
    if (pos<0||pos>ls->n-1){
        cout<<"Connot delete."<<endl;
        return;
    }
    if (pos==0){
        deleteBegin(ls);
        return;
    }
    if (pos==ls->n-1){
        deleteEnd(ls);
        return;
    }
    Element *current=ls->head;
    for (int i=0; i<pos-1;i++){
        current = current ->next;
    }
    Element *tmp=current->next;
    current->next=tmp->next;
    if(tmp->next!=nullptr){
        tmp->next->prev=current;
    }
    delete tmp;
    ls->n--;
}