#ifndef Stack_H
#define Stack_H
#include <iostream>
#include <conio.h>

using namespace std;

struct Element
{
    char data;
    Element *next;
};

struct Stack
{

    int n;
    Element *top;
};

Stack *createStack()
{
    Stack *s = new Stack;
    s->n = 0;
    s->top = nullptr;
    return s;
}

void push(Stack *s, char data)
{
    Element *e = new Element;
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->n++;
}

char pop(Stack *s)
{
    if (s->n == 0)
        return '\0';
    Element *e = s->top;
    s->top = e->next;
    int value = e->data;
    s->n--;
    delete e;
    return value;
}

void display(Stack *s)
{
    Element *e = s->top;
    while (e != nullptr)
    {
        cout << e->data << " ";
        e = e->next;
    }
}

string stackToString(Stack *s)
{
    Element *e = s->top;
    string result = "";
    while (e != nullptr)
    {
        result = e->data + result;
        e = e->next;
    }
    return result;
}

string getPassword()
{

    string password;
    char ch;
    Stack *s = createStack();
    cout << "Enter password: ";
    while ((ch = getch()) != '\r')
    {
        if (ch == '\b')
        {
            pop(s);

            cout << "\b \b";
        }
        else
        {
            push(s, ch);

            cout << "*";
        }
    }

    password = stackToString(s);
    return password;
}


#endif 