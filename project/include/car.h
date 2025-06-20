#include <iostream>
using namespace std;

struct car{
    int id;
    string brand;
    string modul;
    string color;
    string price;
    string country;
    int year;
    string description;
    string status;
};
struct Element{
    car data;
    Element *next;
    Element *prev;
};

struct list{
    int n;
    Element *head;
    Element *tail;
};
list *CreateEmptyList(){
    list *ls =new list;
    ls->n=0;
    ls->head=ls->tail=nullptr;
    return ls;
}
