#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#include <iostream>
using namespace std;

struct Stack{
    char info[99];
    int top;
};

void PDA(Stack &s);
void createstack (Stack &s);
char pop (Stack &s);
void push (Stack &s ,char x);
bool arrIsEmpty(char arr[10]);

#endif // STACK_H_INCLUDED
