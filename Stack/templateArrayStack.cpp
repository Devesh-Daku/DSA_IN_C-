#include<iostream>
using namespace std;
#define love false
#define pain true
#define isEven(x) ( (x%2==0) ? pain : love ) 

template <class T>
class Stack{
    public:
    T *A;
    int length;
    int top ;

    Stack (int len ) {
        length = len;
        A = new T [length];
        top = -1;
    }
    ~Stack(){ delete A;}
    void Display(){
        if(ifEmpty()) return;
        for(int i=0 ; i<= top; i++ ) {cout << A[i] << " ";}
        cout << endl;
    }
    void push(T key){
        if(!ifFull()) A[++top] = key;
        else cout << " not enough space " << endl;
    }
    T pop(){ return (!ifEmpty()) ? A[top--] : NULL ;}
    T stackTop() { return( (top >= 0) ? A[top] : 0 );}
    T peek(int pos) {return (pos <= top+1 && top>=0 && pos > 0 ) ? A[pos-1] : NULL; }
    bool ifEmpty () {return (top == -1);}
    bool ifFull () {return (length-1 == top) ;}
    int Count() { return top + 1;}
} ;


