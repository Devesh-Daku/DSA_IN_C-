#include<iostream>
using namespace std;
#define PINC(p) p=p->next

class Node {
    public :
    int data ;
    Node *next = NULL;
    
    Node (int x = 0) { this->data = x;};
};
class Queue{
    Node *front;
    Node *rear;

    public:
        Queue(){front = new Node ; rear = front;}

        void enqueue (int);
        void Display ();
        int dequeue ();
        bool ifEmpety();
        
};
void Queue :: Display(){
    Node *p = front->next;
    while(p!=NULL){
        cout << p->data << " ";
        PINC(p);
    }
    cout << endl;
}
void Queue :: enqueue(int x){
    Node *t = new Node(x);
    rear->next = t;
    rear = t;
}
int Queue :: dequeue() {
    if(!ifEmpety()){
        Node *t = front;
        PINC(front);
        int x = front->data;
        front->data = 0;
        delete t;
        return x;
    }
    return -1;
}
bool Queue :: ifEmpety(){
   return (front==rear);
}

int main (){
    Queue q;
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(11);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();

    q.Display();
}