#include "stack.h"

void push (Stack &s ,char x){
    s.info[s.top+1]=x;
    s.top=s.top+1;
}
char pop (Stack &s){
    char tmp;
    tmp = s.info[s.top];
    s.top = s.top-1;
    return tmp;
}

void createstack (Stack &s) {
    s.top = 0;
}

bool arrIsEmpty(char arr[10]){
    bool x=true;
    int i=0;
    while (x&&(i<=10)) {
        if (arr[i]!= NULL) {
            x=false;
        }
    }
    return x;
}
