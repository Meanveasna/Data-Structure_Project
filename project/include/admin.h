#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
struct admin{
    string name;
    string password;
};
struct adminElement {
    admin data;
    adminElement *next;
    adminElement *prev;
};
struct adminlist{
    int n;
    adminElement *head;
    adminElement *tail;
};
adminlist *createemptyadminlist(){
    adminlist *ls=new adminlist;
    ls->n=0;
    ls->head=ls->tail=nullptr;
    return ls;
}
#endif