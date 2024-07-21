#include<iostream>
using namespace std;
#define PINC(p) p=p->next

class Node {
    public : 
        int data;
        Node *next;
};
class CircularLL {
    private :
        Node *head;
    public :
        CircularLL(){ head->next = head;}
        CircularLL(int A[], int n);
        ~CircularLL();
        void Display();
        int Length();
        void Insert( int index ,int key );
        int Delete(int index);
};
CircularLL :: CircularLL(int A[], int n) {
    head = new Node;
    Node *p = head;
    head->data = A[0];
    int i =0;
    while(--n){
        Node *t = new Node;
        t->data = A[++i];
        p->next = t;
        p = t;
    }
    p->next = head;
}
CircularLL :: ~CircularLL(){
    Node *p = head->next;
    Node *t;
    t= p;
    while(p!=head){
        PINC(p);
        delete t;
        t = p;
    }
    delete t;
}
void CircularLL :: Display () {
    Node *p = head;
    do {
        cout << p->data << " ";
        PINC(p);
    }while(p!= head);
    cout << endl;
}
int CircularLL :: Length() {
    Node *p = head;
    int count = 0;
    do{
        count++;
        PINC(p);
    }while(p!=head);
    return count;
}
void CircularLL :: Insert(int index , int key){
    if(index <0 || index > Length()) {
        int newInd = index%Length();
        if(newInd == 0) newInd= Length();
    }
    
        Node *p = head ;
        Node *t = new Node;
        t->data = key;
        if(index == 0){
            t->next = head;
            head = t;
            int i = Length();
            while(--i){
                PINC(p);
            }
            p->next = head;
        }
        else {
            int i = index;
            while(--i){
                PINC(p);
            }
            t->next = p->next;
            p->next = t;
        }
}
int CircularLL :: Delete( int index){
    if(index<0|| index >> Length()) {
        int index = index%Length();
        if(index ==0) index = Length();
    }
    
    Node *p = head;
    int j = Length();
    if(index == 1 ){
        while(--j){
            PINC(p);
        }
        j = head->data;
        head = head->next;
        delete p->next;
        p->next = head;

    }
    else{
        Node *t = head;
        while(--index){
            t = p;
            PINC(p);
        }
        t->next = p->next;
        j = p->data;
        delete p;
    }

    return j;
}


int main() {
    int A[] = {2,3,1,5,4};
    CircularLL c(A,5);
    c.Display();
    cout << c.Length() << endl;
    c.Insert(9,6);
    c.Display();
    c.Delete(3);
    c.Display();

    return 0;
    
}