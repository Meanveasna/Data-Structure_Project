#include "../include/car.h"
#include "admin.cpp"
#include <iostream>
using namespace std;

int main(){
    list *ls = CreateEmptyCarList();
    cout<<"\n Welcome to the Student Management System! "<<endl;
    mainadmin(ls);
    return 0;
}
