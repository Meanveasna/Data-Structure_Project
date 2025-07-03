#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
struct user{
    string name;
    string password;
};
struct userElement {
    user data;
    userElement *next;
    userElement *prev;
};
struct userlist{
    int n;
    userElement *head;
    userElement *tail;
};
userlist *createemptyuserlist(){
    userlist *ls=new userlist;
    ls->n=0;
    ls->head=nullptr;
    ls->tail=nullptr;
    return ls;
}
void addenduser(userlist *ls, const user& data){
    userElement *e=new userElement;
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
#endif