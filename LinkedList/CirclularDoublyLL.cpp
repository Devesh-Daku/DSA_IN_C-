#include<iostream>
using namespace std;

#define DEF 0
#define PINC(p) p=p->next
#define PDEC(p) p=p->prev
#define JOIN last->next = first; first->prev = last

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
class CDLinkedList {
    private: 
        Node *first;
        Node *last;
    public:
        CDLinkedList() { 
            first = new Node ; 
            first->next = first;
            first->prev = first;
            last = first;
        }
        CDLinkedList(int A[],int n);
        ~CDLinkedList();
        void Stat(){cout << "First :" << this->first->data << " ,Last :"<< this->last->data << endl; }
        void Display();
        int Length();
        void Insert(int index ,int key);
        int Delete(int index);
        void Reverse();
        int Element(int index);
};
CDLinkedList :: CDLinkedList ( int A[] , int n) {
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
    JOIN;
}
CDLinkedList :: ~CDLinkedList(){
    Node *p = first;
    last->next = NULL;
    while(first){
        PINC(first);
        delete p ;
        p = first;
    }
}
void CDLinkedList :: Display() {
    do{
        cout << first->data << " ";
        PINC(first);
    }while(first != last->next);
    cout<<endl;
}
int CDLinkedList :: Length(){
    int count = 0;
    do{
        count++;
        PINC(first);
    }while(first != last->next);
    return count;
}
void CDLinkedList :: Insert(int index ,int key){
    if(index <0 || index > Length()) {
        index = index%Length();
        if(!index) index = Length();
    }

    Node *t = new Node;
    t->data = key;
    if( index == 0) {    
        t->next = first;
        first->prev = t;
        first = t;
    }
    else if( index == Length()){
        last->next = t;
        t->prev = last;
        last = t;
    }
    else{
        while(--index){
            PINC(first);
        }
        
        t->next = first->next;
        first->next = t;
        t->prev = first;
        t->next->prev = t;
        first = last->next;
        
    }
    JOIN;
}
int CDLinkedList :: Delete(int index){
    if(index <0 || index > Length()) {
        index = index%Length();
        if(!index) index = Length();
    }
    if(index==0){
        index = first->data;
        PINC(first);
        delete last->next;
    }
    else if(index==Length()){
        index = last->data;
        PDEC(last);
        delete first->prev;
    }else{
        while(--index){
            PINC(first);
        }
        Node *temp = first->next;
        temp->next->prev = first;
        first->next = temp->next;
        index = temp->data;
        delete temp;
        first = last->next;
    }
    JOIN;
    return index;
}
int CDLinkedList :: Element(int index){
    if(index<0||index>Length()){
        index %= Length();
        if(!index) index = Length();
    }

    while(index--){
        PINC(first);
    }
    index =  first->data;
    first = last->next;
    JOIN;
    return index;
}


int main() {
    int A[] = { 2,5,4,2,3};
    CDLinkedList cd(A,5);
    cout<< cd.Length() <<endl;
    cd.Display();
    cout<<cd.Element(2)<<endl;
    cd.Insert(cd.Length()-4,11);
    cd.Display();
    cd.Delete(0);
    cd.Display();
    return 0;
}