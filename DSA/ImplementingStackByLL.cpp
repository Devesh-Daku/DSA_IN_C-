#include<iostream>
using namespace std;
#include"./TemplateSinglyLL.h"

template<class T>
class Stack : private SinglyLL<T> {
    public :
        Stack();
        ~Stack();

        void Push(T);
        T Pop();
        T Peek(int i);
} ;

template<class T> 
Stack<T> :: Stack(){
}
template<class T>
void Stack<T> :: Push(T x){
    InsertFirst(x);
}
template<class T>
T Stack<T> :: Pop(){
    return DeleteFirst();
}
template<class T> 
T Stack<T> :: Peek(int x){
    
}
