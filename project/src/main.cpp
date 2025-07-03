#include "login.cpp"
#include <iostream>
using namespace std;


int main(){
    adminlist *als=createemptyadminlist();
    userlist *uls=createemptyuserlist();
    cout<<"\n Welcome to the Student Management System! "<<endl;
    //mainadmin(ls);
    login(uls,als);
    return 0;
}

