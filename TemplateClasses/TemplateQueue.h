
template <class T >
class CQueue {
    private : 
        int size=5;
        int front = 0;
        int rear = 0;
        T *Q;
    public : 
        CQueue(){ this->Q = new T [this->size];}
        CQueue(int size){ this->size = size; Q = new T [this->size]; }
        void Display();
        void enqueue(T);
        T dequeue();
        bool isEmpty(){ return (front==rear);}
};
template<class T>
void CQueue<T> :: Display(){
    int i = front+1;
    do{
        cout << Q[i] << " ";
        i = (i+1)%size;
    }while( i != (rear+1)%size);
    cout << endl;
}
template<class T>
void CQueue<T> :: enqueue(T x) {
    if((rear+1)%size == front ) cout << "Queue is full" << endl;
    else {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}
template<class T>
T CQueue<T> :: dequeue(){
    T x = NULL;
    if(front == rear) cout << "Queue is empty" << endl;
    else {
        front = (front+1)%size;
        x = Q[front];
    } 
    return x;
}
