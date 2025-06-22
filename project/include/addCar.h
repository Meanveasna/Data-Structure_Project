#include "car.h"
#include <iostream>
using namespace std;

void addBegin(list *ls, const car& data )
{
    Element *e=new Element;
    e->data=data;
    e->next=ls->head;
    e->prev=nullptr;
    if(ls->n==0){
        ls->tail=e;
    }else{
        ls->head->prev=e;
    }
    ls->head=e;
    ls->n++;
}

void addEnd (list *ls, const car& data){
    Element *e=new Element;
    e->data=data;
    e->next=nullptr;
    e->prev=ls->tail;
    if(ls->n==0){
        ls->head=e;
    }else{
        ls->tail->next=e;
    }
    ls->tail=e;
    ls->n++;
}

