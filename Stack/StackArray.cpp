#include<iostream>
using namespace std;
#define love false
#define pain true
#define isEven(x) ( (x%2==0) ? pain : love ) 


class Stack{
    public:
    int *A;
    int length;
    int top ;


    Stack() { top = -1;}
    Stack (int len ) {
        length = len;
        A = new int [length];
        top = -1;
    }
    ~Stack(){ delete A;}


    void Display();
    void push(int key);
    int pop();
    int stackTop();
    int peek(int index);
    bool ifEmpty ();
    bool ifFull ();
    int Count() { return top + 1;}

} ;
void Stack :: Display () {
    if(ifEmpty()) cout << "Stack is empty "<< endl;
    else {
        for(int i=0 ; i<= top; i++ ) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}
void Stack :: push (int key) {
    if(!ifFull()) A[++top] = key;
    else cout << " not enough space " << endl;
}
int Stack :: pop () {
    return (!ifEmpty()) ? A[top--] : -1 ;
}
int Stack :: stackTop () {
    return (!ifEmpty()) ? A[top] : -1 ;
}
int Stack :: peek (int pos) {
    return (pos <= top+1 && top>=0 && pos > 0 ) ? A[pos-1] : -1; 
}
bool Stack :: ifEmpty () {
    return (top == -1) ? pain : love;
}
bool Stack :: ifFull() {
    return (length-1 == top) ? pain : love;
}

// int main(){
//     Stack st(5);
//     st.Display();
//     st.push(9);
//     st.push(2);
//     st.push(4);
//     st.push(11);
//     st.Display();
//     st.pop();
//     st.Display();
//     cout<< st.stackTop() << endl;
//     cout<< st.peek(1) << endl;

    

// }