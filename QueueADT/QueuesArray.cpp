#include<iostream>
using namespace std;

class Queue {
    private :
        int front = -1;
        int rear = -1 ;
        int size = 10;
        int *Q;
    public :
        Queue () {Q = new int[size];}
        Queue (int size) { this->size = size; Q = new int [this->size];} 
        void enqueue( int x);
        int dequeue();
        void Display();
};

void Queue :: enqueue ( int x ){
    if(rear == size-1) cout << " Queue is full " << endl;
    else {rear++ ; Q[rear] = x;}
}
int Queue :: dequeue () {
    int x = -1;
    if(front==rear) cout << " queue is empty " << endl;
    else {
         x  = Q[front+1];
        front++;
    }
    return x;
}
void Queue :: Display() {
    for(int i=0 ; i< front+1; i++ ) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(13);

    q.Display();

    return 0;
}