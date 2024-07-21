#include<iostream>
using namespace std;
#define DEF 0
#define PINC(p) p=p->next
#define PDEC(p) p=p->prev

class Node {
    public : 
        Node *prev;
        int data;
        Node *next; 
        Node() {
            prev = NULL;
            next = NULL;
            data = DEF;
        }
};
class DoublyLL {
    private: 
        Node *first;
        Node *last;
    public:
        DoublyLL() { first = new Node  ; first = NULL; last = first;}
        DoublyLL(int A[],int n) ;
        ~DoublyLL();
        void Stat(){
            cout << "First :" << this->first->data << " ,Last :"<< this->last->data << endl; 
        }
        void Display();
        int Length();
        void Insert(int index , int key);
        int Delete(int index);
        void Reverse();
};
DoublyLL :: DoublyLL ( int A[] , int n) {
    first = new Node;
    first->data = A[0];
    last = first;
    int i=0;
    while(--n){
        Node *t = new Node;
        t->data = A[++i];
        last->next = t;
        t->prev = last;
        last = t;
    }
    if(last->next) last->next = NULL;
    if(first->prev) first->prev = NULL;
}
DoublyLL :: ~DoublyLL(){
    Node *p = first;
    while(p){
        PINC(first);
        delete p ;
        p = first;
    }
}
void DoublyLL :: Display() {
    Node *p = first;
    while ( p ){
        cout << p->data << " ";
        PINC(p);
    }
    cout<<endl;
}
int DoublyLL :: Length(){
    Node *p = first;
    int count = 0;
    while(p){
        count++;
        PINC(p);
    }
    return count;
}
void DoublyLL :: Insert(int index ,int key){
    if(index <0 || index > Length()) return ;
    Node *t = new Node;
    t->data = key;
    if( index == 0) {    
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        Node *p = first;
        while(--index){
            PINC(p);
        }
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}
int DoublyLL :: Delete(int index){
    if(index<0||index>=Length()) return NULL;

        Node *p = first;
    if(index == 0){
        PINC(first);
        index = p->data;
        delete p;
        first->prev = NULL;
    }
    if( index == Length() -1 ){
        p = last ;
        last = last->prev;
        index = p->data;
        delete p;
        last->next = NULL;
    }
    else{
        while(index--){
            PINC(p);
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        index = p->data;
        delete p;
    }
    return index;
}
void DoublyLL :: Reverse(){
    Node *p = first;
    Node *temp = new Node;
    do{
        temp = p->next;
        p->next = p->prev;
        p->prev = temp ;
        PDEC(p);
    }while(p);
    temp = first;
    first = last ;
    last = temp;
}

int main() {
    int A[] = {2,3,1,3,5};
    DoublyLL d(A,5);
    d.Display();
    cout<< d.Length()<<endl;
    d.Insert(1,9);
    d.Display();
    cout<< d.Delete(5)<<endl;
    d.Stat();
    d.Display();
    d.Reverse();
    d.Display();
    d.Stat();
    
    return  0;
}
