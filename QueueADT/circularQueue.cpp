#include<iostream>
using namespace std;

class CQueue {
    private : 
        int size=5;
        int front = 0;
        int rear = 0;
        int *Q;
    public : 
        CQueue(){ this->Q = new int [this->size];}
        CQueue(int size){ this->size = size; Q = new int [this->size]; }
        
        void Display();
        void enqueue(int x);
        int dequeue();

        
};
void CQueue :: Display(){
    int i = front+1;
    do{
        cout << Q[i] << " ";
        i = (i+1)%size;
    }while( i != (rear+1)%size);
    cout << endl;
}
void CQueue :: enqueue(int x) {
    if((rear+1)%size == front ) cout << "Queue is full" << endl;
    else {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}
int CQueue :: dequeue(){
    int x = -1;
    if(front == rear) cout << "Queue is empty" << endl;
    else {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}


// int main(){
//     CQueue cq(10);
//     cq.enqueue(5);
//     cq.enqueue(7);
//     cq.enqueue(8);
//     cq.enqueue(2);
//     cq.enqueue(10);
//     cq.enqueue(0);
//     cq.enqueue(1);
//     cq.enqueue(4);
//     cq.enqueue(15);
//     cq.enqueue(16);
//     cq.Display();
//     cq.dequeue();
//     cq.dequeue();
//     cq.enqueue(16);
//     cq.enqueue(17);
//     cq.Display();
//     return 0;
// }
