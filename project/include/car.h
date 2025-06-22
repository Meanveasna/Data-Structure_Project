#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

struct car{
    int id;
    string brand;
    string model;
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
list* CreateEmptyCarList() {
    list* ls = new list;
    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}
#endif