#include<iostream>
using namespace std;
#define love false
#define pain true
#define isEven(x) ( (x%2==0) ? pain : love ) 
#define PINC(p) p=p->next;

class Node {
    public :
    int data;
    Node *next;
    Node(int x=0) {
        data = x;
        next = NULL;
    }
};
class Stack{
    private :
        Node *top;
        int size;
    public : 
        Stack(){
            cout << " construction begins " << endl;
            size = 0;
            top = NULL;
        }
        ~Stack(){

            Node *n = top;
            while(size--){
                PINC(top);
                delete n;
                n = top;
            }
            cout << endl << "destructor ends " << endl;
        };
        void Display();
        int pop ();
        void push(int );
        bool ifEmpty();
        bool ifFull();
        Node* peek(int pos );
};


void Stack :: Display(){
    Node *n = top;
    
    while(n){
        cout << n->data << " ";
        PINC(n);
    }
    cout << " :Displaying current stack ";
    cout << endl;
}
Node* Stack :: peek(int pos){
    Node *n = top;
    if(pos > size) return NULL;
    while(--pos){
        PINC(n);
    }
    return n;
}
int Stack :: pop(){
    if(!ifEmpty()) {
        Node *n = top ;
        PINC(top );
        int i = n->data;
        size--;
        cout << i << " :pop out from stack" <<endl;
        delete n;
        return i;
    }
    else return -1;

}
void Stack :: push(int x) {
    Node *n = new Node;
    if( n == NULL ) {
        cout << "Stack overflow "<< endl;
        return ;
    }
    n->data = x;
    n->next = top;
    top = n;
    size++;
    cout << x << " :pushed in stack "<< endl;
}
bool Stack :: ifEmpty(){
    return (top)?love:pain;
}
bool Stack :: ifFull() {
    Node *t = new Node;
    return (t==NULL)?pain : love;
}

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(11);
    s.push(7);
    s.Display();
    s.pop();
    s.Display();
    cout << s.peek(2)->data << endl;

    return 0;
    
}
